#include <iostream>
#include "fun.h"

using namespace std;

int main()
{
    double height;
    cin >> height;

    double real_height = 0;
    for(int time = 0; ; time++)
    {
        real_height = calc_acceleration_height(height, time);

        if(real_height <= 0)
        {
           outputOnTheGround(time);
            break;
        }

        outputOnTheFly(real_height, time);
    };

    system("pause");

    return 0;
}
