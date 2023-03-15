#include <iostream>
#include "Sort.h"

int main()
{
    Sort a("10,2,34,54");
    //a.Print();
    //a.stalinSort(false); 
    a.BubbleSort(true);
    a.Print();
    return 0;
}