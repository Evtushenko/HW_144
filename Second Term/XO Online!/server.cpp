#include "server.h"

Server::Server(const int port, const int size, QWidget *parent) :
    QWidget(parent),
    size(size),
    menu(new QVBoxLayout(this)),
    field(new Widget(size, "green", "blue")),
    myServer(new QTcpServer(this)),
    txtInfo(new QTextEdit),
    nextBlockSize(0)
{
    connect(field, SIGNAL(sendNumber(int)), this, SLOT(sendToClient(int)));
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

    txtInfo->setReadOnly(true);

    menu->addWidget(new QLabel("<H1>Server</H1>"));
    menu->addWidget(txtInfo);
    menu->addLayout(field->menu);
    setLayout(menu);
}

void Server::sendToClient(int number)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);
    out << quint16(0) << QString::number(number);

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    sender->write(arrBlock);
    txtInfo->append("<b>You:</b>");
    txtInfo->append(QString::number(number));
    field->lockButtons();
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
    QString str;
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

        //QTime time;

        in >> str;
        txtInfo->append("<b>Client:</b>");
        QString strMessage = str;
        txtInfo->append(strMessage);

        nextBlockSize = 0;
    }
    field->useTurn(str.toInt());
    field->unlockButtons();
}
