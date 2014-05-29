#include "client.h"

Client::Client(const QString &strHost, const int port, const int size, QWidget *parent) :
    QWidget(parent),
    size(size),
    menu(new QVBoxLayout(this)),
    field(new Widget(size, "blue", "green")),
    mySocket(new QTcpSocket),
    txtInfo(new QTextEdit),
    nextBlockSize(0)

{
    connect(field, SIGNAL(sendNumber(int)), this, SLOT(slotSendToServer(int)));
    mySocket->connectToHost(strHost, port);
    connect(mySocket, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(mySocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(mySocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(slotError(QAbstractSocket::SocketError)));

    txtInfo->setReadOnly(true);
    menu->addWidget(new QLabel("<H1>Client</H1>"));
    menu->addWidget(txtInfo);
    menu->addLayout(field->menu);
    setLayout(menu);
}

void Client::slotReadyRead()
{
    QDataStream in(mySocket);
    in.setVersion(QDataStream::Qt_5_2);
    QString str;
    for(;;)
    {
        if (!nextBlockSize)
        {
            if (mySocket->bytesAvailable() < sizeof(quint16)) //bytesAvailable
                break;
            in >> nextBlockSize;
        }

        if (mySocket->bytesAvailable() < nextBlockSize)
            break;


        in >> str;
        txtInfo->append("<b>Server:</b>");
        txtInfo->append(str);
        nextBlockSize = 0;
    }
    field->useTurn(str.toInt());
    field->unlockButtons();
}

void Client::slotError(QAbstractSocket::SocketError err)
{
    QString strError = "Error : " + (err == QAbstractSocket::HostNotFoundError ?
                                     "The Host was not found." :
                                     err == QAbstractSocket::RemoteHostClosedError ?
                                     "The remote host is closed." :
                                     err == QAbstractSocket::ConnectionRefusedError ?
                                     "The connection was refused." :
                                     QString(mySocket->errorString())
                                     );
    txtInfo->append(strError);
}

void Client::slotSendToServer(int number)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);
    out << quint16(0) << QString::number(number);

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    mySocket->write(arrBlock);
    txtInfo->append("<b>You:</b>");
    txtInfo->append(QString::number(number));
}

void Client::slotConnected()
{
    txtInfo->append("Recevied the connected() signal");
}
