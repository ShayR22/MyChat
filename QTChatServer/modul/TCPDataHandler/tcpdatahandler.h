#ifndef TCP_DATA_HANDLER_HEADER
#define TCP_DATA_HANDLER_HEADER

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#define SEND_RECV_BUFFER_SIZE 512

#include "controller/controller.h"
#include <WinSock2.h>
#include <string>
#include <mutex>
#include <thread>

class TCPDataHandler {
private:
    std::string name;

    Controller *controller;

    SOCKET dataSocket;


    std::mutex dataSocketMutex;
    bool keepRecvingInformation;
    bool keepSendingInformation;

    std::thread *sendThread;
    std::thread *recvThread;

    char sendBuffer[SEND_RECV_BUFFER_SIZE];
    char recvBuffer[SEND_RECV_BUFFER_SIZE];

    void recvMessages();
    void sendMessages();

public:
    TCPDataHandler(SOCKET *dataSocket, std::string HandlerName);
    void setHandlerController(Controller *controller);
    void startSend();
    void startRecv();
    void stopSend();
    void stopRecv();

};


#endif // !TCP_DATA_HANDLER_HEADER


