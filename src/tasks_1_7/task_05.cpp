#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    for (int i = 1; i < 11; i++)
    {
        int s = i * i;
        cout << i << "^2 = " << s << "\n";
    }

    return 0;
}