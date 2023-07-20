#include <iostream>
#include "fun.h"

using namespace std;

int main()
{
    int a = readNumber();
    int b = readNumber();

    writeNumber(a + b);

    std::system("pause");

    return 0;
}
