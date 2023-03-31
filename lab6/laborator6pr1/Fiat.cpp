#include "Fiat.h"
#include "Weather.h"
#include "Car.h"
#include <cstring>

Fiat::Fiat() {
    //strcpy(name, "Fiat");
    fuel_capacity = 300;
    fuel_consumption = 40;
    average_speed_sunny = 300;
    average_speed_rain = 200;
    average_speed_snow = 190; 
}