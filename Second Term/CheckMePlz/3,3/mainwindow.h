#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>
#include "calculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    /**
    @brief for buttons 0..9
    */
    QSignalMapper *numbersMapper;
    /**
    @brief for buttons + - * /
    */
    QSignalMapper *operatorMapper;
    Calculator calc;

private slots:
    /**
    @brief fuctions call their equals friends from Calculator
    */
    void digitClicked(int const number);
    void dotClicked();
    void operatorClicked(int const number);
    void resultClicked();
    void defaultClicked();
};

#endif // MAINWINDOW_H
