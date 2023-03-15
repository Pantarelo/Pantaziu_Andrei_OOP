//#pragma once

class Sort
{
    int* array;
    int nr;
public:
    Sort(int n, int mini, int maxi);
    Sort(int n, int v[]);
    Sort(int count,...);
    Sort(const char* s);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascentent = false);
    void BubbleSort(bool ascendent = false);
    void stalinSort(bool ascendent = false);
    void bogoSort(bool ascendent = false);
    void quantumBogoSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
}; 