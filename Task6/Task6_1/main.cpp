#include <iostream>

using namespace std;

int sum(int array[], int length)
{
    int sum = 0;
    for(int i = 0; i < length; ++i)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
    int array[] {3, 6, 12};
    int length = sizeof(array) / sizeof(array[0]);

    int sumValue = sum(array, length);

    cout << sumValue << endl;

    system("pause");

    return 0;
}
