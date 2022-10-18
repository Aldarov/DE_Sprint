#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int year;

    cout << "Введите год: ";
    cin >> year;

    if (year % 400 == 0)
        cout << year << " год - високосный." << endl;
    else if (year % 100 == 0)
        cout << year << " год - невисокосный." << endl;
    else if (year % 4 == 0)
        cout << year << " год - високосный." << endl;
    else
        cout << year << " год - невисокосный." << endl;

    return 0;
}