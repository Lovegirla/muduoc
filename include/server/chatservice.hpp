#ifndef CHATSREVICE_H
#define CHATSREVICE_H
#include <muduo/net/TcpConnection.h>
#include <unordered_map>
#include "json.hpp"
#include <functional>
using namespace std;
using namespace muduo;
using namespace muduo::net;
using json = nlohmann::json;

using MsgHandler = std::function<void(const TcpConnectionPtr &conn,json &js,Timestamp)>;
class  ChatService
{
private:
    ChatService();

    unordered_map<int,MsgHandler> _msgHandlerMap;
public:
    static ChatService* instance();
    void login(const TcpConnectionPtr &conn,json &js,Timestamp time);
    void reg(const TcpConnectionPtr &conn,json &js,Timestamp time);

    MsgHandler getHandler(int msgid);
};


#endif