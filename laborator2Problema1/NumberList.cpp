#include <iostream>
#include "NumberList.h"
using namespace std;

int dinamicArray()
{
    int* dinamic = new int[this -> count + 1];
    for (int i = 0; i < count; i++)
        dinamic[i] = this -> numbers[i];
    delete this->numbers;
    return dinamic;
}

void NumberList::Init()
{
    count = 0;
}

bool NumberList::Add(int x)
{
    numbers.dinamicArray();
    if (count >= 10)
        return false;
    numbers[count] = x;
    //count++;
    //numbers.dinamicArray();
    return true;
}

void NumberList::Sort()
{
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++)
            if (numbers[i] > numbers[j])
                swap(numbers[i], numbers[j]);
}

void NumberList::Print()
{
    for (int i = 0; i <= count; i++)
        cout << numbers[i] << " ";
}