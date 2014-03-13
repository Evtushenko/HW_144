#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



        numbersMapper = new QSignalMapper(this);
        connect(ui->pushButton_10, SIGNAL(pressed()), numbersMapper, SLOT(map()));
        numbersMapper->setMapping(ui->pushButton_10, 0);
        connect(ui->pushButton_1, SIGNAL(pressed()), numbersMapper, SLOT(map()));
        numbersMapper->setMapping(ui->pushButton_1, 1);
        connect(ui->pushButton_2, SIGNAL(pressed()), numbersMapper, SLOT(map()));
        numbersMapper->setMapping(ui->pushButton_2, 2);
        connect(ui->pushButton_3, SIGNAL(pressed()), numbersMapper, SLOT(map()));
        numbersMapper->setMapping(ui->pushButton_3, 3);
        connect(ui->pushButton_4, SIGNAL(pressed()), numbersMapper, SLOT(map()));
        numbersMapper->setMapping(ui->pushButton_4, 4);
        connect(ui->pushButton_5, SIGNAL(pressed()), numbersMapper, SLOT(map()));
        numbersMapper->setMapping(ui->pushButton_5, 5);
        connect(ui->pushButton_6, SIGNAL(pressed()), numbersMapper, SLOT(map()));
        numbersMapper->setMapping(ui->pushButton_6, 6);
        connect(ui->pushButton_7, SIGNAL(pressed()), numbersMapper, SLOT(map()));
        numbersMapper->setMapping(ui->pushButton_7, 7);
        connect(ui->pushButton_8, SIGNAL(pressed()), numbersMapper, SLOT(map()));
        numbersMapper->setMapping(ui->pushButton_8, 8);
        connect(ui->pushButton_9, SIGNAL(pressed()), numbersMapper, SLOT(map()));
        numbersMapper->setMapping(ui->pushButton_9, 9);
        connect(numbersMapper, SIGNAL(mapped(int)), this, SLOT(digitClicked(int)));

        operatorMapper = new QSignalMapper(this);

        connect(ui->inc, SIGNAL(pressed()), operatorMapper, SLOT(map()));
        operatorMapper->setMapping(ui->inc, 0);
        connect(ui->dec, SIGNAL(pressed()), operatorMapper, SLOT(map()));
        operatorMapper->setMapping(ui->dec, 1);
        connect(ui->mul, SIGNAL(pressed()), operatorMapper, SLOT(map()));
        operatorMapper->setMapping(ui->mul, 2);
        connect(ui->div, SIGNAL(pressed()), operatorMapper, SLOT(map()));
        operatorMapper->setMapping(ui->div, 3);
        connect(operatorMapper, SIGNAL(mapped(int)), this, SLOT(operatorClicked(int)));




        connect(ui->dot, SIGNAL(clicked()), this, SLOT(dotClicked()));
        connect(ui->result, SIGNAL(clicked()), this, SLOT(resultClicked()));
        connect(ui->onStart, SIGNAL(clicked()), this, SLOT(defaultClicked()));
}

void MainWindow::digitClicked(const int number)
{
    ui->lineEdit->setText(calc.putNumber(number));
}

void MainWindow::dotClicked() {
    ui->lineEdit->setText(calc.putDot());
}

void MainWindow::operatorClicked(int const number){
    ui->lineEdit->setText(calc.putOperation(number+1));
}

void MainWindow::resultClicked() {
    ui->lineEdit->setText(calc.putResult());
}

void MainWindow::defaultClicked() {
    ui->lineEdit->setText("");
    Calculator one;
    calc = one;
}

MainWindow::~MainWindow()
{
    delete ui;
}
