#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

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

string timeToString(time_t *time)
{
    stringstream steam;
    steam << put_time(localtime(time), "%d.%m.%Y %H:%M");
    return steam.str();
}

class Train
{
    public:
        string destination;

        time_t departureTime;

        int trainNumber;

        Train(string _destination, time_t _departureTime)
        {
            destination = _destination;
            departureTime = _departureTime;
        }
};

vector<Train> initTrains()
{
    vector<Train> res;

    // struct tm my_time = { .tm_year = 2022 - 1900, .tm_mon = 9, .tm_mday = 1, .tm_hour = 8, .tm_min = 0 };
    struct tm my_time = { .tm_min = 0, .tm_hour = 8, .tm_mday = 1, .tm_mon = 9 - 1, .tm_year = 2022 - 1900 };
    // res.push_back(Train("Train 1", mktime(&my_time)));
    res.push_back(Train("Train 1", mktime(&tm{ .tm_min = 0, .tm_hour = 8, .tm_mday = 1, .tm_mon = 9 - 1, .tm_year = 2022 - 1900 })));
    // res.push_back(Train("Train 1", mktime(tm{tm_year = 2022, tm_mon = 9, tm_mday = 1, tm_hour = 9, tm_min = 0 })));

    return res;
}

// struct {
//     bool operator() (Student a, Student b) const
//     {
//         return a.avgMark() < b.avgMark();
//     }
// } StudentLess;

// void showStudentsOnlyWith45(vector<Student> students)
// {
//   for (int i = 0; i < students.size(); i++)
//   {
//     if (students[i].isAllMarks(4) or students[i].isAllMarks(5))
//         cout << students[i].fullName << " - " << students[i].group << " гр.\n";
//   }
// }

int main()
{
    setlocale(LC_ALL, "");

    vector<Train> trans = initTrains();

    // sort(students.begin(), students.end(), StudentLess);

    // showStudentsOnlyWith45(students);

    string time = timeToString(&trans[0].departureTime);
    return 0;
}