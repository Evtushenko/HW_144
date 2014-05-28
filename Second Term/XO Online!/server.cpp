#include "server.h"

Server::Server(const int port, const int size, QWidget *parent) :
    QWidget(parent),
    size(size),
    buttons(new QPushButton *[size]),
    columns(new QHBoxLayout [size]),
    menu(new QVBoxLayout(this)),
    buttonMapper(new QSignalMapper(this)),
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
    txtInfo->setReadOnly(true);

    menu->addWidget(new QLabel("<H1>Server</H1>"));
    menu->addWidget(txtInfo);

    createButtons();
}

int Server::findNumber(QWidget *pressedButton) {
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

void Server::lockButtons() {
    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size; j++)
            buttons[i][j].setEnabled(false);
}

void Server::unlockButtons() {
    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size; j++) {
            if (buttons[i][j].styleSheet() != QString("background-color:green") && buttons[i][j].styleSheet() != QString("background-color:blue") )
                buttons[i][j].setEnabled(true);
        }
}

void Server::useTurn(int number)
{
    int i = number / size;
    int j = number % size;
    buttons[i][j].setStyleSheet("background-color:green");
    buttons[i][j].setDisabled(true);
    if (endGame(number)) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Game Over!");
            msgBox.setText("U R LOSER!");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
    }

}

void Server::queue(QWidget *pressedButton)
{
    pressedButton->setStyleSheet("background-color:blue");
    pressedButton->setDisabled(true);
    int number = findNumber(pressedButton);
    sendToClient(number);
    if (endGame(number)) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Game Over!");
            msgBox.setText("U R WINNER!");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
    }
}

void Server::createButtons()
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
    lockButtons();
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
    useTurn(str.toInt());
    unlockButtons();
}
