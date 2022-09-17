// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>


int main() {
	setlocale(LC_ALL, "Rus");


	double x1, x2, x3, y1, y2, y3;
	std::cout << "Введите координаты 1 точки через пробел(x,y): ";
	std::cin >> x1 >> y1;
	std::cout << "Введите координаты 2 точки через пробел(x,y): ";
	std::cin >> x2 >> y2;
	std::cout << "Введите координаты 3 точки через пробел(x,y): ";
	std::cin >> x3 >> y3;

	double d1 = sqrt(pow(x1 + x2, 2) + pow(y1 + y2, 2));
	double d2 = sqrt(pow(x1 + x3, 2) + pow(y1 + y3, 2));
	double d3 = sqrt(pow(x2 + x3, 2) + pow(y2 + y3, 2));

	if (d1 >= d2 + d3 && d2 >= d1 + d3 && d3 >= d1 + d2) {
		std::cout << "Это не треугольник";
		return 1;
	}

	double summ = d1 + d2 + d3;

	if (pow(d1, 2) > pow(d2, 2) + pow(d3, 2) || 
		pow(d2, 2) > pow(d1, 2) + pow(d3, 2) || 
		pow(d3, 2) > pow(d2, 2) + pow(d1, 2)) {

		double p = (d1 + d2 + d3) / 2;
		double s = sqrt(p * (p - d1) * (p - d2) * (p - d3));

		std::cout << "Площадь = " << s << "\n";
	}

	std::cout << "Стороны треугольника" <<"\n";

	double a, c;

	// упорядочивание числе в порядке убывания
	if (d1 > d2 && d1 > d3) {
		c = d1;
		summ -= d1;
	}
	else if (d2 > d1 && d1 > d3) {
		c = d2;
		summ -= d2;
	}
	else{
		c = d3;
		summ -= d3;
	}

	if (d1 < d2 && d1 < d3) {
		a = d1;
		summ -= d1;
	}
	else if (d2 < d1 && d1 < d3) {
		a = d2;
		summ -= d2;
	}
	else {
		a = d3;
		summ -= d3;
	}

	std::cout << c << "\n";
	std::cout << summ << "\n";
	std::cout << a << "\n";
}

