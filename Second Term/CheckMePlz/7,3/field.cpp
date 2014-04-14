#include "field.h"

Field::Field(int newSize, QWidget *parent) :
    QDialog(parent),
    size(newSize),
    //testNumber(0),
    buttons(new QPushButton *[size]) {
    //create field
    createButtons();

    QHBoxLayout *columns = new QHBoxLayout [size];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            columns[i].addWidget(&buttons[i][j]);

    QVBoxLayout *field = new QVBoxLayout;
    for (int i = 0; i < size; ++i)
        field->addLayout(&columns[i]);

    setLayout(field);

    //connects
    QSignalMapper *buttonMapper = new QSignalMapper(this);

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            buttonMapper->setMapping(&buttons[i][j], &buttons[i][j]);

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            connect(&buttons[i][j], SIGNAL(clicked()), buttonMapper, SLOT(map()));

    connect(buttonMapper, SIGNAL(mapped(QWidget *)), this, SLOT(queue(QWidget *)));
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
        pressedButton->setStyleSheet("background-image: url(X.bmp)");
        pressedButton->setDisabled(true);
        firstTurn = false;
    }
    else {
        pressedButton->setStyleSheet("background-image: url(O.bmp)");
        pressedButton->setDisabled(true);
        firstTurn = true;
    }

    emit pressed(pressedButton);
}
