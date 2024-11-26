#include "webPage/WebPageQuery.h"


//构造函数，传入redis对象指针
WebPageQuery::WebPageQuery()
{
        _conf = Configuration::getInstance("conf/searchSever.conf");
        map<string, string> confInfo = _conf->getConfigMap();
        _redis=Redis::getInstance(confInfo["redis_host"],confInfo["redis_port"]);
        _splitTool= new CnSplitTool(
                                      confInfo["jieba.dict.utf8"].c_str(),
                                      confInfo["hmm_model.utf8"].c_str(),
                                      confInfo["user.dict.utf8"].c_str(),
                                      confInfo["idf.utf8"].c_str(),
                                      confInfo["stop_words.utf8"].c_str()
                                     );

        _webPageReader= WebPageReader::getInstance(confInfo["IndexPage.dat"].c_str(), confInfo["OffsetPage.dat"].c_str(), confInfo["WebPage.dat"].c_str());

        ifstream ifs(confInfo["stop_words.utf8"].c_str());

    }

//WebPageQuery析构函数
WebPageQuery::~WebPageQuery() {
    delete _splitTool;

}

template <typename T>
void travel(vector<T> vec)
{
    for(auto i:vec)
    {
        cout<<i<<";";
    }
    cout<<endl;
}

//对外提供的查询接口，形参是要查询的字符串
nlohmann::json WebPageQuery::Query(const std::string& word) {
    LogInfo("start");
    //将字符串分词
    std::vector<std::string> words = cut(word);
//    travel(words);

    //获取各个分词的关联docid
    vector<int> docIds = getDocId(words);
  //  travel(docIds);

    LogInfo("order start");
    //利用docids获取doc表项
    std::map<double, RssItem, std::greater<double>> resMap = getRes(docIds, words);
    LogInfo("order end");

    LogInfo("signRed start");
    //将各个表项存入json然后汇总成数组
    vector<nlohmann::json> vecRes;
    //travel(vecRes);
    for (const auto& i : resMap) {
        nlohmann::json newJson = modifyJson(i.second, words);
        vecRes.push_back(newJson);

    }
    LogInfo("signRed end")

    //在最外面套上一层json，加上必要信息
    nlohmann::json res;
    res["item"] = vecRes;
    res["messageId"] = "200";
    
    LogInfo("endl");

    return res;

}


//对外提供的查询接口，形参是要查询的字符串
nlohmann::json WebPageQuery::shortQuery(const std::string& word) {
    LogInfo("start");
    //将字符串分词
    std::vector<std::string> words = cut(word);

    //获取各个分词的关联docid
    vector<int> docIds = getDocId(words);

    LogInfo("order start");
    //利用docids获取doc表项
    std::map<double, RssItem, std::greater<double>> resMap = getRes(docIds, words);
    std::map<double,RssItem,std::greater<double>> tmp;
    // 迭代器遍历前10项
    int count = 0;
    for (auto it = resMap.begin(); it != resMap.end() && count < 10; ++it) {
        // 可以在这里对每个键值对进行处理
        tmp[it->first]=it->second;
        count++;
    }
    LogInfo("order end");

    LogInfo("signRed start");
    //将各个表项存入json然后汇总成数组
    vector<nlohmann::json> vecRes;
    for (const auto& i : tmp) {
        nlohmann::json newJson = modifyJson(i.second, words);
        vecRes.push_back(newJson);

    }
    LogInfo("signRed end")

        //在最外面套上一层json，加上必要信息
        nlohmann::json res;
    res["item"] = vecRes;
    res["messageId"] = "200";

    LogInfo("endl");

    return res;

}

//将rssItem更具关键词修改成json
nlohmann::json WebPageQuery::modifyJson(RssItem rssIems, vector<string> keyWord) {

    //获取rssIems的内容
    string str = getContent(rssIems);

    //找出内容中的关键字的位置索引
    map<string, vector<size_t>> idxs = findKeyword(str, keyWord);

    //根据位置索引对每一项的内容进行切割、标红
    string redStr;
    for (auto idx : idxs) {
        int keyWordLength = idx.first.length();
        for (auto num : idx.second) {
            //对这一项的内容进行切割、标红
            redStr += "..." + signRed(str, num, keyWordLength) + "...\n";

        }

    }

    //对标题进行标红
    string title=rssIems.title;
    title = ChangeColor::colorizeString(title.c_str(),0,title.length(),BLUE_COLOR_STRING);

    //对链接进行标红
    string link=rssIems.link;
    link=ChangeColor::colorizeString(link.c_str(),0,link.length(),GREEN_COLOR_STRING);

    //将结果打包成json
    nlohmann::json newJson;
    newJson["title"] = title;
    newJson["link"] = link;
    newJson["description"] = rssIems.description;
    newJson["content"] = redStr;
    return newJson;

}

//获取rssitem的内容
std::string WebPageQuery::getContent(RssItem rssItem) {
    return rssItem.content;

}

//查找关键字在字符串的索引，形参为字符串和关键字数组
map<string, vector<size_t>> WebPageQuery::findKeyword(const string& str, vector<string> keyWords) {

    //把utf-8的字符串转化成wstring
    wstring wstr = WstringOperation::stringToWstring(str);

    //将关键词的在items内容中的索引数组与关键词组合生成
    map<string, vector<size_t>> idxs;
    for (auto word : keyWords) {
        vector<size_t> tmp = WstringOperation::findAllOccurrences(wstr, word, 0);
        idxs[word] = tmp;

    }
    return idxs;

}

