#include "Sort.h"
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <stdarg.h>
using namespace std;

Sort::Sort(int n, int mini, int maxi)
{
    nr = n;
    array = new int[nr];
    for (int i = 0; i < n; i++)
    {
        int random = rand() % (maxi - mini + 1);
        array[i] = random;
    }
}

Sort::Sort(int n, int v[])
{
    nr = n;
    array = new int[nr];
    for (int i = 0; i < n; i++)
        array[i] = v[i];
}

Sort::Sort(int count, ...)
{
    nr = count;
    array = new int[nr];
    va_list v;
    va_start (v, count);
    for (int i = 0; i < count; i++)
        array[i] = va_arg(v, int);
    va_end(v);
}

Sort::Sort(const char* s)
{
    int n = 0, b[101];
    char a[101];
    strcpy(a, s);
    char sep[] = ",";
    char* p = strtok(a, sep);
    while (p)
    {
        b[n] = atoi(p);
        n = n + 1;
        p = strtok(NULL, ",");
    }
    nr = n;
    array = new int[nr];
    for (int i = 0; i < nr; i++)
        array[i] = b[i];
}

void Sort::InsertSort(bool ascendent)
{
    for (int i = 0; i < nr; i++)
    {
        int x = array[i];
        int p = i - 1;
        while (p >= 0 && ((array[p] > x && ascendent) || (array[p] < x && !ascendent)))
        {
            array[p + 1] = array[p];
            p = p - 1;
        }
        array[p + 1] = x;
    }
}

void Sort::QuickSort(bool ascendent)
{
    if (nr <= 1)
        return;
    int pivot = array[nr / 2];
    int i = 0, j = nr - 1;
    while (i <= j)
    {
        while ((array[i] < pivot && ascendent) || (array[i] > pivot && !ascendent))
            i++;
        while ((array[j] > pivot && ascendent) || (array[j] < pivot && !ascendent))
            j--;
        if (i <= j)
        {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }  
    Sort a(i, array);
    Sort b(nr - i, array + i);
    a.QuickSort(ascendent);
    b.QuickSort(ascendent);  
}

void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < nr - 1; i++)
        for (int j = i + 1; j < nr; j++)
           if ((ascendent && array[i] > array[j]) || (!ascendent && array[i] < array[j]))
            //if (array[i] < array[j] + ascendent == 1)
                swap(array[i], array[j]);
}

void Sort::stalinSort(bool ascendent)
{
    if (ascendent == true)
    {
        int i = 0;
        while (i < nr)
        {
            if (array[i] > array[i + 1])
            {
                for (int i = 0; i < nr - 1; i++)
                    array[i] = array[i + 1];
                nr--;
            }
            i++;
        }
    }
    else
    {
        int i = nr - 1;
        while (i >= 0)
        {
            for (int j = 0; j < nr; j++)
                cout << array[j] << " ";
            cout << endl;
            if (array[i] < array[i - 1])
            {
                for (int j = i - 1; j < nr - 1; j++)
                    array[j] = array[j + 1];
                nr--;
            }
            i--;
        }
    }
}

void Sort::bogoSort(bool ascendent)
{
    int random1 = rand() % nr;
    int random2 = rand() % nr;
    swap(array[random1], array[random2]);
}

void Sort::quantumBogoSort(bool ascendent)
{
    for (int i = 0; i < nr - 1; i++)
    {
        if ((array[i - 1] > array[i] && ascendent) || (array[i - 1] < array[i] && !ascendent))
            cout << array[1000000001];
    }
}

void Sort::Print()
{
    for (int i = 0; i < nr; i++)
        cout << array[i] << " ";
}

int Sort::GetElementsCount()
{
    return nr;
}

int Sort::GetElementFromIndex(int i)
{
    return array[i];
}