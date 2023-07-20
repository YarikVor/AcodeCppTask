#pragma once

#include <iostream>

#include "fun.h"
#include "constants.h"

double calc_acceleration_height(double height, double time)
{
    return height - gravity_earth * time * time / 2;
}

void outputOnTheGround(double time)
{
    std::cout << "At " << time << " seconds, the ball is on the ground." << std::endl;
}

void outputOnTheFly(double height, double time)
{
    std::cout << "At " << time << " seconds, the ball is at height: " << height << " meters" << std::endl;
}
