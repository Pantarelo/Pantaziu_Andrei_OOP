#include "Weather.h"
#include "Car.h"
#include <vector>
using namespace std;

class Circuit {
    private:
        int _length;
        Weather _weather = Sunny;
        vector<Car*> _car;
    public:
        Circuit() {};
        void SetLength(int length);
        void SetWeather(Weather weather);
        void AddCar(Car* car);
        void Race();
        void ShowFinalRanks();
        //void ShowWhoDidNotFinish();
};