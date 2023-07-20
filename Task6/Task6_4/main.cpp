#include <iostream>

using namespace std;

void printText(const char *text)
{
    for(;*text != '\0'; ++text)
        cout << *text;
}

int main()
{
    printText("Pizda");
    return 0;
}
