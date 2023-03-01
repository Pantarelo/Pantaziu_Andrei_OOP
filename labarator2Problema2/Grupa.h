#include "Student.h"

class Grupa
{
    private:
        Student v[101];
        int count = 0;
    public:
        void addStudent(Student s)
        {
            if (count < 101)
                v[count] = s;
                count++;
        }
        void sortStudent()
        {
            for (int i = 0; i < count - 1; i++)
                for (int j = i + 1; j < count; j++)
                    if (v[i].avgGrade() > v[j].avgGrade())
                        swap(v[i],v[j]);
        }
};