//将字符串裁剪标红
std::string WebPageQuery::signRed(const string& str, size_t idx, int keyWordLength) {
    int iidx = idx;

    //将字符床装成wstring
    std::wstring wstr = WstringOperation::stringToWstring(str);
    size_t startPos;
    int cutLength;
    int newStartPos = 10;

    //确定裁剪的开始位置
    if (iidx - 10 >= 0) {
        startPos = idx - 10;

    } else {
        //iidx为标红的开始位置
        newStartPos = iidx;
        startPos = 0;

    }

    //确定裁剪的长度
    if (startPos + 20 >= str.length()) {
        cutLength = str.length() - startPos - 1;

    } else {
        cutLength = 20;

    }

    //裁剪方法
    std::wstring newWstr = WstringOperation::substrByCharacter(wstr, startPos, cutLength);

    //堆字符串进行标红
    newWstr = ChangeColor::colorizeString(newWstr, newStartPos, keyWordLength / 3, RED_COLOR);

    //将wstring改成string
    std::string newString = WstringOperation::wstringToString(newWstr);

    //去除换行符
    newString = WstringOperation::removeWhitespace(newString);
    return newString;

}


//裁剪方法，形参是需要裁剪的字符串
std::vector<std::string> WebPageQuery::cut(const std::string& word) {
    //把字符串裁剪
    std::vector<std::string> words = _splitTool->cut(word);

    //屏蔽掉停用词
    std::vector<std::string> res =_splitTool->removeStopWords(words);
    return res;

}

//获取拥有关键词的docid，传入切好词的数组
std::vector<int> WebPageQuery::getDocId(const std::vector<std::string>& words) {
    std::vector<int> res;

    //获取每一个关键词的拥有的docid
    for (const auto& word : words) {

        //对关键词进行防冲突处理
        string newWord="网页查询："+word;

        //判断redis有无这个关键词
        string rres = _redis->getRedisData(newWord);

        //如果redis中没有这个关键词从词库中查找
        if (rres == string()) {
            LogInfo("从词库中查询%s",word.c_str());

            //获取倒排索引表
            std::map<std::string, std::multimap<double, int>> invert_index_lib = _webPageReader->getInvertIndexLib();

            //将每一项加入set去重,排序
            std::set<int> tmp;
            for (const auto& item : invert_index_lib[word]) {
                tmp.insert(item.second);

            }

            //将set转成vector适应接口
            vector<int> resTmp(tmp.begin(),tmp.end());
            res=resTmp;

            //将数组转成字符串
            string sdocIds = WstringOperation::vectorToString(res);

            //写入redis
            _redis->setRedisData(newWord, sdocIds);
            _redis->expireRedisData(newWord, 10);

        } 
        //如果redis中存在关键词
        else 
        {
            //将从redis中获取的字符串转成string
            res = WstringOperation::stringToVector(rres);
            LogInfo("从Redis中查询%s",word.c_str());
        }

    }
    return res;

}


//计算关键词与网页的余弦值，形参为网页库的id和关键词组
double WebPageQuery::getCos(int ID, const std::vector<std::string>& keyWords) {

    //获取<网页id,搜索词，权重>的表
    std::map<int, std::vector<std::pair<std::string, double>>> id_word_weight = _webPageReader->getIdWordWeight();

    //获取当前id的搜索词和权重的表
    std::vector<std::pair<std::string, double>> vcp = id_word_weight[ID];
    std::vector<double> pointx;
    std::vector<double> pointy;
    int size = keyWords.size();
    int count = 0;

    //遍历当前id的搜索词和权重的表，将关键词和文章的点标出
    for (const auto& item : vcp) {
        count++;
        if (std::find(keyWords.begin(), keyWords.end(), item.first) != keyWords.end()) {
            double value = 1.0 / size;
            pointy.push_back(value);

        } else {
            pointy.push_back(0);

        }
        pointx.push_back(item.second);

    }
    double XmulY = 0;
    double Xdis2 = 0;
    double Ydis2 = 0;

    //计算两个点的余弦值
    for (int i = 0; i < count; i++) {
        XmulY += (pointx[i] * pointy[i]);
        Xdis2 += pointx[i] * pointx[i];
        Ydis2 += pointy[i] * pointy[i];

    }
    double res = XmulY / (sqrt(Xdis2) * sqrt(Ydis2));
    return res;

}

//对获取的docid的余弦值排序，并去除对应项的内容形参为拥有关键词的docid数组和关键字词组
std::map<double, RssItem, std::greater<double>> WebPageQuery::getRes(const std::vector<int>& docIds, const std::vector<std::string>& keyWords) {

    std::map<double, RssItem, std::greater<double>> res;
    std::map<int,double> tmp;
    string key="网页查询排序："+WstringOperation::vectorToString(keyWords);
    string rss= _redis->getRedisData(key);
    if(rss==string())
    {
        for (const auto& id : docIds) {
            //获取docids项与关键词的余弦值
            double cosTmp = getCos(id, keyWords);
            tmp[id]=cosTmp;
            //获取docid的内容
            //RssItem strTmp = _webPageReader->getWebLib()[id];

        }
        string value=WstringOperation::mapToString(tmp);
        _redis->setRedisData(key,value);
    }
    else
    {
        tmp=WstringOperation::stringToMap(rss);
    }

    for(auto& id:docIds)
    {
        double cosTmp=tmp[id];
        RssItem strTmp=_webPageReader->getWebLib().at(id);
        res[cosTmp] = strTmp;
    }
    //遍历拥有关键词的docid数组
    return res;

}

