#include "Math.h"
#include <iostream>
using namespace std;

int main()
{
    Math a;
    cout << a.Add(2, 4) << '\n' << a.Add(3.54, 234.345) << '\n';
    cout << a.Add("Ana", "Maria") << '\n';
    cout << a.Add(3, 1, 2, 3);
    return 0;
}