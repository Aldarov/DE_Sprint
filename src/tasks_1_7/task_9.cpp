#include <iostream>
#include <vector>

using namespace std;

float avg(int *values, int size)
{
    if (size == 0)
        return 0;

    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        cout << values[i] << "\n";
        sum += values[i];
    }

    return sum / size;
}

class Student
{
    public:
        string fullName;

        string group;

        int marks[5];

        float avgMark()
        {
            // int size = sizeof(masks) / sizeof(masks[0]);
            return avg(marks, 5);
        }

        bool isAllMarks(int mark)
        {
            bool res = true;
            for (int i = 0; i < 5; i++)
            {
                if (marks[i] != mark)
                {
                    res = false;
                }
            }

            return res;
        }

        Student(string _fullName, string _group, int _marks[5])
        {
            fullName = _fullName;
            group = _group;
            auto &marks = _marks;
        }

        // Student(string _fullName, string _group)
        // {
        //     fullName = _fullName;
        //     group = _group;
        // }
};

vector<Student> initStudents()
{
    vector<Student> res;

    res.push_back(Student("Иванов ИИ", "05111", new int[5]{ 1, 2, 3, 4, 5 }));
    res.push_back(Student("Петров АА", "05121", new int[5]{ 4, 4, 4, 4, 4 }));
    res.push_back(Student("Сидоров ББ", "05311", new int[5]{ 5, 5, 5, 5, 5 }));
    res.push_back(Student("Иванов2 ИИ", "05111", new int[5]{ 1, 2, 3, 4, 5 }));
    res.push_back(Student("Петров2 АА", "05121", new int[5]{ 4, 4, 4, 4, 4 }));
    res.push_back(Student("Сидоров2 ББ", "05311", new int[5]{ 5, 5, 5, 5, 5 }));
    res.push_back(Student("Иванов3 ИИ", "05111", new int[5]{ 1, 2, 3, 4, 5 }));
    res.push_back(Student("Петров3 АА", "05121", new int[5]{ 4, 4, 4, 4, 4 }));
    res.push_back(Student("Сидоров3 ББ", "05311", new int[5]{ 5, 5, 5, 5, 5 }));
    res.push_back(Student("Сидоров4 ББ", "05311", new int[5]{ 5, 5, 5, 5, 5 }));

    return res;
}

int main()
{
    setlocale(LC_ALL, "");

    vector<Student> students = initStudents();

    return 0;
}