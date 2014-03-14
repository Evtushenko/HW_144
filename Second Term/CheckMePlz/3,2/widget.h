#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFont>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QString>
#include <QLineEdit>
#include "counter.h"


/**
@brief class for bulding interface
@detailed has own signal for calculating
*/
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    /**
    @brief deleting 4 points to interface classes
    */
    ~Widget();

private slots:
    /**
    @brief takes changes from interface; calls calculator; puts relult in interface
    */
    void setValue();

private:
    Counter calc;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QSpinBox *spinBox2;
    QLineEdit *lineEdit;
};

#endif // WIDGET_H
