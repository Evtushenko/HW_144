#include "field.h"

Field::Field(const int newSize, QWidget *parent) :
    QDialog(parent),
    size(newSize),
    buttons(new QPushButton *[size]),
    columns(new QHBoxLayout [size]),
    field(new QVBoxLayout(this)),
    mainWindow(new QVBoxLayout),
    buttonMapper(new QSignalMapper(this)),
    matrix(new int*[newSize])
{
    //create field
    matrix = new int*[newSize];
        for (int  i = 0; i < newSize; i++)
            matrix[i] = new int[newSize];

        for (int  i = 0; i < newSize; i++) // ввод
            for (int  j = 0; j < newSize; j++)
            {
                 matrix[i][j] = 0;
            }
        while(sum() != ((newSize*newSize)/2) ) {
            for (int  i = 0; i < newSize; i++) // ввод
                for (int  j = 0; j < newSize; j++)
                {
                     matrix[i][j] = rand() % 2;
                }
        }

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

    connect(buttonMapper, SIGNAL(mapped(QWidget *)), this, SIGNAL(pressed(QWidget *)));
    mainWindow = new QVBoxLayout;
    mainWindow->addWidget(this);
    setLayout(mainWindow);
}

Field::~Field() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            columns[i].removeWidget(&buttons[i][j]);
    mainWindow->removeWidget(this);
    delete[] columns;
    delete field;
    delete mainWindow;
    for (int i = 0; i < size; ++i) {
        delete[] buttons[i];
        delete[] matrix[i];
    }


}

void Field::createButtons() {
    for (int i = 0; i < size; ++i) {
        buttons[i] = new QPushButton [size];
    }

}

const char *Field::getDigit(int num) {
    switch ( num ) {
    case 0 :
        return "0";
    case 1 :
        return "1";
    case 2 :
        return "2";
    case 3 :
        return "3";
    case 4 :
        return "4";
    case 5 :
        return "5";
    case 6 :
        return "6";
    case 7 :
        return "7";
    case 8 :
        return "8";
    case 9 :
        return "9";
    }
    return "0";
}
