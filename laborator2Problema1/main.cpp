#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
    NumberList list;
    list.Init();
    list.Add(32);
    list.Add(71);
    list.Add(2);
    list.Add(12342);
    list.Add(-321);
    //list.Add(23);
    list.Print();
    list.Sort();
    cout << '\n';
    list.Print();
    return 0;
}