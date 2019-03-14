#include "modul/TCPClient/tcpclient.h"
#include "modul/TCPServer/TCPServer.h"
#include "controller/controller.h"
#include "view/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow applicationWindow;

    TCPServer server("127.0.0.1");
    //TCPClient client;
    Controller controller;

    //controller.setClient(&client);
    controller.setServer(&server);
    controller.setView(&applicationWindow);

    server.setController(&controller);
    server.startToListen();
    //client.setController(&controller);
    applicationWindow.setController(&controller);

    applicationWindow.show();


    return a.exec();
}
