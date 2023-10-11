#include "chatservice.hpp"
#include "public.hpp"
#include <string>
#include <muduo/base/Logging.h>
#include "usermodel.hpp"
using namespace muduo;

ChatService* ChatService::instance(){
    static ChatService service;
    return &service;
}

ChatService::ChatService(){
    _msgHandlerMap.insert({LOGIN_MSG,std::bind(&ChatService::login,this,_1,_2,_3)});
    _msgHandlerMap.insert({REG_MSG,std::bind(&ChatService::reg,this,_1,_2,_3)});
}
//ORM object relationmap对象关系映射，在业务层操作的都是对象； Dao层操作数据库
void ChatService::login(const TcpConnectionPtr &conn,json &js,Timestamp time){
    LOG_INFO<<"do login service";
}
void ChatService::reg(const TcpConnectionPtr &conn,json &js,Timestamp time){
    string name = js["name"];
    string pwd = js["password"];
    
    User user;
    user.setName(name);
    user.setPwd(pwd);
    
    // bool state = _userModel.insert(user);
    if(_userModel.insert(user)){
        json response ;
        response["msgid"] = REG_MSG_ACK;
        response["errno"] = 0;
        response["id"] = user.getID();
        conn->send(response.dump());
    }else{
        json response ;
        response["msgid"] = REG_MSG_ACK;
        response["errno"] = 1;
        conn->send(response.dump());
    }
    
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
}