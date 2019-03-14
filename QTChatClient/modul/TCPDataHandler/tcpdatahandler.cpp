#include "modul/TCPDataHandler/tcpdatahandler.h"
#include <string>
#include <iostream>
#include "modul/TCPSocketFunctions/tcpsocketfunctions.h"
#include <dataTransferObjects/modulChatDTO/modulchatodto.h>
#include "modul/TCPSocketFunctions/tcpsocketfunctions.h"

using namespace std;

//TODO change sendMessages and recvMessages to be with controller

void TCPDataHandler::recvMessages() {
    while (keepRecvingInformation) {
        dataSocketMutex.lock();
        if (!recvData(&dataSocket, recvBuffer)) {
           string recvMessage = string(recvBuffer);
           ModulChatDTO dto(recvMessage);
           cout << "recvMessage = " << recvMessage.c_str() << endl;
           this->controller->modulChanges(dto);
        }
        dataSocketMutex.unlock();
    }
}

void TCPDataHandler::sendMessages() {
    string tempBuffer;
    while (keepSendingInformation) {

        cout << "enter data to send please" << endl;

        getline(cin, tempBuffer);
        strcpy(sendBuffer, tempBuffer.c_str());

        dataSocketMutex.lock();
        if (!sendMessage(&dataSocket, sendBuffer)) {
            cout << name << " send: " << sendBuffer << endl;
        }
        dataSocketMutex.unlock();

    }
}

TCPDataHandler::TCPDataHandler(SOCKET *dataTranferSocket, string handlerName) {
    dataSocket = *dataTranferSocket;
    name = handlerName;
}


void TCPDataHandler::setHandlerController(Controller *controller){
    this->controller = controller;
}

//void TCPDataHandler::startSend() {
 //   keepSendingInformation = true;
 //   sendThread = new thread(&TCPDataHandler::sendMessages, this);
 //   sendThread->detach();
//}

//void TCPDataHandler::stopSend()
//    keepRecvingInformation = false;
  //  sendThread->join();
  //  sendThread->~thread();
//}

void TCPDataHandler::sendMessage(string message){
    strcpy(sendBuffer, message.c_str());

    dataSocketMutex.lock();
    if (!sendData(&dataSocket, sendBuffer)) {
        cout << name << " send: " << sendBuffer << endl;
    }
    dataSocketMutex.unlock();
}


void TCPDataHandler::startRecv() {
    keepRecvingInformation = true;
    recvThread = new thread(&TCPDataHandler::recvMessages, this);
    recvThread->detach();
}

void TCPDataHandler::stopRecv() {
    keepRecvingInformation = false;
   // recvThread->join();
   // recvThread->~thread();
}

