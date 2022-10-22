#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float avg(vector<int> values)
{
    if (values.empty())
        return 0;

    int sum = 0;
    for(int i = 0; i < values.size(); i++)
    {
        sum += values[i];
    }

    auto const count = static_cast<float>(values.size());

    return sum / count;
}

class Student
{
    public:
        string fullName;

        string group;

        vector<int> marks;

        float avgMark()
        {
            return avg(marks);
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

        Student(string _fullName, string _group, vector<int> _marks)
        {
            fullName = _fullName;
            group = _group;
            marks = _marks;
        }
};

vector<Student> initStudents()
{
    vector<Student> res;

    res.push_back(Student("Иванов ИИ", "05111", vector<int> { 1, 2, 3, 4, 5 }));
    res.push_back(Student("Петров АА", "05121", vector<int> { 4, 4, 4, 4, 4 }));
    res.push_back(Student("Сидоров ББ", "05311", vector<int> { 5, 5, 5, 5, 5 }));
    res.push_back(Student("Иванов2 ИИ", "05111", vector<int> { 1, 2, 3, 4, 5 }));
    res.push_back(Student("Петров2 АА", "05121", vector<int> { 4, 4, 4, 4, 4 }));
    res.push_back(Student("Сидоров2 ББ", "05311", vector<int> { 5, 5, 5, 5, 5 }));
    res.push_back(Student("Иванов3 ИИ", "05111", vector<int> { 2, 2, 2, 2, 2 }));
    res.push_back(Student("Петров3 АА", "05121", vector<int> { 4, 4, 4, 4, 4 }));
    res.push_back(Student("Сидоров3 ББ", "05311", vector<int> { 5, 5, 5, 5, 5 }));
    res.push_back(Student("Сидоров4 ББ", "05311", vector<int> { 5, 5, 5, 5, 5 }));

    return res;
}

struct {
    bool operator() (Student a, Student b) const
    {
        return a.avgMark() < b.avgMark();
    }
} StudentLess;

void showStudentsOnlyWith45(vector<Student> students)
{
  for (int i = 0; i < students.size(); i++)
  {
    if (students[i].isAllMarks(4) or students[i].isAllMarks(5))
        cout << students[i].fullName << " - " << students[i].group << " гр.\n";
  }
}

int main()
{
    setlocale(LC_ALL, "");

    vector<Student> students = initStudents();

    sort(students.begin(), students.end(), StudentLess);

    showStudentsOnlyWith45(students);

    return 0;
}