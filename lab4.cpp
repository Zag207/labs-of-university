#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Rus");

    int x, y;
    y = 0;

    std::cout << "Введите значение x: ";
    std::cin >> x;

    for (int i = 10; i >= 0; i--)
    {
        y += (i + 1) * pow(x, i);
    }

    std::cout << "y = " << y;
}
