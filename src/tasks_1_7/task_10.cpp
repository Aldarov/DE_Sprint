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

        int trainNumber = 0;

        Train(string destination, time_t departureTime)
        {
            this->destination = destination;
            this->departureTime = departureTime;
        }

        setTrainNumber(int number)
        {
            this->trainNumber = number;
        }
};

time_t getTime(tm time)
{
    return mktime(&time);
}

vector<Train> initTrains()
{
    vector<Train> res;

    res.push_back(Train("destination 1", getTime({ .tm_min = 0, .tm_hour = 12, .tm_mday = 1, .tm_mon = 9 - 1, .tm_year = 2022 - 1900 })));
    res.push_back(Train("destination 2", getTime({ .tm_min = 0, .tm_hour = 11, .tm_mday = 1, .tm_mon = 9 - 1, .tm_year = 2022 - 1900 })));
    res.push_back(Train("destination 1", getTime({ .tm_min = 0, .tm_hour = 9, .tm_mday = 1, .tm_mon = 9 - 1, .tm_year = 2022 - 1900 })));
    res.push_back(Train("destination 4", getTime({ .tm_min = 0, .tm_hour = 7, .tm_mday = 1, .tm_mon = 9 - 1, .tm_year = 2022 - 1900 })));
    res.push_back(Train("destination 3", getTime({ .tm_min = 0, .tm_hour = 16, .tm_mday = 1, .tm_mon = 9 - 1, .tm_year = 2022 - 1900 })));

    return res;
}

void setTrainNumbers(vector<Train> &trains)
{
  for (int i = 0; i < trains.size(); i++)
  {
    cout << "Поезд отправляется в \"" << trains[i].destination << "\" - " << timeToString(&trains[i].departureTime) << "\n";
    cout << "Введите номер поезда: ";
    int number;
    cin >> number;
    trains[i].setTrainNumber(number);
  }
}

void showTrains(vector<Train> trains)
{
  for (int i = 0; i < trains.size(); i++)
  {
    cout << "Поезд № " << trains[i].trainNumber << " отправляется в \"" << trains[i].destination << "\" - " << timeToString(&trains[i].departureTime) << "\n";
  }
}

struct {
    bool operator() (Train a, Train b) const
    {
        if (a.destination < b.destination)
            return true;
        else if ((a.destination == b.destination) and (a.departureTime < b.departureTime))
            return true;
        else
            return false;
    }
} TrainsLess;

int main()
{
    setlocale(LC_ALL, "");

    vector<Train> trains = initTrains();

    setTrainNumbers(trains);

    sort(trains.begin(), trains.end(), TrainsLess);

    showTrains(trains);

    return 0;
}