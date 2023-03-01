#include <string>
using namespace std;

class Student
{
    public:
        string getName();
        float mathGrade();
        float hisGrade();
        float engGrade();
        float avgGrade();
        void setName(string name);
        void setMathGrade(float mGrade);
        void setEngGrade(float eGrade);
        void setHistGrade(float hGrade);
    private:
        string name_;
        float math_;
        float eng_;
        float his_;
};