#include <iostream>
#include <limits>
#include "fun.h"

using namespace std;

int main()
{
    double a = inputDouble("Enter a double value: ");
    double b = inputDouble("Enter a double value: ");

    char key = inputChar("Enter one of the following (+, -, *, or /): ");

    double calcValue = calc(a, b, key);

    cout << a << " " << key << " " << b << " = " << calcValue << endl;

    system("pause");

    return 0;
}
