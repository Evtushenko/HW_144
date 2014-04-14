#include "game.h"
#include <QLabel>
#include <iostream>

Game::Game(QWidget *parent) :
    QDialog(parent),
    currentField(new Field(defaultSize)),
    menu(new QVBoxLayout) {
    sizeChanger.setRange(defaultSize, maxSize);
    sizeChanger.setValue(defaultSize);
    exit.setText(tr("Exit"));

    //create interface
    menu->addWidget(&sizeChanger);
    menu->addWidget(&exit);

    QVBoxLayout *mainWindow = new QVBoxLayout;
    mainWindow->addLayout(menu);
    mainWindow->addWidget(currentField);

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
    int size = currentField->size;
    if ( ( (j < size - 1) && (currentField->buttons[i][j+1].styleSheet() == currentField->buttons[i][j].styleSheet() )
            && (j > 0) && (currentField->buttons[i][j-1].styleSheet() == currentField->buttons[i][j].styleSheet() ) )

    ||
     ( (i < size - 1) && (currentField->buttons[i+1][j].styleSheet() == currentField->buttons[i][j].styleSheet() )
            && (i > 0) && (currentField->buttons[i-1][j].styleSheet() == currentField->buttons[i][j].styleSheet() ) )

    ||
    ( (j < size -2) && (currentField->buttons[i][j+1].styleSheet() == currentField->buttons[i][j].styleSheet() )
    && (currentField->buttons[i][j+2].styleSheet() == currentField->buttons[i][j].styleSheet()) )

    ||
    ( (j > 1) && (currentField->buttons[i][j-1].styleSheet() == currentField->buttons[i][j].styleSheet() )
    && (currentField->buttons[i][j-2].styleSheet() == currentField->buttons[i][j].styleSheet()) )

    ||
    ( (i < size -2) && (currentField->buttons[i+1][j].styleSheet() == currentField->buttons[i][j].styleSheet() )
    && (currentField->buttons[i+2][j].styleSheet() == currentField->buttons[i][j].styleSheet()) )

    ||
    ( (i > 1) && (currentField->buttons[i-1][j].styleSheet() == currentField->buttons[i][j].styleSheet() )
    && (currentField->buttons[i-2][j].styleSheet() == currentField->buttons[i][j].styleSheet()) )

    ||
    ( ( i < size -1) && ( j > 0) && (j < size -1) && (i > 0) &&
         currentField->buttons[i+1][j-1].styleSheet() == currentField->buttons[i][j].styleSheet() &&
         currentField->buttons[i-1][j+1].styleSheet() == currentField->buttons[i][j].styleSheet() )

    ||
    ( (i < size -1) && (i > 0) && ( j > 0) && (j < size -1) &&
         currentField->buttons[i+1][j+1].styleSheet() == currentField->buttons[i][j].styleSheet() &&
         currentField->buttons[i-1][j-1].styleSheet() == currentField->buttons[i][j].styleSheet() )

    ||
    ( (i < size -2) && (j < size -2) &&
         currentField->buttons[i+1][j+1].styleSheet() == currentField->buttons[i][j].styleSheet() &&
         currentField->buttons[i+2][j+2].styleSheet() == currentField->buttons[i][j].styleSheet() )

    ||
    ( (i > 1) && (j >1) &&
         currentField->buttons[i-1][j-1].styleSheet() == currentField->buttons[i][j].styleSheet() &&
         currentField->buttons[i-2][j-2].styleSheet() == currentField->buttons[i][j].styleSheet() )

    ||
    ( (i < size -2) && (j >1) &&
         currentField->buttons[i+1][j-1].styleSheet() == currentField->buttons[i][j].styleSheet() &&
         currentField->buttons[i+2][j-2].styleSheet() == currentField->buttons[i][j].styleSheet() )

    ||
    ( (i > 1) && (j < size -2) &&
         currentField->buttons[i-1][j+1].styleSheet() == currentField->buttons[i][j].styleSheet() &&
         currentField->buttons[i-2][j+2].styleSheet() == currentField->buttons[i][j].styleSheet() ) )
        return true;
    return false;
}

void Game::findButton(QWidget *sender) {
    int static counter = 0;
    counter++;
    bool victory = false;
    for (int i = 0; i < currentField->size; ++i)
        for (int j = 0; j < currentField->size; ++j) {
            // i = столб j= строка 
            if (sender == &currentField->buttons[i][j] && endGame(i,j)) {
                    QLabel *win = new QLabel(tr("<h1>I.C. Wiener</h1>"));
                    win->show();
                    victory = true;
                    currentField->setDisabled(true);
            }
        }

     if (counter == currentField->size * currentField->size && !victory) {
         QLabel *draw = new QLabel(tr("<h1>No one is I.C. Wiener</h1>"));
         draw->show();
     }
}
