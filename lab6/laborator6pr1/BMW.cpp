#include "BMW.h"
#include "Weather.h"
#include "Car.h"
#include <cstring>

BMW::BMW() {
   // strcpy(name, "BMW");
    fuel_capacity = 600;
    fuel_consumption = 50;
    average_speed_sunny = 400;
    average_speed_rain = 100;
    average_speed_snow = 100; 
}