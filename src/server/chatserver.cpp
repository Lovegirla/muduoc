#include "chatserver.hpp"
#include "chatservice.hpp"
#include <functional>
#include <string>
#include <iostream>
#include "json.hpp"
using namespace std;
using namespace placeholders;
using json = nlohmann::json;
ChatServer::ChatServer(EventLoop *loop,
               const InetAddress &listenAddr,
               const string &nameArg):_server(loop,listenAddr,nameArg),_loop(loop)
{
    _server.setConnectionCallback(std::bind(&ChatServer::onConnection,this,_1));

    _server.setMessageCallback(std::bind(&ChatServer::onMessage,this,_1,_2,_3));

    _server.setThreadNum(4);
}

void ChatServer::onConnection(const TcpConnectionPtr &conn)
{
    //客户端断开连接
    if(conn->connected()){
        conn->shutdown();
    }
}

void ChatServer::onMessage(const TcpConnectionPtr &conn,
                   Buffer *buffer,
                   Timestamp time)
{
    string buf = buffer->retrieveAllAsString();
    //数据反序列化
    json js = json::parse(buf);
    //达到的目的：完全解耦网络模块的代码和业务模块的代码
    auto msgHandler = ChatService::instance()->getHandler(js["msgid"].get<int>());
    msgHandler(conn,js,time);
}

void ChatServer::start(){
    _server.start();
}