/*TcpServer TcpClient
epoll + 线程池
好处：能够把网络io代码和业务区分开
用户连接和断开 用户可读写事件
*/
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <iostream>
#include <functional>
using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;
//step1:组合tcpserver对象
//step2:创建eventloop时间循环对象指针
//step3:明确tcpserver构造需要什么参数
//step4:注册回调
//step5:确立worker数量 io线程数
class ChatServer{
public:
    ChatServer(EventLoop* loop,//事件循环 reactor反应堆
                const InetAddress& listenAddr,//ip + port
                const string& nameArg)//服务器名字
                :_server(loop,listenAddr,nameArg),_loop(loop)
    {
        //创建断开回调
        _server.setConnectionCallback(std::bind(&ChatServer::onConnection,this,_1));
        //读写回调
        _server.setMessageCallback(std::bind(&ChatServer::onMessage,this,_1,_2,_3));
        //设置服务器端的数量
        _server.setThreadNum(4);//y一个io线程 3个worker
    }

    void start(){
        _server.start();
    }
private:

    void onConnection(const TcpConnectionPtr& conn){
        if(conn->connected()){
            cout<<conn->peerAddress().toIpPort()<<"->"<<conn->localAddress().toIpPort()<<"state:online"<<endl;
        }else{
            cout<<conn->peerAddress().toIpPort()<<"->"<<conn->localAddress().toIpPort()<<"state:offline"<<endl;
            conn->shutdown();//close(fd)
            //_loop->quit();
        }
    }
    void onMessage(const TcpConnectionPtr &conn,
                    Buffer *buffer,
                    Timestamp time)
    {
        string buf = buffer->retrieveAllAsString();
        cout<<"recv data:"<<buf<<" time"<<time.toString()<<endl;
        conn->send(buf);
    }
    TcpServer _server;
    EventLoop *_loop;
};

int main(){
    EventLoop loop;//epoll
    InetAddress addr("127.0.0.1",6000);
    ChatServer server(&loop,addr,"chatserver");
    server.start();//listenfd epoll_ctl =>epoll
    loop.loop();//epoll wait
    return 0;
}