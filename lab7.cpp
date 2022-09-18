#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Rus");

    double area, p;
    int r, a, b, c, s;

    std::cout << "Введите номер фигуры (1-прямоугольник 2-треугольник 3-круг): ";
    std::cin >> s;

    switch (s)
    {
    case 1:
        std::cout << "Введите стороны через пробел: ";
        std::cin >> a >> b;
        area = a * b;
        break;
    case 2:
        std::cout << "Введите стороны через пробел: ";
        std::cin >> a >> b >> c;
        p = (a + b + c) / 2.0;
        area = sqrt(p * (p - a) * (p - b) * (p - c));
        break;
    case 3:
        std::cout << "Введите радиус: ";
        std::cin >> r;
        area = 3.14*r*r;
        break;

    default:
        std::cout << "Неверный номер фигуры";
        break;
    }

    std::cout << "Площадь фигуры: " << area;
}
