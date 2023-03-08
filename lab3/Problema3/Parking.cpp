#include "Parking.h"
#include "Parking-spot.h"
#include "Car.h"
#include <cstring>
#include <iostream>
using namespace std;

void Parking::init_park()
{
    for(int i = 1; i <= 100; i++)
    {
        x[i].busy = false;
        if(i % 3 == 1)
            strcpy(x[i].color, "albastru");
        else if(i % 3 == 2)
            strcpy(x[i].color, "rosu");
        else
            strcpy(x[i].color, "verde");
    }
}

void Parking::print_park()
{
    for (int i = 1; i <= 100; i++)
        cout << "Locul "<< i << " : " << x[i].busy << endl;
}

void Parking::add_car(Car c)
{
    bool ok = false;
    int i = 1;
    while (ok != true && i <= 100)
    {
        if (strcmp(x[i].color, c.get_color()) == 0 && x[i].busy == false)
        {
            x[i].busy = true;
            ok = true;
        }
        i++;
    }
}
