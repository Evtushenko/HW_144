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
#include <QSignalMapper>
#include <QMessageBox>

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(const int port, const int size, QWidget *parent = 0);

private:
    const int size;
    QPushButton **buttons;
    QHBoxLayout *columns;
    QVBoxLayout *menu;
    QSignalMapper *buttonMapper;

    void createButtons();
    int findNumber(QWidget *pressedButton);


    void lockButtons();
    void unlockButtons();
    void useTurn(int number);
    bool endGame(int number) {
        int i = number / size;
        int j = number % size;

        QString source(buttons[i][j].styleSheet());
            int count[4] = { 0 };

            // горизонтали
            for (int m = j + 1; m < size; m++)
                if (buttons[i][m].styleSheet() == source)
                    count[0]++;
            for (int m = 0; m < j; m++)
                if (buttons[i][m].styleSheet() == source)
                    count[0]++;

            // вертикали
            for (int m = i + 1; m < size; m++)
                if (buttons[m][j].styleSheet() == source)
                    count[1]++;
            for (int m = 0; m < i; m++)
                if (buttons[m][j].styleSheet() == source)
                    count[1]++;

            //И- диагональ
            if (j + i == (size -1)) {
                for (int m = j + 1; m < size; m++)
                    if (buttons[i-(m-j)][m].styleSheet() == source)
                        count[2]++;
                for (int m = 0; m < j; m++)
                    if (buttons[i-(m-j)][m].styleSheet() == source)
                        count[2]++;
            }

            // N = диагональ
            if (i == j) {
                for (int m = 0; m < j; m++ )
                    if (buttons[m][m].styleSheet() == source)
                        count[3]++;
                for (int m = j + 1; m < size; m++)
                    if (buttons[m][m].styleSheet() == source)
                        count[3]++;
            }

            return count[0] == size -1 || count[1] == size -1 || count[2] == size -1 || count[3] == size -1;
    }

    QTcpServer *myServer;
    QTextEdit *txtInfo;
    quint16 nextBlockSize;
    QTcpSocket *sender;

public slots:
    void sendToClient(int number);
    virtual void slotNewConnection();
    void slotReadClient();

    void queue(QWidget *pressedButton);
};
