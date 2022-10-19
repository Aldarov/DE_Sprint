#include <iostream>

using namespace std;

void fillArray(int (*arr)[5][5])
{
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int val = 30 + (rand() % 30);
            (*arr)[i][j] = val;
        }
    }
}

int getMaxValue(int (*arr)[5][5])
{
    int max = (*arr)[0][0];
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
             if ((*arr)[i][j] > max)
             {
                max = (*arr)[i][j];
             }
        }
    }

    return max;
}

int getMinValue(int (*arr)[5][5])
{
    int min = (*arr)[0][0];
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
             if ((*arr)[i][j] < min)
             {
                min = (*arr)[i][j];
             }
        }
    }

    return min;
}

void printArray(int (*arr)[5][5])
{
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << (*arr)[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "");

    int arr[5][5];

    fillArray(&arr);

    printArray(&arr);

    cout << "Максимальное значение: " << getMaxValue(&arr) << "\n";
    cout << "Минимальное значение: " << getMinValue(&arr) << "\n";

    return 0;
}