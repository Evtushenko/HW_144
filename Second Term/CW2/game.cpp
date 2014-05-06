#include "game.h"
#include <QLabel>
#include <QMessageBox>

Game::Game(QWidget *parent) :
    QDialog(parent),
    currentField(new Field(0)),
    menu(new QVBoxLayout)
{
    sizeChanger.setRange(0, maxSize);
    sizeChanger.setValue(0);
    exit.setText(tr("Exit"));

    //create interface
    menu->addWidget(&sizeChanger);
    menu->addWidget(&exit);

    QVBoxLayout *mainWindow = new QVBoxLayout;
    mainWindow->addLayout(menu);

    setLayout(mainWindow);

    //connects
    connect(&sizeChanger, SIGNAL(valueChanged(int)), this, SLOT(doResize(int)));
    connect(&exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(currentField, SIGNAL(pressed(QWidget *)), this, SLOT(findButton(QWidget *)));
}

void Game::doResize(int size)
{
    delete currentField;
    currentField = new Field(size);
    menu->addWidget(currentField);
    connect(currentField, SIGNAL(pressed(QWidget *)), this, SLOT(findButton(QWidget *))); //  rewrite
}

bool Game::endGame(int i, int j) {
    int static isEnd = 0;
    int static iLast = -1;
    int static jLast = -1;
    if (iLast + jLast == -2) {
        currentField->buttons[i][j].setText(currentField->getDigit(currentField->matrix[i][j]));
        currentField->buttons[i][j].setDisabled(true);
        iLast = i;
        jLast = j;
    }
    else {
        currentField->buttons[i][j].setText(currentField->getDigit(currentField->matrix[i][j]));
        currentField->buttons[i][j].setDisabled(true);
        if (currentField->matrix[i][j] == currentField->matrix[iLast][jLast]) {
            isEnd += 2;
        }
        else {
            currentField->buttons[i][j].setDisabled(false);
            currentField->buttons[iLast][jLast].setDisabled(false);
            currentField->buttons[iLast][jLast].setText("");
            currentField->buttons[i][j].setText("");

        }
        iLast = -1;
        jLast = -1;
    }
    if ( ( ( currentField->size % 2 == 0)  && (isEnd == currentField->size*currentField->size) )
        ||
     ( ( currentField->size % 2 == 1) && (isEnd == currentField->size*currentField->size -1) ) )
        return true;
    return false;
}

void Game::showMsgs(const QString &name, const QString &txt) {
    QMessageBox msgBox;
    msgBox.setWindowTitle(name);
    msgBox.setText(txt);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void Game::findButton(QWidget *sender) {
    for (int i = 0; i < currentField->size; ++i)
        for (int j = 0; j < currentField->size; ++j) {
            // i = столб j= строка
            if (sender == &currentField->buttons[i][j] && endGame(i,j)) {
                    showMsgs("Victory!", "I.C. Wiener\n");
                    currentField->setDisabled(true);
            }
        }
}
