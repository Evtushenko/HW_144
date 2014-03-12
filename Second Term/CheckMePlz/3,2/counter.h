#pragma once

/**
@brief class for calculating from GUI elements
*/
class Counter
{
public:
    /**
    @brief do one simple operation
    @param values from  QSpinBox (2) and value from QComboBox
    */
   double calculate(double first, double second, char operand);
};
