#ifndef TCP_SOCKET_FUNCTIONS
#define TCP_SOCKET_FUNCTIONS

#include <WinSock2.h>
#include <string>

int initWSAStartup(WSADATA *winSock);
void initSocketAddressData(sockaddr_in *socketAddress, std::string address);
int initSocket(SOCKET *initSocket);

int sendData(SOCKET *serverSocket, char *buffer);
int recvData(SOCKET *serverSocket, char *buffer);

int closeSocket(SOCKET *socketToClose);
int myWSACleanUp();


#endif // !TCP_SOCKET_FUNCTIONS
