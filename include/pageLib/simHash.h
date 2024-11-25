#ifndef _SIMHASH_H
#define _SIMHASH_H

#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;
class SimHash {
public:
    SimHash();
    ~SimHash();
    /**
     *      * 计算 SimHash 值
     *           * @param idTfidf 包含关键词及其 TF-IDF 值的映射
     *                * @return 计算得到的 SimHash 值的字符串表示
     *                     */
    string calculateSimHash(const map<string, double>& idTfidf);

        /**
     *      * 判断是否为重复内容
     *           * @param simhash SimHash 值的字符串表示
     *                * @return 是否为重复内容的布尔值
     *                     */
    bool isDuplicate(const string& simhash);


private:
    vector<string> _simHash;  // 存储 SimHash 值的向量

    /**
     *      * 提取关键词
     *           * @param idTfidf 包含关键词及其 TF-IDF 值的映射
     *                * @return 提取得到的关键词向量
     *                     */
    vector<string> getKeyWords(const map<string, double>& idTfidf);

    /**
     *      * 计算汉明距离
     *           * @param s1 字符串 s1
     *                * @param s2 字符串 s2
     *                     * @return 计算得到的汉明距离
     *                          */
    int hammingDistance(const string& s1, const string& s2);
};



#endif