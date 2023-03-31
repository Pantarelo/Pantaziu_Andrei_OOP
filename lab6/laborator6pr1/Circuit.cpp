#include "Circuit.h"
#include "Car.h"
#include "Weather.h"
#include <algorithm>
#include <iostream>
using namespace std;

void Circuit::SetLength(int lenght) {
    this -> _length = lenght;
}

void Circuit::SetWeather(Weather weather) {
    this -> _weather = weather;
}

void Circuit::AddCar(Car* car) {
    _car.push_back(car);
}

void Circuit::Race() {
    vector<int> _time(_car.size());
    for (int i = 0; i < _car.size(); i++) {
        int flue = this -> _car[i] -> fuel_capacity;
        int consumption = this -> _car[i] -> fuel_consumption;
        int speed;
        switch (_weather) {
            case 0:
                speed = _car[i] -> average_speed_sunny;
                break;
            case 1:
                speed = _car[i] -> average_speed_rain;
                break;
            case 2:
                speed = _car[i] -> average_speed_snow; 
                break;
        }
        int time = _length / speed;
        while (flue > 0 && time > 0) {
            flue -= consumption;
            time -= 100;
        }
        if (flue <= 0)
            _time[i] = -1;
        else 
            _time[i] = time;
    }  
    /*sort(_time.begin(), _time.end());
    for (int i = 0; i < _car.size(); i++)
    {
        cout << "Masina " << i + 1 << " a terminat cursa ";
        if (_time[i] >= 0)
            cout << _time[i] << '\n';
    }  */
    cout << _car[0] -> name << '\n';
    for (int i = 0; i < _car.size(); i++) {
        if (_time[i] == -1) 
            cout << "masina " << i + 1 << " nu a terminat cursa" << '\n';
        else
            cout << "masina " << i + 1 << " a terminat cursa in " << _time[i] << " minute" << '\n';
    } 
}

void Circuit::ShowFinalRanks() {
    
}
