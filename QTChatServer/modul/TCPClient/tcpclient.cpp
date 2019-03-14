#include "modul/TCPClient/tcpclient.h"
#include "modul/TCPSocketFunctions/tcpsocketfunctions.h"


using namespace std;

int TCPClient::connectToServer(SOCKET *clientSocket, sockaddr_in *serverAddress)
{
    if ((connect((*clientSocket), (SOCKADDR*)serverAddress, sizeof(*serverAddress))) == SOCKET_ERROR)
    {
        return 1;
    }
    cout << "connected to server" << endl;
    return 0;
}


void TCPClient::connectionRoutine(SOCKET *clientSocket, sockaddr_in *serverAddress) {
    if (!tryToConnect(clientSocket, serverAddress)) {

        ModulConnectionDTO dto(false, true, "");
        this->controller->modulChanges(dto);

        u_long flag = 1; // any non 0 value will do
        ioctlsocket(dataSocket, FIONBIO, &flag); // make socket non blocking
        cout << "Client connected success" << endl;
        string name = "Client";
        this->dataHandler = new TCPDataHandler(clientSocket, name);
        this->dataHandler->setHandlerController(this->controller);
        this->dataHandler->startSend();
        this->dataHandler->startRecv();
    }
    else{
        ModulConnectionDTO dto(false, false, "");
        this->controller->modulChanges(dto);
    }
}

int TCPClient::tryToConnect(SOCKET *clientSocket, sockaddr_in *serverAddress) {
    long initConnectTime = clock();
    long currentTime;
    double timePass;
    do
    {
        if (!connectToServer(clientSocket, serverAddress)) {
            return  0;
        }
        currentTime = clock();
        timePass = ((currentTime - initConnectTime) / double(CLOCKS_PER_SEC));
    } while (timePass < MAX_WAIT_TIME_FOR_CONNECTION);
    return 1;
}

TCPClient::TCPClient() {
    this->MAX_WAIT_TIME_FOR_CONNECTION = 3;
    initWSAStartup(&winSockData);
    initSocket(&dataSocket);
}

void TCPClient::setController(Controller *controller){
    this->controller = controller;
}

void TCPClient::connectToMyServer(string serverAddressString) {
    initSocketAddressData(&serverAddress, serverAddressString);
    connectionThread = new thread(&TCPClient::connectionRoutine, this, &dataSocket, &serverAddress);
    connectionThread->detach();
}




