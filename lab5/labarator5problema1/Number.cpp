#include "Number.h"
#include <cstring>
#include <iostream>
using namespace std;

Number::Number(const char * value, int base)
{
    this -> baza = base;
    int k = strlen(value);
    if (base >= 2 && base <= 16)
    {
        this -> nrCount = k;
        this -> valoare = new char[k];
        strcpy(valoare, value);
    }
}

Number::~Number()
{
    this -> valoare = NULL;
}

//operators

Number operator+(const Number &n1, const Number &n2)
{
    int maxBase = max(n1.baza, n2.baza);
    Number num1 = n1;
    num1.SwitchBase(maxBase); 
    Number num2 = n2;
    num2.SwitchBase(maxBase);
    char* rezultat = new char[num1.nrCount + 2];
    int carry = 0;
    for (int i = num1.nrCount - 1; i >= 0; i--)
    {
        int s = (num1.valoare[i] - '\0' + num2.valoare[i] - '\0') + carry;
        carry = s / maxBase;
        rezultat[i + 1] = (s % maxBase) + '\0';
    }
    rezultat[0] = carry + '\0';
    int i = 0;
    while (rezultat[i] == '0')
        i++;
    Number fRezultat(rezultat + i, maxBase);
    delete[] rezultat;
    return fRezultat;
}

Number operator-(const Number &n1, const Number &n2)
{
    int maxBase = max(n1.baza, n2.baza);
    Number num1 = n1;
    num1.SwitchBase(maxBase); 
    Number num2 = n2;
    num2.SwitchBase(maxBase);
    char* rezultat = new char[num1.nrCount + 2];
    int borrow = 0;
    for (int i = num1.nrCount - 1; i >= 0; i++)
    {
        int d = (num1.valoare[i] - '0') - (num2.valoare[i] - '0') - borrow;
        if (d < 0)
        {
            d += maxBase;
            borrow = 1;
        }
        else
            borrow = 0;
        rezultat[i] = d + '0';
    }
    int i = 0;
    while (rezultat[i] == '0')
        i++;
    Number fRezultat(rezultat + i, maxBase);
    delete[] rezultat;
    return fRezultat;
}

Number& Number::operator=(const Number &n1)
{
    this -> valoare = n1.valoare;
    return (*this);
}


//index

char Number::operator[](int index)
{
    if (index < 0 || index >= this -> nrCount)
    {
        cout << "indexul nu se incatreaza in limite";
        return '0';
    }
    return this -> valoare[index];
}

//relations

bool operator>(Number &n1, Number &n2)
{
    int maxBase = max(n1.baza, n2.baza);
    Number num1 = n1;
    num1.SwitchBase(maxBase);
    Number num2 = n2;
    num2.SwitchBase(maxBase);
    if (n1.nrCount > n2.nrCount)
        return true;
    else
        if (n1.nrCount < n2.nrCount)
            return false;
        else
            for (int i = 0; i <= n1.nrCount; i++)
            {
                if (n1.valoare[i] > n2.valoare[i])
                    return true;
                else
                    if (n1.valoare[i] < n2.valoare[i])
                        return false;
            }
    return false;
}

bool operator<(Number &n1, Number &n2)
{
    return !(n1 > n2) && !(n1 == n2);
}

bool operator>=(Number &n1, Number &n2)
{
    return n1 > n2 || n1 == n2;
}

bool operator<=(Number &n1, Number &n2)
{
    return n1 < n2 || n1 == n2;
}

bool operator==(Number &n1, Number &n2)
{
    int maxBase = max(n1.baza, n2.baza);
    Number num1 = n1;
    num1.SwitchBase(maxBase);
    Number num2 = n2;
    num2.SwitchBase(maxBase);
    if (n1.nrCount != n2.nrCount)
        return false;
    for (int i = 0; i < n1.nrCount; i++)
        if (n1.valoare[i] != n2.valoare[i])
            return false;
    return true;
}

bool operator!=(Number &n1, Number &n2)
{
    return !(n1 == n2);
}

// << operator

ostream& operator<<(ostream& os, const Number& dt)
{
    os << dt.valoare << " " << dt.baza << " " << dt.nrCount;
    return os;
}

//others

int Number::charToInt(char s)
{
    if (s >= '0' && s <= '9')
        return s - '\0';
    return s - 'A' + 10;
}

char Number::intToChar(int number)
{
    if (number >= 0 || number <= 9)
        return '0' + number;
    return 'A' + number + 10;
}

void Number::SwitchBase(int newBase)
{
    if (newBase < 2 || newBase > 16)
    {
        cout << "baza prea mare sau prea mica";
        return;
    }
    if (newBase == baza)
        return;
    int d = 0, m = 1;
    for (int i = nrCount - 1; i >= 0; i--)
    {
        int dvalue = charToInt(valoare[i]);
        d = d + dvalue * m;
        m *= baza;
    }
    int i = 0;
    while (d)
    {
        valoare[i] = intToChar(d % newBase);
        d /= newBase;
    }
    reverse(valoare, valoare + i);
} 

/// @brief 
/// @param nr 
/// @param initBase 
/// @param newBase 
/// @return 
int Number::convertToBase(int nr, int initBase, int newBase)
{
    int rezultat = 0;
    int power = 1;
    while (nr != 0)
    {
        int rest = nr % newBase;
        rezultat = rezultat + rest * power;
        power = power * initBase;
        nr = nr / newBase;
    }
    return rezultat;
}

void Number::Print()
{
    cout << this -> valoare;
}

int Number::GetDigitsCount()
{
    return strlen(this -> valoare);
}

int Number::GetBase()
{
    return this -> baza;
}

Number Number::operator--()
{
    this -> valoare++;
}
