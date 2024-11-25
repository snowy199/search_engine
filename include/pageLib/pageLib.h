#ifndef _PAGELIB_H
#define _PAGELIB_H

#include "pageLib/webPage.h"
#include "pageLib/offsetPage.h"
#include "pageLib/indexPage.h"
#include "mylog.h"

class PageLib {
public:
        /**
         *      * 构造函数
         *           * @param conf 配置对象的引用
         *                */
        PageLib(Configuration& conf)
                    : _webPages(conf),
                              _offPages(conf, _webPages),
                              _indexPage(conf, _webPages) {}

        // 创建网页库
        void create() {
            _webPages.creat();
        }

        // 存储网页库、偏移库和索引页库
        void store() {
            _webPages.store();
            LogInfo("WebPageLib stored");
            _offPages.store();
            LogInfo("OffPageLib stored");
            _indexPage.store();
            LogInfo("IndexPageLib stored");
        }

private:
        WebPages _webPages;  // 网页库对象
        OffsetPage _offPages;  // 偏移库对象
        IndexPage _indexPage;  // 索引页库对象
};


#endif