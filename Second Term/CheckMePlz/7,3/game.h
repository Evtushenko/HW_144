#pragma once
#include "field.h"
#include "QSpinBox"

int const defaultSize = 3;
int const maxSize = 10;

class Game : public QDialog
{
    Q_OBJECT

public:
    Game(QWidget *parent = NULL);

private:
    Field *currentField;
    QSpinBox sizeChanger;
    QPushButton exit;
    QVBoxLayout *menu;

private slots:
    /**
    @brief delete field and make new one
    */
    void doResize(int size);
    /**
    @brief find who is pressed and run checking for end of game
    */
    void findButton(QWidget *sender);
    /**
    @brief check out conditions for ending
    */
    bool endGame(int i, int j);
    /**
    @brief show message about the result of game
    */
    void showMsgs(const QString &name, const QString &txt);
};
