#include "Car.h"
#include "Parking-spot.h"
#include "Parking.h"
using namespace std;

int main()
{
    Car c1, c2, c3, c4;
    Parking p;
    c1.set_color("albastru");
    c2.set_color("rosu");
    c3.set_color("rosu");
    c4.set_color("verde");
    p.init_park();
    p.add_car(c1);
    p.add_car(c2);
    p.add_car(c3);
    p.add_car(c4);
    p.print_park();
    return 0;
}