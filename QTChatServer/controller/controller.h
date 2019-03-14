#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "dataTransferObjects/modulConnectionDTO/modulConnectionDTO.h"
#include "dataTransferObjects/viewConnectionDTO/viewConnectionDTO.h"
#include "dataTransferObjects/modulChatDTO/modulchatodto.h"
#include "dataTransferObjects/viewChatDTO/viewchatdto.h"

//starter definitions against infi include loop.
class TCPClient; // this is part of modul
class TCPServer; // this is part of modul
class MainWindow; // this is view

#include <QObject>

//Added extend to QObject for signals reasons.
class Controller: public QObject {
    Q_OBJECT;
private:
    TCPClient *client;
    TCPServer *server;
    MainWindow *view;

public:
    Controller();
    void setClient(TCPClient *client);
    void setServer(TCPServer *server);
    void setView(MainWindow *view);
    void modulChanges(ModulConnectionDTO dto);
    void modulChanges(ModulChatDTO dto);
    void viewChanges(ViewConnectionDTO dto);
    void viewChanges(ViewChatDTO dto);

signals:
    void emitIncomingCall(std::string caller);
    void emitSuccessConnection();
    void emitFailedConnection();
    void emitIncomingMessage(std::string message);
};


#endif // CONTROLLER_H
