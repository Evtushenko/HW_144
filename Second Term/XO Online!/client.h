#pragma once
#include <QWidget>
#include <QTcpSocket>
#include <QVBoxLayout>
#include <QDataStream>
#include <QMessageBox>
#include "widget.h"

class Client : public QWidget
{
    Q_OBJECT

public:
    Client(const QString &strHost, const int port, const int size, QWidget *parent = 0);
    ~Client() {
        delete field;
        delete menu;
        delete txtInfo;
        delete mySocket;
    }

private:
    int const size;
    QVBoxLayout * menu;
    Widget *field;

    QTcpSocket *mySocket;
    QTextEdit *txtInfo;
    quint16 nextBlockSize;

private slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError err);
    void slotSendToServer(int number);
    void slotConnected();
};

