#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Rus");

    int n;
    char s1, s2;

    std::cout << "Введите n: ";
    std::cin >> n;

    std::cout << "Введите символ: ";
    std::cin >> s1;

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Введите символ: ";
        std::cin >> s2;

        if (s1 == ',' && s2 == '-')
        {
            std::cout << "YES";
            return 1;
        }
        s1 = s2;
    }

    std::cout << "NO";
}
