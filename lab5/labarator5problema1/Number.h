#include <iostream>
using namespace std;

class Number
{
private:
    char * valoare;
    int baza;
    int nrCount;
public:
   Number(const char * value, int base); 
   ~Number();

   // add operators and copy/move constructor

   friend Number operator+(const Number &n1, const Number &n2);
   friend Number operator-(const Number &n1, const Number &n2);
   Number& operator=(const Number &n1);

   char operator[](int index);
   
   friend bool operator>(Number &n1, Number &n2);
   friend bool operator<(Number &n1, Number &n2);
   friend bool operator>=(Number &n1, Number &n2);
   friend bool operator<=(Number &n1, Number &n2);
   friend bool operator==(Number &n1, Number &n2);
   friend bool operator!=(Number &n1, Number &n2);
   
   // << operator
   friend ostream& operator<<(ostream& os, const Number& dt);

   int charToInt(char s); 
   char intToChar(int number);
   void SwitchBase(int newBase);
   int convertToBase(int nr, int initBase, int newBase);
   void Print();
   int  GetDigitsCount(); // returns the number of digits for the current number
   int  GetBase(); // returns the current base

   Number operator--();
};