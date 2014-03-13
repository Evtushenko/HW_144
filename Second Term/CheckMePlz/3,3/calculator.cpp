#include "calculator.h"

Calculator::Calculator()
{
    firstUsing = true;
    allowDot = true;
    operation = 0;
    firstNumber = QString("");
    secondNumber = QString("");
}

QString Calculator::putNumber(int number) {
    if (firstUsing) {
        firstNumber.append(QString::number(number));
                return firstNumber;
    }
    else {
        secondNumber.append(QString::number(number));
                return secondNumber;
    }
}

QString Calculator::putResult(){
    double a = firstNumber.toDouble();
    double b = secondNumber.toDouble();
    switch(operation) {
        case 1:
            return QString::number(a+b);
        case 2:
            return QString::number(a-b);
        case 3:
            return QString::number(a*b);
        case 4:
            return QString::number(a/b);
        }
    return QString("");
}

QString Calculator::putOperation(int number){
    operation = number;
    firstUsing = false;
    allowDot = true;
    switch(number) {
        case 1:
            return QString("inc");
        case 2:
            return QString("dec");
        case 3:
            return QString("mul");
        case 4:
            return QString("div");
        }
    return QString("");
}

QString Calculator::putDot() {
    if (allowDot) {
        allowDot = false;
        if (firstUsing) {
            firstNumber.append(".");
            return firstNumber;
        }
        if (!firstUsing) {
            secondNumber.append(".");
            return secondNumber;
        }
    }
    else {
        if (firstUsing) {
            firstNumber.append("");
            return firstNumber;
        }
        if (!firstUsing) {
            secondNumber.append("");
            return secondNumber;
        }
    }
    return QString("");
}
