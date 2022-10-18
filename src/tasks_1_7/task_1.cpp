#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    double num1, num2;

    cout << "Введите 1 число: ";
    cin >> num1;
    cout << "Введите 2 число: ";
    cin >> num2;

    if (num1 > num2)
    {
        cout << num1 << " больше " << num2 << endl;
    }
    else if (num2 > num1)
    {
        cout << num2 << " больше " << num1 << endl;
    }
    else{
        cout << num1 << " равно " << num2 << endl;
    }

    return 0;
}