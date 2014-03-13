#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QString>

/**
@brief class for storing numbers, operations, state of dot and do one operation in the end
*/
class Calculator
{
public:
    Calculator();
//private slots:
    /**
    @brief put one digit in the end of string (first or second)
    @param one digit form user's interface keyboad
    */
    QString putNumber(int number);
    /**
    @brief decided put dot or dont
    */
    QString putDot();
    /**
    @brief take a number of operation for storing
    */
    QString putOperation(int number);
    /**
    @brief calculate 2 numbers
    */
    QString putResult();
private:
    QString firstNumber;
    QString secondNumber;
    /**
    @brief switch 1 or 2 number using
    */
    bool firstUsing;
    /**
    @brief was a dot here?
    */
    bool allowDot;
    int operation;
};

#endif // CALCULATOR_H
