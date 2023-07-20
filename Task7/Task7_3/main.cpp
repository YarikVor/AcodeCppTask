#include <iostream>



int binaryIndexOf(int* array, int len, int value)
{
    int min = 0;
    int max = len - 1;
    while(min <= max)
    {
        int middle = (min + max) / 2;
        int resValue = array[middle];
        if(resValue == value)
        {
            return middle;
        }
        else if(resValue < value)
        {
            min = middle + 1;
        }
        else
        {
            max = middle - 1;
        }
    }
    return -1;
}



int binaryIndexOfRecursion(int* array, int min, int max, int value)
{
    if(min > max)
        return -1;

    int middle = (min + max) / 2;
    int resValue = array[middle];
    if(resValue == value)
        return middle;
    if(resValue < value)
        return binaryIndexOfRecursion(array, min + 1, max, value);
    return binaryIndexOfRecursion(array, min, max - 1, value);

}

int binaryIndexOfRecursion(int* array, int len, int value)
{
    return binaryIndexOfRecursion(array, 0, len - 1, value);
}

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int index = binaryIndexOfRecursion(arr, 6, 9);
    cout << index << endl;
    return 0;
}
