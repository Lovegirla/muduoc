#ifndef CHATSREVICE_H
#define CHATSREVICE_H
#include <muduo/net/TcpConnection.h>
#include <unordered_map>
#include "json.hpp"
#include <functional>
using namespace std;
using json = nlohmann::json;

using MsgHandler = std::function<void(const TcpConnectionPtr &conn)>
class  ChatService
{
private:
    /* data */
public:

};


#endif