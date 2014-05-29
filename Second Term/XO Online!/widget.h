#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QSignalMapper>
#include <QMessageBox>


class Server;
class Client;

class Widget : public QWidget
{
    Q_OBJECT
    friend class Server;
    friend class Client;
public:
    explicit Widget(int const size, QString color1, QString color2, QWidget *parent = 0);
    ~Widget()
    {
        for (int i = 0; i < size; ++i)
              for (int j = 0; j < size; ++j)
                  columns[i].removeWidget(&buttons[i][j]);
        for (int i = 0; i < size; i++)
            delete[] buttons[i];
        delete buttonMapper;
        delete menu;
    }
public slots:

private:
    const int size;
    QPushButton **buttons;
    QHBoxLayout *columns;
    QSignalMapper *buttonMapper;
    QVBoxLayout * menu;
    QString myColor;
    QString yourColor;
    int amountMoves;

    void createButtons();
    int findNumber(QWidget *pressedButton);
    bool endGame(int number);

    void lockButtons();
    void unlockButtons();
    void useTurn(int number);

private slots:
    void queue(QWidget *pressedButton);
signals:
    void sendNumber(int number);

};

#endif // WIDGET_H
