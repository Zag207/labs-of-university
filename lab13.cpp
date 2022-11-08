#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using std::cin;
using std::cout;
using std::string;

//struct interfaceData
//{
//    int m, n;
//    string* subjects;
//    string* students;
//};

string* getSubjectsAndStudentsLists(string, int);
void getInterfaceInitData();
void init(int**&, int, int);
void printMatr(int*&, int*&, int**&, int, int);
int* searchRow(int**&, int, int);
int* searchCol(int**&, int, int);
void printArr(int**&, int, int, bool);
void numGood(int**&, int**&, int, int);
void average(int**&, int**&, int, int);



int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int m, n;
    cout << "Введите количество предметов: ";
    cin >> n;

    string* subjects = getSubjectsAndStudentsLists("Введите названия предметов через запятую без пробелов", n);
    
    cout << "Введите количество студентов: ";
    cin >> m;
    
    string* students = getSubjectsAndStudentsLists("Введите фамилии студентов через запятую без пробелов", m);
    
    delete[] subjects;
    delete[] students;
    return 0;
}

string* getSubjectsAndStudentsLists(string message, int p) {
    string s;
    string* arr = new string[p]; //Массив строк предметов/студентов
    cout << message;
    getline(cin, s);

    s += ','; //костыль

    //Разбиение строки s на подстроки arr, где разделитель - запятая
    int i = 0, j = 0;
    while (i < p)
    {
        arr[i] = "";
        while (s[j] != ',')
        {
            arr[i] += s[j];
            ++j;
        }
        ++j;
        ++i;
    }

    return arr;
}
