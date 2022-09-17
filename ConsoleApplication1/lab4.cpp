#include <iostream>
#include <cmath>


int main() {
	setlocale(LC_ALL, "Rus");
    int i = 11;
    double x, y;
	std::cout << "Введите x: ";
	std::cin >> x;
	
	while(i > 0){
	    y += i*pow(x, (i - 1));
	    --i;
	}
	std::cout <<"Значение выражения: "<<y;
}
