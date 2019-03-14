#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "controller/controller.h"
#include <QMainWindow>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setController(Controller *controller);

private slots:
    //buttons
    void on_connectToBtn_clicked();
    void on_acceptFromBtn_clicked();
    void on_sendBtn_clicked();
    void on_exitBtn_clicked();

    //connection
    void incomingCall(std::string);
    void connectionSuccess();
    void connectionFailed();

    //chat
    void incomingMessage(std::string);



private:
    Controller *controller;
    Ui::MainWindow *ui;
    int MENU_STARTUP_PAGE;
    int CONNECTION_PAGE;
    int CHAT_PAGE;

};

#endif // MAINWINDOW_H
