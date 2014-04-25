#include "field.h"

Field::Field(int newSize, QWidget *parent) :
    QDialog(parent),
    size(newSize),
    buttons(new QPushButton *[size]),
    columns(new QHBoxLayout [size]),
    field(new QVBoxLayout(this)),
    mainWindow(new QVBoxLayout),
    buttonMapper(new QSignalMapper(this))
{
    //create field
    createButtons();

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            columns[i].addWidget(&buttons[i][j]);


    for (int i = 0; i < size; ++i)
        field->addLayout(&columns[i]);


    //connects

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            buttonMapper->setMapping(&buttons[i][j], &buttons[i][j]);

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            connect(&buttons[i][j], SIGNAL(clicked()), buttonMapper, SLOT(map()));

    connect(buttonMapper, SIGNAL(mapped(QWidget *)), this, SLOT(queue(QWidget *)));
    mainWindow = new QVBoxLayout;
    mainWindow->addWidget(this);
    setLayout(mainWindow);
}

Field::~Field() {
    //delete field;
    //delete mainWindow;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            columns[i].removeWidget(&buttons[i][j]);
    mainWindow->removeWidget(this);
    delete[] columns;
    delete field;
    delete mainWindow;
    for (int i = 0; i < size; ++i)
        delete[] buttons[i];


}

void Field::createButtons() {
    for (int i = 0; i < size; ++i) {
        buttons[i] = new QPushButton [size];
        for (int j = 0; j < size; ++j)
            buttons[i][j].setText(tr("\0"));
    }
}

void Field::queue(QWidget *pressedButton) {
    static bool firstTurn = true;

    if (firstTurn) {
        pressedButton->setStyleSheet("background-color:yellow");
        pressedButton->setDisabled(true);
        firstTurn = false;
    }
    else {
        pressedButton->setStyleSheet("background-color:red");
        pressedButton->setDisabled(true);
        firstTurn = true;
    }

    emit pressed(pressedButton);
}
