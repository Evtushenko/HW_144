#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->setFont(QFont("Times", 18, QFont::Bold));
    ui->comboBox->addItem("+");
    ui->comboBox->addItem("-");
    ui->comboBox->addItem("*");
    ui->comboBox->addItem("/");

    ui->spinBox->setFont(QFont("Times", 18, QFont::Bold));
    ui->spinBox->setMinimum(0);
    ui->spinBox->setMaximum(9);

    ui->spinBox_2->setMinimum(0);
    ui->spinBox_2->setMaximum(9);
    ui->spinBox_2->setFont(QFont("Times", 18, QFont::Bold));

    ui->lineEdit->setFont(QFont("Times", 18, QFont::Bold));

    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(setValue()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(setValue()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setValue()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setValue()
{
   double first = ui->spinBox->text().toDouble();
   double second = ui->spinBox_2->text().toDouble();

   char operand = (char)ui->comboBox->currentText().toStdString()[0];

   QString result = QString::number(calc.calculate(first, second, operand));

   ui->lineEdit->setText(result);
}
