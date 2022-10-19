#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    float max = 0;
    do
    {
        float digit;
        cout << "Введите число: ";
        cin >> digit;

        if (digit > max)
        {
            max = digit;
            cout << "Максимальное число = " << max << "\n";
        }
    }
    while (true);

    return 0;
}