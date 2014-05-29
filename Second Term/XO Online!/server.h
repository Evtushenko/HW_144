#pragma once
#include <QWidget>
#include <QTcpServer>
#include <QVBoxLayout>
#include <QLabel>
#include <QDataStream>
#include <QTcpSocket>
#include <QMessageBox>
#include "widget.h"

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(const int port, const int size, QWidget *parent = 0);
    ~Server() {
        delete field;
        delete menu;
        delete txtInfo;
        delete myServer;
    }

private:

    int const size;
    QVBoxLayout * menu;
    Widget *field;

    QTcpServer *myServer;
    QTextEdit *txtInfo;
    quint16 nextBlockSize;
    QTcpSocket *sender;

public slots:
    void sendToClient(int number);
    virtual void slotNewConnection();
    void slotReadClient();
};
