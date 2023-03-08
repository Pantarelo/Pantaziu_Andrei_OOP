#include "Math.h"
#include <cstring>
#include <stdarg.h>
#include <iostream>
using namespace std;

int Math::Add(int a, int b)
{
    return a + b;
}

 int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return a + b;
}

int Math::Add(double a, double b, double c)
{
    return a + b + c;
}

int Math::Mul(int a, int b)
{
    return a + b;
}

int Math::Mul(int a, int b, int c)
{
    return a + b + c;
}

int Math::Mul(double a, double b)
{
    return a + b;
}

int Math::Mul(double a, double b, double c)
{
    return a + b + c;
}

/*int Math::Add(int count,...)
{
    int s = 0;
    va_list v;
    va_start (v, count);
    for (int i = 0; i < count; i++)
        s += va_arg(v,int);
    va_end(v);
    return s;
}*/

int Math::Add(int count,...)
{
    int* adress = &count;
    int nr = 4, s = 0;
    while (count)
    {
        s += *(adress + nr);
        nr += 4;
        --count;
    }
    return s;
}

char* Math::Add(const char* s1, const char* s2)
{
    if (s1 == NULL || s2 == NULL)
        return NULL;
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    char* sr = new char[l1 + l2];
    strcat(sr,s1);
    strcat(sr,s2);
    return sr;
}
