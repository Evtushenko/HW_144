#include "server.h"

Server::Server(int port, QWidget *parent) :
    QWidget(parent),
    nextBlockSize(0)
{
    myServer = new QTcpServer(this);
    if (!myServer->listen(QHostAddress::Any, port))
    {
        QMessageBox::critical(0, "Server Error",
                              "Unable to start the server:"
                              + myServer->errorString()
                              );
        myServer->close();
        return;
    }

    connect(myServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

    txtInfo = new QTextEdit();
    txtInput = new QLineEdit();
    txtInfo->setReadOnly(true);

    QPushButton *send = new QPushButton("&send");
    connect(send, SIGNAL(clicked()), this, SLOT(sendToClient()));
    connect(txtInput, SIGNAL(returnPressed()), this, SLOT(sendToClient()));

    QVBoxLayout *form = new QVBoxLayout(this);
    form->addWidget(new QLabel("<H1>Server</H1>"));
    form->addWidget(txtInfo);
    form->addWidget(txtInput);
    form->addWidget(send);
}

void Server::sendToClient()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);
    out << quint16(0) << QTime::currentTime() << txtInput->text();

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    sender->write(arrBlock);
}

void Server::slotNewConnection()
{
    sender = myServer->nextPendingConnection();
    connect(sender, SIGNAL(disconnected()), sender, SLOT(deleteLater()));
    connect(sender, SIGNAL(readyRead()), this, SLOT(slotReadClient()));
}

void Server::slotReadClient()
{
    QDataStream in(sender);
    in.setVersion(QDataStream::Qt_5_2);

    for(;;)
    {
        if (!nextBlockSize)
        {
            if (sender->bytesAvailable() < sizeof(quint16))
                break;
            in >> nextBlockSize;
        }

        if (sender->bytesAvailable() < nextBlockSize)
            break;

        QTime time;
        QString str;
        in >> time >> str;

        QString strMessage = time.toString() + " " + "Client has sent - " + str;
        txtInfo->append(strMessage);

        nextBlockSize = 0;
    }
}
