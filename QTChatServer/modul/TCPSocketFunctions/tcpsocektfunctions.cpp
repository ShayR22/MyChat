#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "modul/TCPSocketFunctions/tcpsocketfunctions.h"
#include <iostream>

using namespace std;

int initWSAStartup(WSADATA *winSock) {
    if (WSAStartup(MAKEWORD(2, 2), winSock))
    {
        cout << "error on winsock, (WSA startup) " << endl;
        return 1;
    }
    return 0;
}

void initSocketAddressData(sockaddr_in *socketAddress, string address) {
    socketAddress->sin_family = AF_INET; // ipv4
    socketAddress->sin_addr.s_addr = inet_addr(address.c_str()); // s_addr is macro shortcut for s_un.S_addr
    socketAddress->sin_port = htons(8000); // convet short into big-endian (TCP/IP byte order)
}

int initSocket(SOCKET *initSocket) {
    *initSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (*initSocket == INVALID_SOCKET)
    {
        cout << "failed to create socket " << WSAGetLastError() << endl;
        return 1;
    }
    return 0;
}

int sendData(SOCKET *serverSocket, char *buffer)
{
    int bufferSize = strlen(buffer) + 1;
    int flags = 0;
    if ((send(*serverSocket, buffer, bufferSize, flags)) == SOCKET_ERROR)
    {
        cout << "failed to send data " << WSAGetLastError() << endl;
        return 1;
    }
    return 0;
}

int recvData(SOCKET *serverSocket, char *buffer)
{
    string temp;
    int bufferSize = strlen(buffer) + 1;
    int flags = 0;
    bool readSomething = false;
    int error;
    do {
        error = recv(*serverSocket, buffer, bufferSize, flags);
        if (error != SOCKET_ERROR)
        {
            temp.append(buffer);
            readSomething = true;
        }
    } while (error != SOCKET_ERROR);

    if (readSomething) {
        strcpy(buffer, temp.c_str());
        return 0;
    }
    else {
        return 1;
    }
}

int closeSocket(SOCKET *socketToClose)
{
    if ((closesocket(*socketToClose)) == SOCKET_ERROR)
    {
        cout << "fail to close socket " << WSAGetLastError() << endl;
        return 1;
    }
    return 0;
}

int myWSACleanUp()
{
    if ((WSACleanup()) == SOCKET_ERROR)
    {
        cout << "failed to cleanup" << endl;
        return 1;
    }
    return 0;
}
