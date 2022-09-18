#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Rus");

    int k, n, s;
    std::cout << "Введите k,n через пробел ";
    std::cin >> k >> n;

    // динамический массив
    int *numbers = new int[k * n];

    std::cout << "Вводите числа" << "\n";
    for (int i = 0; i < SIZE; ++i)
    {
        std::cin >> numbers[i];
    }

    int min = INT_MAX;

    for (int i = 0; i < n; i += k)
    {
        s = 0;

        for (int j = 0; j < k; ++j)
        {
            s += numbers[i + j];
        }

        min = s < min ? s : min;
    }

    std::cout << "Минимум равен " << min;
