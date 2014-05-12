#pragma once
#include <QWidget>
#include <QTcpServer>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDataStream>
#include <QMessageBox>
#include <QTime>
#include <QTcpSocket>

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(int port, QWidget *parent = 0);

private:
    QTcpServer *myServer;
    QLineEdit *txtInput;
    QTextEdit *txtInfo;
    quint16 nextBlockSize;
    QTcpSocket *sender;

public slots:
    void sendToClient();
    virtual void slotNewConnection();
    void slotReadClient();
};
