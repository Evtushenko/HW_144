#include "calculator.h"

Calculator::Calculator()
{
    firstUsing = true;
    allowDot = true;
    operation = zero;
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
        case inc:
            return QString::number(a+b);
        case dec:
            return QString::number(a-b);
        case mul:
            return QString::number(a*b);
        case div:
            return QString::number(a/b);
        }
    return QString("");
}

QString Calculator::putOperation(int number){
    operation = number;
    firstUsing = false;
    allowDot = true;
    switch(number) {
        case inc:
            return QString("inc");
        case dec:
            return QString("dec");
        case mul:
            return QString("mul");
        case div:
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
