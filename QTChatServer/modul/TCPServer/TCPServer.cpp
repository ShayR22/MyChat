#include "TCPServer.h"
#include "modul/TCPSocketFunctions/tcpsocketfunctions.h"

#define TCP_SERVER_MAX_CLIENT_TO_LISTEN 2

using namespace std;

int TCPServer::bindSocketToAddress(SOCKET *socketToBind, sockaddr_in *addressToBind)
{
	//TODO ask ben about global call to bind
	int bindError = ::bind((*socketToBind), (SOCKADDR*)addressToBind, sizeof(*addressToBind));
	if (bindError == SOCKET_ERROR)
	{
		cout << "failed to bind socket to address" << WSAGetLastError() << endl;
		return 1;
	}
	return 0;
}

int TCPServer::listenSocket(SOCKET *listeningSocket, int maxListeningQue)
{
	if ((listen(*listeningSocket, maxListeningQue)) == SOCKET_ERROR)
	{
		cout << "failed to listen " << WSAGetLastError() << endl;
		return 1;
	}
	return 0;
}

//TODO fix method
void TCPServer::acceptSocket(SOCKET *acceptingSocket, SOCKET *serverSocket, sockaddr_in *clientAddress)
{
	cout << "Server Waiting for a client to connect" << endl;
	int clientAddressSize = sizeof(*clientAddress);

	do
	{
		*acceptingSocket = accept(*serverSocket, (SOCKADDR*)clientAddress, &clientAddressSize);
	} while (*acceptingSocket == INVALID_SOCKET);

    string clientName = inet_ntoa(clientAddress->sin_addr);

    cout << "Client name is: " << clientName << endl;
    ModulConnectionDTO dto(true, false, clientName);
    this->controller->modulChanges(dto);

	cout << "Server accepted Client" << endl;
	isConnected = true;
	
}


TCPServer::TCPServer(string listeningAddress) {
	initWSAStartup(&winSockData);
	initSocketAddressData(&listeningSocketAddress, listeningAddress);
	initSocket(&listeningSocket);
	bindSocketToAddress(&listeningSocket, &listeningSocketAddress);

	listenSocket(&listeningSocket, TCP_SERVER_MAX_CLIENT_TO_LISTEN);
	
	u_long flag = 1; // any non 0 value will do
	ioctlsocket(listeningSocket, FIONBIO, &flag); // make socket non blocking
}

void TCPServer::setController(Controller *controller){
    this->controller = controller;
}

void TCPServer::startToListen(){
    isConnected = false;
    listeningThread = thread(&TCPServer::acceptSocket, this, &dataTransferSocket, &listeningSocket, &clientAddress);
    listeningThread.detach();
}


void TCPServer::acceptCall() {
    if(isConnected){
        string name = "Server";
        dataHandler = new TCPDataHandler(&dataTransferSocket, name);
        dataHandler->setHandlerController(controller);
        dataHandler->startSend();
        dataHandler->startRecv();
    }
    else{
        cout << "failed to accept because isConnected = false" << endl;
    }
}






