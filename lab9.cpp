#include <iostream>
#include <cmath>
using std::cin;
using std::cout;


int main()
{
    setlocale(LC_ALL, "Rus");

    int count1 = 0, count2 = 0;
    std::string str;
    cout << "Введите строку без пробела"<<"\n";
    cin >> str;

    for (int i = 0; i < str.size(); ++i)
    {
        count1 += str[i] == '(' ? 1 : 0;
        count2 += str[i] == ')' ? 1 : 0;
    }

    if (count1 == count2)
    {
        cout << "Всё хорошо";
    }
    else {
        cout << "Ошибка";
    }
}
