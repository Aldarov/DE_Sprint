#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    float x = -4;
    while (x < 4.5)
    {
        float y = -2 * pow(x, 2) - 5 * x - 8;
        cout << "x = " << x << "; " << "y = " << y << "\n";
        x += 0.5;
    }

    return 0;
}