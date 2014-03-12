#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    comboBox = new QComboBox;
    comboBox->setFont(QFont("Times", 18, QFont::Bold));
    comboBox->addItem("+");
    comboBox->addItem("-");
    comboBox->addItem("*");
    comboBox->addItem("/");

    spinBox = new QSpinBox;
    spinBox->setFont(QFont("Times", 18, QFont::Bold));
    spinBox->setMinimum(0);
    spinBox->setMaximum(9);

    spinBox2 = new QSpinBox;
    spinBox2->setMinimum(0);
    spinBox2->setMaximum(9);
    spinBox2->setFont(QFont("Times", 18, QFont::Bold));

    lineEdit = new QLineEdit;
    lineEdit->setFont(QFont("Times", 18, QFont::Bold));

    QGridLayout *grid = new QGridLayout;
    grid->addWidget(spinBox, 0, 0);
    grid->addWidget(comboBox, 0, 1);
    grid->addWidget(spinBox2, 0, 2);
    grid->addWidget(lineEdit, 0, 3);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(grid);
    setLayout(layout);

    connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(setValue()));
    connect(spinBox2, SIGNAL(valueChanged(int)), this, SLOT(setValue()));
    connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setValue()));
}

Widget::~Widget()
{
    delete comboBox;
    delete spinBox;
    delete spinBox2;
    delete lineEdit;
}

void Widget::setValue()
{
    double first = spinBox->text().toDouble();
    double second = spinBox2->text().toDouble();

    char operand = (char)comboBox->currentText().toStdString()[0];

    QString result = QString::number(calc.calculate(first, second, operand));

    lineEdit->setText(result);
}
