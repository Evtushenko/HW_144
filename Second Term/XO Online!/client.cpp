#include "client.h"

Client::Client(const QString &strHost, const int port, const int size, QWidget *parent) :
    QWidget(parent),
    size(size),
    buttons(new QPushButton *[size]),
    columns(new QHBoxLayout [size]),
    menu(new QVBoxLayout(this)),
    buttonMapper(new QSignalMapper(this)),
    nextBlockSize(0)

{

    mySocket = new QTcpSocket();

    mySocket->connectToHost(strHost, port);
    connect(mySocket, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(mySocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(mySocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(slotError(QAbstractSocket::SocketError)));

    txtInfo = new QTextEdit();

    txtInfo->setReadOnly(true);

    menu->addWidget(new QLabel("<H1>Client</H1>"));
    menu->addWidget(txtInfo);

    createButtons();
}

void Client::createButtons()
{
    for (int i = 0; i < size; ++i)
    {
        buttons[i] = new QPushButton [size];
        for (int j = 0; j < size; ++j)
            columns[i].addWidget(&buttons[i][j]);
    }


    for (int i = 0; i < size; ++i)
        menu->addLayout(&columns[i]);

    for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                buttonMapper->setMapping(&buttons[i][j], &buttons[i][j]);

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                connect(&buttons[i][j], SIGNAL(clicked()), buttonMapper, SLOT(map()));

    connect(buttonMapper, SIGNAL(mapped(QWidget *)), this, SLOT(queue(QWidget *)));
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
        txtInfo->append("<b>Friend:</b>");
        txtInfo->append(str);
        nextBlockSize = 0;
    }
    useTurn(str.toInt());
    unlockButtons();
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

int Client::findNumber(QWidget *pressedButton) {
    int counter = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            if (pressedButton == &buttons[i][j])
                return counter;
            counter++;
        }
    return -1;
}

void Client::lockButtons() {
    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size; j++)
            buttons[i][j].setEnabled(false);
}

void Client::unlockButtons() {
    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size; j++) {
            if (buttons[i][j].styleSheet() != QString("background-color:green") && buttons[i][j].styleSheet() != QString("background-color:blue") )
                buttons[i][j].setEnabled(true);
        }
}

void Client::useTurn(int number)
{
    int i = number / size;
    int j = number % size;
    buttons[i][j].setStyleSheet("background-color:blue");
    buttons[i][j].setDisabled(true);
    if (endGame(number)) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Game Over!");
            msgBox.setText("U R LOSER!");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
    }

}

void Client::queue(QWidget *pressedButton)
{
    //if (amountMoves % 2 == 0) // если наша очередь
    //{
    pressedButton->setStyleSheet("background-color:green");
    pressedButton->setDisabled(true);
    int number = findNumber(pressedButton);
    slotSendToServer(number);
    if (endGame(number)) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Game Over!");

            msgBox.setText("U R WINNER!");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();

    }
    lockButtons();
   // }

}
