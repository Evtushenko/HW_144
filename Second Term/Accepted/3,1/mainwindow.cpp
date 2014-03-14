#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->verticalScrollBar, SIGNAL(sliderMoved(int)), ui->horizontalSlider, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}