#include "Number.h"
#include <iostream>
using namespace std;

int main()
{
    Number n1("10", 10);
    Number n2("2", 10);
    Number n3("312", 10);
    cout << n3 << '\n';
    n1 = n2;
    n1.Print();
    cout << '\n';
    if (n1 >= n2)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
