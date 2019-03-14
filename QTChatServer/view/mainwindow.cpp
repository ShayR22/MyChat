#include "view/mainwindow.h"
#include "ui_mainwindow.h"
#include "dataTransferObjects/viewConnectionDTO/viewConnectionDTO.h"
#include "dataTransferObjects/viewChatDTO/viewchatdto.h"
#include <qmetatype.h>
#include <iostream>

#include <thread>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->acceptFromBtn->setDisabled(true);
    this->setWindowTitle("Server");

    MENU_STARTUP_PAGE = 0;
    CONNECTION_PAGE = 1;
    CHAT_PAGE = 2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setController(Controller *controller){
    this->controller = controller;
    //connect signals to slots
    qRegisterMetaType<std::string>("std::string");
    connect(this->controller, SIGNAL( emitIncomingCall(std::string) ),this,SLOT( incomingCall(std::string)) ); // incoming call
    connect(this->controller, SIGNAL( emitSuccessConnection() ),this,SLOT( connectionSuccess() )); // connection established
    connect(this->controller, SIGNAL( emitFailedConnection() ),this,SLOT( connectionFailed() )); // connection failed
    connect(this->controller, SIGNAL( emitIncomingMessage(std::string) ),this,SLOT(incomingMessage(std::string) )); // incoming message

}

void MainWindow::on_connectToBtn_clicked()
{
    string userAddress = this->ui->connectToLine->text().toStdString();
    ViewConnectionDTO dto(userAddress, false);
    this->controller->viewChanges(dto);

    this->ui->stackedWidget->setCurrentIndex(CONNECTION_PAGE);
}

void MainWindow::on_acceptFromBtn_clicked()
{
    ViewConnectionDTO dto("", true);
    this->controller->viewChanges(dto);
    this->ui->stackedWidget->setCurrentIndex(CHAT_PAGE);
}

void MainWindow::on_exitBtn_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(MENU_STARTUP_PAGE);
}


void MainWindow::incomingCall(string userName){
    this->ui->acceptFromBtn->setDisabled(false);
    QString qtUserName = QString::fromStdString(userName);
    this->ui->acceptFromLine->setText(qtUserName);
}

void MainWindow::connectionSuccess(){
    this->ui->stackedWidget->setCurrentIndex(CHAT_PAGE);
}

void MainWindow::connectionFailed(){
     this->ui->stackedWidget->setCurrentIndex(MENU_STARTUP_PAGE);
}


void MainWindow::on_sendBtn_clicked()
{
    string sendString = this->ui->sendText->toPlainText().toStdString();
    ViewChatDTO dto(sendString);
    this->controller->viewChanges(dto);
}

void MainWindow::incomingMessage(string message)
{
    cout << "incoming message" << endl;
    QString Qmessage = QString::fromStdString(message);
    this->ui->chatList->addItem(Qmessage);
}
