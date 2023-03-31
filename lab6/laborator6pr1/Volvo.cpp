#include "Volvo.h"
#include "Weather.h"
#include "Car.h"
#include <cstring>

Volvo::Volvo() {
    //strcpy(name, "Volvo");
    fuel_capacity = 800;
    fuel_consumption = 10;
    average_speed_sunny = 100;
    average_speed_rain = 60;
    average_speed_snow = 70; 
}
