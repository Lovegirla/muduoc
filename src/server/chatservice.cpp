#include "chatservice.hpp"
#include "public.hpp"
#include <string>
#include <muduo/base/Logging.h>
using namespace muduo;

ChatService* ChatService::instance(){
    static ChatService service;
    return &service;
}

ChatService::ChatService(){
    _msgHandlerMap.insert({LOGIN_MSG,std::bind(&ChatService::login,this,_1,_2,_3)});
    _msgHandlerMap.insert({REG_MSG,std::bind(&ChatService::reg,this,_1,_2,_3)});
}

void ChatService::login(const TcpConnectionPtr &conn,json &js,Timestamp time){

}
void ChatService::reg(const TcpConnectionPtr &conn,json &js,Timestamp time){

}
MsgHandler ChatService::getHandler(int msgid){
    auto it = _msgHandlerMap.find(msgid);
    if(it == _msgHandlerMap.end()){
        return [=](const TcpConnectionPtr &conn,json &js,Timestamp time){
            LOG_ERROR << "msgid:"<<msgid<<"can not find handler";
        };
    }
    else{
        return _msgHandlerMap[msgid];
    }
    return _msgHandlerMap[msgid];
}