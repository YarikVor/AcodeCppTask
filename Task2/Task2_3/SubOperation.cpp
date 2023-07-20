#include "SubOperation.h"

float SubOperation::action(float a, float b)
{
    return a - b;
}

char SubOperation::get_key()
{
    return '-';
}
