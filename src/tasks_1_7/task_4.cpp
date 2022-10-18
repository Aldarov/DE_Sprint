#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int num;

    cout << "Введите число: ";
    cin >> num;

    if (num % 2 == 0)
        cout << "введенное число четное";
    else
        cout << "введенное число нечетное";

    return 0;
}