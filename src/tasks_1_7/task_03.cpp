#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    float a, b, c, d;

    cout << "Введите коэффициенты квадратного уравнения \n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    if (a == 0)
    {
        cout << "Неверный коэффициент а = 0" << endl;
        return 0;
    }


    d = pow(b, 2) - 4 * a * c;
    if (d < 0)
    {
        cout << "Корней нет";
    }
    else if (d == 0)
    {
        float x = -b / (2 * a);
        cout << "x = " << x;
    }
    else
    {
        float x1 = (-b + sqrt(d)) / (2 * a);
        float x2 = (-b - sqrt(d)) / (2 * a);
        cout << "x1 = " << x1 << "; x2 = " << x2;
    }

    return 0;
}