#ifndef TCP_CLIENT_HEADER
#define TCP_CLIENT_HEADER

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#define TCP_CLIENT_BUFFER_SIZE 512


#include "modul/TCPDataHandler/tcpdatahandler.h"
#include "controller/controller.h"
#include <WinSock2.h>
#include <iostream>
#include <thread>
#include <string>
#include <stdio.h>
#include <chrono>
#include <ctime>


class TCPClient {
private:
    std::thread *connectionThread;
    int MAX_WAIT_TIME_FOR_CONNECTION;

    Controller *controller;
    TCPDataHandler *dataHandler;
    WSADATA winSockData;
    SOCKET dataSocket;
    sockaddr_in dataSocketAddress;
    std::string dataSocketAddressString;
    sockaddr_in serverAddress;
    void connectionRoutine(SOCKET *clientSocket, sockaddr_in *serverAddress);
    int tryToConnect(SOCKET *clientSocket, sockaddr_in *serverAddress);
    int connectToServer(SOCKET *clientSocket, sockaddr_in *serverAddress);

public:
    TCPClient();
    void connectToMyServer(std::string serverAddressString);
    void setController(Controller *controller);
};

#endif // TCP_CLIENT_HEADER


