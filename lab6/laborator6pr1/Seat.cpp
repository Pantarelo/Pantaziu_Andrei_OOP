#include "Seat.h"
#include "Weather.h"
#include "Car.h"
#include <cstring>

Seat::Seat() {
    //strcpy(name, "Seat");
    fuel_capacity = 500;
    fuel_consumption = 10;
    average_speed_sunny = 150;
    average_speed_rain = 80;
    average_speed_snow = 70; 
}