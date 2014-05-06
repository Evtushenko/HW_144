#pragma once
#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QSignalMapper>

/**
@brief class for working with buttons
*/
class Field : public QDialog
{
    Q_OBJECT
    friend class Game;

public:
    Field(const int colCells, QWidget *parent = NULL);
    ~Field();

private:
    /**
    @brief size of game field
    */
    int size;
    /**
    @brief double array
    */
    QPushButton **buttons;
    void createButtons();
    QHBoxLayout *columns;
    QVBoxLayout *field;
    QVBoxLayout *mainWindow;
    QSignalMapper *buttonMapper;
    int** matrix;
    char const *getDigit(int num);
    int sum() {
        int r = 0;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                r += matrix[i][j];
        return r;
    }

signals:
    void pressed(QWidget *);
};
