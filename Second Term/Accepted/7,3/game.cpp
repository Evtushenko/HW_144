#include "game.h"
#include <QLabel>
#include <QMessageBox>

Game::Game(QWidget *parent) :
    QDialog(parent),
    currentField(new Field(0)),
    menu(new QVBoxLayout) {
    sizeChanger.setRange(0, maxSize);
    sizeChanger.setValue(0);
    exit.setText(tr("Exit"));

    //create interface
    menu->addWidget(&sizeChanger);
    menu->addWidget(&exit);

    QVBoxLayout *mainWindow = new QVBoxLayout;
    mainWindow->addLayout(menu);
    //mainWindow->addWidget(currentField);

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
    QString source(currentField->buttons[i][j].styleSheet());
    int count[4] = { 0 };

    // горизонтали
    for (int m = j + 1; m < size; m++)
        if (currentField->buttons[i][m].styleSheet() == source)
            count[0]++;
    for (int m = 0; m < j; m++)
        if (currentField->buttons[i][m].styleSheet() == source)
            count[0]++;

    // вертикали
    for (int m = i + 1; m < size; m++)
        if (currentField->buttons[m][j].styleSheet() == source)
            count[1]++;
    for (int m = 0; m < i; m++)
        if (currentField->buttons[m][j].styleSheet() == source)
            count[1]++;

    //И- диагональ
    if (j + i == (size -1)) {
        for (int m = j + 1; m < size; m++)
            if (currentField->buttons[i-(m-j)][m].styleSheet() == source)
                count[2]++;
        for (int m = 0; m < j; m++)
            if (currentField->buttons[i-(m-j)][m].styleSheet() == source)
                count[2]++;
    }

    // N = диагональ
    if (i == j) {
        for (int m = 0; m < j; m++ )
            if (currentField->buttons[m][m].styleSheet() == source)
                count[3]++;
        for (int m = j + 1; m < size; m++)
            if (currentField->buttons[m][m].styleSheet() == source)
                count[3]++;
    }

    return count[0] == size -1 || count[1] == size -1 || count[2] == size -1 || count[3] == size -1;
}

void Game::showMsgs(const QString &name, const QString &txt) {
    QMessageBox msgBox;
    msgBox.setWindowTitle(name);
    msgBox.setText(txt);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void Game::findButton(QWidget *sender) {
    int static counter = 0;
    counter++;
    bool victory = false;
    for (int i = 0; i < currentField->size; ++i)
        for (int j = 0; j < currentField->size; ++j) {
            // i = столб j= строка
            if (sender == &currentField->buttons[i][j] && endGame(i,j)) {
                    showMsgs("Victory!", "I.C. Wiener\n");
                    victory = true;
                    currentField->setDisabled(true);
            }
        }

     if (counter == currentField->size * currentField->size && !victory) {
         showMsgs("Friendship", "No one is I.C.Wiener\n");
     }
}
