#include "client.h"

Client::Client(const QString &strHost, int port, QWidget *parent) :
    QWidget(parent),
    nextBlockSize(0)
{
    mySocket = new QTcpSocket();

    mySocket->connectToHost(strHost, port);
    connect(mySocket, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(mySocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(mySocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(slotError(QAbstractSocket::SocketError)));

    txtInfo = new QTextEdit();
    txtInput = new QLineEdit();

    txtInfo->setReadOnly(true);
    QPushButton *send = new QPushButton("&Send");

    connect(send, SIGNAL(clicked()), this, SLOT(slotSendToServer()));
    connect(txtInput, SIGNAL(returnPressed()), this, SLOT(slotSendToServer()));

    QVBoxLayout *form = new QVBoxLayout(this);
    form->addWidget(new QLabel("<H1>Client</H1>"));
    form->addWidget(txtInfo);
    form->addWidget(txtInput);
    form->addWidget(send);
}

void Client::slotReadyRead()
{
    QDataStream in(mySocket);
    in.setVersion(QDataStream::Qt_5_2);
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

        QTime time;
        QString str;
        in >> time >> str;

        txtInfo->append(time.toString() + " " + str);
        nextBlockSize = 0;
    }
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

void Client::slotSendToServer()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_2);
    out << quint16(0) << QTime::currentTime() << txtInput->text();

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    mySocket->write(arrBlock);
    txtInfo->clear();
}

void Client::slotConnected()
{
    txtInfo->append("Recevied the connected() signal");
}
