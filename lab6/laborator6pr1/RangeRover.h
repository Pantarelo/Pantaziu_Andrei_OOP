#include "Car.h"
#include "Weather.h"

class RangeRover : public Car {
        char name[101];
    public:
        RangeRover(char nume[]);
        void getName(char nume[]);
};
