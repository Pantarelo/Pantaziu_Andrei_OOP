#include "Function.h"

int compareName(Student s1, Student s2)
{
    if (s1.getName() == s2.getName()) 
        return 0;
    if (s1.getName() > s2.getName())
        return 1;
    return -1;
}

int compareMath(Student s1, Student s2)
{
    if (s1.mathGrade() == s2.mathGrade())
        return 0;
    if (s1.mathGrade() > s2.mathGrade())
        return 1;
    return -1;
}

int compareHis(Student s1, Student s2)
{
    if (s1.hisGrade() == s2.hisGrade())
        return 0;
    if (s1.hisGrade() > s2.hisGrade())
        return 1;
    return -1;
}

int compareEng(Student s1, Student s2)
{
    if (s1.engGrade() == s2.engGrade())
        return 0;
    if (s1.engGrade() > s2.engGrade())
        return 1;
    return -1;
}

int compareAvg(Student s1, Student s2)
{
    if (s1.avgGrade() == s2.avgGrade())
        return 0;
    if (s1.avgGrade() > s2.avgGrade())
        return 1;
    return -1;
}