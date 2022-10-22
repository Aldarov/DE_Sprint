#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int year;

    cout << "Введите год: ";
    cin >> year;

    if (year % 400 == 0)
        cout << year << " год - високосный.";
    else if (year % 100 == 0)
        cout << year << " год - невисокосный.";
    else if (year % 4 == 0)
        cout << year << " год - високосный.";
    else
        cout << year << " год - невисокосный.";

    return 0;
}