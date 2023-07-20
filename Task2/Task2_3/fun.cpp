#include "fun.h"

double inputDouble(const char* str)
{
    cout << str;
    double result;
    cin >> result;
    return result;
}

char inputChar(const char* str)
{
    cout << str;
    char result;
    cin >> result;
    return result;
}

double calc(double a, double b, char operation)
{
    switch(operation)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return numeric_limits<double>::quiet_NaN();
    }
}
