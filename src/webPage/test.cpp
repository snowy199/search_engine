#include "webPage/WebPageQuery.h"
#include "dict/split_tool.h"
#include <iostream>
using namespace std;
int main()
{

    mylog::Mylogger::getInstance();
    WebPageQuery* wpq=new WebPageQuery();
    string input;
    while(cin>>input){
    nlohmann::json vec=wpq->Query(input);

  
    for(auto i:vec["item"])
    {
        string title=i["title"];
        string link=i["link"];
        string content=i["content"];
        cout<<title<<endl<<link<<endl<<content<<endl<<endl;
    }
  
    
   }
}