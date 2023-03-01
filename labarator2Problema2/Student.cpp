#include "Student.h"
using namespace std;

string Student::getName()
{
    return name_;
}

float Student::mathGrade()
{
    return math_;
}

float Student::hisGrade()
{
    return his_;
}

float Student::engGrade()
{
    return eng_;
}

float Student::avgGrade()
{
    return (math_ + his_ + eng_)/3.0;
}

void Student::setName(string name) {
    name_ = name;
}

void Student::setMathGrade(float mGrade) {
    math_ = mGrade;
}

void Student::setEngGrade(float eGrade) {
    eng_ = eGrade;
}

void Student::setHistGrade(float hGrade) {
    his_ = hGrade;
}


