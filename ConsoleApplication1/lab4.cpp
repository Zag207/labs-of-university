#include <iostream>
#include <cmath>


int main() {
	setlocale(LC_ALL, "Rus");

    double x, y;
	std::cout << "Введите x: ";
	std::cin >> x;
	
	for(int i = 11; i > 0; --i){
	    y += i*pow(x, (i - 1));
	}
	std::cout <<"Значение выражения: "<<y;
}
