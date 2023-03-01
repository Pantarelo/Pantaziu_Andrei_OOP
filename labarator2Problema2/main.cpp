#include "Student.h"
#include "Function.h"
#include "Grupa.h"

int main()
{
    Student a1;
    Student a2;
    Grupa g;
    a1.setName("Adelin");
    a2.setName("Adi");
    a1.setMathGrade(6.0);
    a2.setMathGrade(6.4);
    a1.setHistGrade(9);
    a2.setHistGrade(7.6);
    a1.setEngGrade(10);
    a1.setEngGrade(9.6);
    return 0;
}