#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "counter.h"

namespace Ui {
class MainWindow;
}

/**
@brief class for bulding interface
@detailed has own signal for calculating
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    /**
    @brief takes changes from interface; calls calculator; puts relult in interface
    */
    void setValue();

private:
    /**
    @brief variable of Counter class
    */
    Counter calc;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
