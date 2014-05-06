#pragma once
#include <QWidget>
#include <QTcpSocket>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDataStream>
#include <QTime>

class Client : public QWidget
{
    Q_OBJECT

public:
    Client(const QString &strHost, int port, QWidget *parent = 0);

private:
    QTcpSocket *mySocket;
    QTextEdit *txtInfo;
    QLineEdit *txtInput;
    quint16 nextBlockSize;

private slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError err);
    void slotSendToServer();
    void slotConnected();
};
