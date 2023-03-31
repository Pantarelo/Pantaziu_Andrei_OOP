#include "RangeRover.h"
#include "Weather.h"
#include "Car.h"
#include <cstring>

RangeRover::RangeRover(char nume[]) {
    strcpy(name,nume);
    fuel_capacity = 400;
    fuel_consumption = 20;
    average_speed_sunny = 100;
    average_speed_rain = 60;
    average_speed_snow = 70; 
}

void RangeRover::getName(char nume[]) {
    strcpy(name, nume);
}
