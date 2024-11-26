#ifndef WEB_PAGE_QUERY_H
#define WEB_PAGE_QUERY_H

#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <codecvt>
#include <cwchar>
#include <string>
#include <nlohmann/json.hpp>
#include "WstringOperation.h"
#include "ChangeColor.h"
#include "dict/split_tool.h"
#include "webPage/WebPageReader.h"
#include "Configuration.h"
#include "WstringOperation.h"
#include "redis.h"
#include "mylog.h"


class WebPageQuery {
public:
    WebPageQuery();
    ~WebPageQuery();

    /**
     *      * 查询函数，返回包含查询结果的 JSON 对象
     *           * @param word 查询关键词
     *                * @return 查询结果的 JSON 对象
     *                     */
    nlohmann::json Query(const std::string& word);
    /**
     *      * 简略查询函数，返回包含查询结果的 JSON 对象
     *           * @param word 查询关键词
     *                * @return 查询结果的 JSON 对象
     *                     */
    nlohmann::json shortQuery(const std::string& word);
private:
    /**
     *      * 分词函数，将查询关键词切分为单词
     *           * @param word 查询关键词
     *                * @return 切分后的单词列表
     *                     */
    std::vector<std::string> cut(const std::string& word);
        /**
     *      * 获取包含指定单词的文档 ID 列表
     *           * @param words 单词列表
     *                * @return 文档 ID 列表
     *                     */
    std::vector<int> getDocId(const std::vector<std::string>& words);
        /**
     *      * 计算指定文档与关键词之间的余弦相似度
     *           * @param ID 文档 ID
     *                * @param keyWords 关键词列表
     *                     * @return 余弦相似度
     *                          */
    double getCos(int ID, const std::vector<std::string>& keyWords);
        /**
     *      * 获取查询结果
     *           * @param docIds 文档 ID 列表
     *                * @param keyWords 关键词列表
     *                     * @return 包含查询结果的映射，键为相似度，值为 RssItem 对象
     *                          */
    std::map<double, RssItem, std::greater<double>> getRes(const std::vector<int>& docIds, const std::vector<std::string>& keyWords);
    /**
     *      * 获取文档的内容
     *           * @param data RssItem 对象
     *                * @return 文档内容
     *                     */
    std::string getContent(RssItem data);
        /**
     *      * 在文档内容中查找关键词的位置
     *           * @param content 文档内容
     *                * @param keyWords 关键词列表
     *                     * @return 包含关键词位置的映射，键为关键词，值为位置列表
     *                          */
    map<string, vector<size_t>> findKeyword(const std::string& content, vector<string> keyWords);
    /**
     *      * 标记关键词在文档内容中的位置
     *           * @param content 文档内容
     *                * @param idx 关键词位置
     *                     * @param keyWordLength 关键词长度
     *                          * @return 标记后的文档内容
     *                               */
    std::string signRed(const std::string& content, size_t idx, int keyWordLength);
    /**
     *      * 修改 JSON 对象中的字段值
     *           * @param js JSON 对象
     *                * @param word 关键词列表
     *                     * @return 修改后的 JSON 对象
     *                          */
    nlohmann::json modifyJson(RssItem js, vector<string> word);
private:
    SplitTool* _splitTool;
    WebPageReader* _webPageReader;
    Configuration* _conf;
    std::set<std::string> _stopWord;
    Redis* _redis;
};
#endif  // WEB_PAGE_QUERY_H