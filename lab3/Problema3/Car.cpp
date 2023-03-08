#include "Car.h"
#include <cstring>

const char* Car::get_color()
{
    return color;
}

void Car::set_color(const char* s)
{
    strcpy(color, s);
}



