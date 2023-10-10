#include "json.hpp"
using json = nlohmann::json;
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

string func1(){
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhangsan";
    js["to"] = "lisi";
    js["msg"] = "hello";
    cout<<js<<endl;

    string sendBuf = js.dump();
    cout<<sendBuf.c_str()<<endl;
    return sendBuf;
}


void func2(){
    json js;
    js["id"] = {1,2,3,4,5};
    js["msg"]["zhang san"] = "hello word";
}

//json 容器
void func3(){
    json js;
// 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    js["list"] = vec;
    // 直接序列化一个map容器x
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;
    cout<<js<<endl;
}

int main(){
    string recvBuf = func1();
    json buf = json::parse(recvBuf);
    cout<<buf["msg_type"]<<endl;
    cout<<buf<<endl;
    return 0;
}