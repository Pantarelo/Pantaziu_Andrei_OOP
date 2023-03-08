#include "Parking-spot.h"
#include "Car.h"

class Parking
{
    Parking_spot x[101];
    public:
        void add_car(Car c);
        void init_park();
        void print_park();
};