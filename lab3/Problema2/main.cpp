#include <iostream>
#include "Canvas.h"
using namespace std;

int main()
{
    Canvas a(50, 50);
    a.DrawCircle(17, 25, 13, '*');
    a.Print();
    a.Clear();
    a.FillCircle(17, 25, 13, '*');
    a.Print();
    a.Clear();
    a.DrawRect(6, 39, 25, 7, '*');
    a.Print();
    a.Clear();
    a.FillRect(6, 39, 25, 7, '*');
    a.Print();
    a.Clear();
    a.SetPoint(6, 21, '*');
    a.Print();
    a.Clear();
    a.DrawLine(3, 4, 4, 30, '*');
    a.Print();
    a.Clear();
    return 0;
}