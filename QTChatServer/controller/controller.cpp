#include "controller.h"
#include "modul/TCPClient/tcpclient.h"
#include "modul/TCPServer/TCPServer.h"
#include "view/mainwindow.h"


#include <iostream>


Controller::Controller()
{

}

void Controller::setClient(TCPClient *client){
    this->client = client;
}

void Controller::setServer(TCPServer *server){
    this->server = server;
}
void Controller::setView(MainWindow *view){
    this->view = view;
}

void Controller::modulChanges(ModulConnectionDTO dto){
    std::cout << "enter controller modulChanges ConnectionDTO" << std::endl;
    if(dto.isIncomingCall()){
       emit emitIncomingCall(dto.getIncmingCallFrom());
    }
    else if(dto.isConnectionSuccess()){
       // this->view->connectionSuccess();
       emit emitSuccessConnection();
    }
    else{
       // this->view->connectionFailed();
       emit emitFailedConnection();
    }
}

void Controller::modulChanges(ModulChatDTO dto){
    std::cout << "controller emiting incoming message with message " << dto.getMessage().c_str() << std::endl;
    emit emitIncomingMessage(dto.getMessage());
}


void Controller::viewChanges(ViewConnectionDTO dto){
    if(dto.getIsAcceptingCall()){
        this->server->acceptCall();
    }
    else{
        this->client->connectToMyServer(dto.getWhoToConnect());
    }
}

void Controller::viewChanges(ViewChatDTO dto){

}



