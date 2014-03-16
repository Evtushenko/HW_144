#include "counter.h"

double Counter::calculate(double first, double second, char operand)
{
    switch(operand) {
    case '+':
        return first + second;
    case '-':
        return first - second;
    case '*':
        return first*second;
    case '/':
        return first/second;
    }
    return 0;
}
