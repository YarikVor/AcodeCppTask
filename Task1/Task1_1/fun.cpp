#pragma once

#include <iostream>

int readNumber()
{
    int result;
    std::cin >> result;
    return result;
}

void writeNumber(int value)
{
    std::cout << value;
}
