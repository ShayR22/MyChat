#-------------------------------------------------
#
# Project created by QtCreator 2018-12-21T15:28:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTChatClient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11


LIBS += -lws2_32

SOURCES += \
    controller/controller.cpp \
    dataTransferObjects/modulConnectionDTO/modulConnectionDTO.cpp \
    dataTransferObjects/viewConnectionDTO/viewConnectionDTO.cpp \
    modul/TCPClient/tcpclient.cpp \
    modul/TCPDataHandler/tcpdatahandler.cpp \
    modul/TCPServer/TCPServer.cpp \
    modul/TCPSocketFunctions/tcpsocektfunctions.cpp \
    view/mainwindow.cpp \
    main.cpp \
    dataTransferObjects/modulChatDTO/modulchatodto.cpp \
    dataTransferObjects/viewChatDTO/viewchatdto.cpp



HEADERS += \
    controller/controller.h \
    dataTransferObjects/modulConnectionDTO/modulConnectionDTO.h \
    dataTransferObjects/viewConnectionDTO/viewConnectionDTO.h \
    modul/TCPClient/tcpclient.h \
    modul/TCPServer/TCPServer.h \
    modul/TCPDataHandler/tcpdatahandler.h \
    modul/TCPSocketFunctions/tcpsocketfunctions.h \
    view/mainwindow.h \
    dataTransferObjects/modulChatDTO/modulchatodto.h \
    dataTransferObjects/viewChatDTO/viewchatdto.h


FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README
