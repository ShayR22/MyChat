#ifndef TCP_SERVER_HEADER
#define TCP_SERVER_HEADER

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <WinSock2.h>
#include "modul/TCPDataHandler/tcpdatahandler.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <thread>
#include <mutex>
#include "controller/controller.h"

class TCPServer {
private:
    Controller *controller;
	TCPDataHandler *dataHandler;

	std::thread listeningThread;
	boolean isConnected;

	WSADATA winSockData;

	sockaddr_in listeningSocketAddress;
	std::string addressString;

	sockaddr_in clientAddress;

	SOCKET listeningSocket;
	SOCKET dataTransferSocket;


	int bindSocketToAddress(SOCKET *socketToBind, sockaddr_in *addressToBind);
	int listenSocket(SOCKET *listeningSocket, int maxListeningQue);

	void acceptSocket(SOCKET *acceptingSocket, SOCKET *serverSocket, sockaddr_in *clientAddress);
	
	void recvMessages();
	void sendMessages();

public:
	TCPServer(std::string listeningAddress);
    void setController(Controller *controller);
    void startToListen();
	void acceptCall();
};

#endif // !TCP_SERVER_HEADER

