#include "widget.h"

Widget::Widget(int const size, QString color1, QString color2, QWidget *parent) :
    QWidget(parent),
    size(size),
    buttons(new QPushButton *[size]),
    columns(new QHBoxLayout [size]),
    buttonMapper(new QSignalMapper(this)),
    menu(new QVBoxLayout),
    myColor(color1),
    yourColor(color2),
    amountMoves(0)
{
    createButtons();
}


void Widget::createButtons() {
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

int Widget::findNumber(QWidget *pressedButton) {
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

bool Widget::endGame(int number) {
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

void Widget::lockButtons()
{
    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size; j++)
            buttons[i][j].setEnabled(false);
}

void Widget::unlockButtons()
{
    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size; j++) {
            if (buttons[i][j].styleSheet() != QString("background-color:"+myColor) &&
                    buttons[i][j].styleSheet() != QString("background-color:"+yourColor) )
                buttons[i][j].setEnabled(true);
        }
}

void Widget::useTurn(int number) {
    amountMoves++;
    int i = number / size;
    int j = number % size;
    buttons[i][j].setStyleSheet("background-color:"+yourColor);
    buttons[i][j].setDisabled(true);
    if (endGame(number) || amountMoves == size * size) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Game Over!");
        if (amountMoves < size * size )
            msgBox.setText("U R LOSER!");
        else
            msgBox.setText("FRIENSHIP!");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}

void Widget::queue(QWidget *pressedButton) {
    amountMoves++;
    pressedButton->setStyleSheet("background-color:"+myColor);
    pressedButton->setDisabled(true);
    int number = findNumber(pressedButton);
    emit sendNumber(number);
    if (endGame(number) || amountMoves == size * size) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Game Over!");
        if (amountMoves < size * size )
            msgBox.setText("U R WINNER!");
        else
            msgBox.setText("FRIENSHIP!");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();

    }
    lockButtons();
}
