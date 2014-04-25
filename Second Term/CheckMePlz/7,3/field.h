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
    Field(int colCells, QWidget *parent = NULL);
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
signals:
    void pressed(QWidget *);
private slots:
    /**
    @brief manage X or O
    */
    void queue(QWidget *pressedButton);
};
