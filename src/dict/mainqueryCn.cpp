#include<iostream>
#include "dict/key_recommander.h"
#include <string.h>

/*测试：中文关键字推荐*/
int main(){

    string str;
    while(true){
        cout<<"请输入查询的词："<<endl;
        cin>>str;
        if(str=="exit")break;
        CnKeyRecommander cn_kr(str);
        string result = cn_kr.query(0);
        cout << result << endl;
    }

    return 0;
}

