#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

using std::cin;
using std::cout;
using std::string;

struct interfaceData
{
    int command = 0;
    int data;
};

string* getSubjectsAndStudentsLists(string, int);
bool getInterfaceData(interfaceData&); //Возвращает 1 если все плохо, иначе 0
void init(int**&, int, int);
void printMatr(string*&, string*&, int**&, int, int);
void searchRow(int**&, string*&, string*&, int, int, int);
void searchCol(int**&, string*&, string*&, int, int, int);
void printArr(int**&, int, int, bool);
void numGood(int**&, string*&, int, int, int);
void average(int**&, string*&, int, int , int);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    interfaceData Data;

    int m, n;
    cout << "Введите количество предметов: ";
    cin >> n;
    
    string* subjects = getSubjectsAndStudentsLists("Введите названия предметов через запятую без пробелов: ", n);
    cout << "Введите количество студентов: ";
    cin >> m;
    
    string* students = getSubjectsAndStudentsLists("Введите фамилии студентов через запятую без пробелов: ", m);

    //Матрица оценок с хорошо успевающими и средними оценками
    int** matr = new int*[m + 1];
    for (int i = 0; i < m + 1; ++i)
    {
        matr[i] = new int[n + 1];
    }
    init(matr, m, n);

    bool haveError = 0;
    while (Data.command != 6) {
        haveError = getInterfaceData(Data);

        if (haveError) continue;
        else {
            switch (Data.command)
            {
            case 1:
                printMatr(subjects, students, matr, m, n);
                break;
            case 2:
                searchRow(matr, students, subjects, Data.data, m, n);
                break;
            case 3:
                searchCol(matr, students, subjects, Data.data, m, n);
                break;
            case 4:
                numGood(matr, subjects, m, n, Data.data);
                break;
            case 5:
                average(matr, students, m, n, Data.data);
                break;
            default:
                break;
            }  
        }
        continue;
    }

    for (int i = 0; i < m + 1; ++i) delete[] matr[i];
    delete[] matr;
    delete[] subjects;
    delete[] students;
    return 0;
}

// Возвращает указатель на динамический массив строк
string* getSubjectsAndStudentsLists(string message, int p) {
    string s = "";
    string* arr = new string[p]; //Массив строк предметов/студентов
    cout << message;

    cin.ignore(1); // Очищаю поток ввода от символа \n
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
void init(int**& matr, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j) {
            matr[i][j] = 2 + rand() % (5 - 2 + 1);
        }
    }
}
bool getInterfaceData(interfaceData& Data)
{
    cout << "\n\nДоступные команды: \n";
    cout << "1 - Показать матрицу\n";
    cout << "2 - Показать оценки студента\n";
    cout << "3 - Показать оценки всех студентов за предмет\n";
    cout << "4 - Вывести количество хорошо успевающих студентов по предмету\n";
    cout << "5 - Вывести среднее арифметрическое значение оценок студента\n";
    cout << "6 - Закончить выполнение программы\n";
    cout << "Введите команду -> ";
    cin >> Data.command;

    if (cin.fail() == 1) {
        cout << "Неверная команда! Попробуйте еще раз\n";
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        return 1;
    }
    else if(Data.command < 1 || Data.command > 6) {
        cout << "Неверная команда! Попробуйте еще раз\n";
        Data.command = 0;
        return 1;
    }
    else {
        switch (Data.command)
        {
        case 5:
        case 2:
            cout << "Введите номер студента -> ";
            cin >> Data.data;
            if (cin.fail() == 1) {
                cout << "Неверный формат номера! Попробуйте еще раз\n";
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
                return 1;
            }
            break;
        case 3:
        case 4:
            cout << "Введите номер предмета -> ";
            cin >> Data.data;
            if (cin.fail() == 1) {
                cout << "Неверный формат номера! Попробуйте еще раз\n";
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
                return 1;
            }
            break;
        
            default:
                break;
        }
        return 0;
    }
}
void printMatr(string*& subjects, string*& students, int**& matr, int m, int n)
{
    cout << "\n                 |";
    for (int i = 0; i < n; ++i) cout << std::setw(10) << std::setfill(' ') << subjects[i] << "|";
    cout << "\n";
    cout << std::setw(18) << std::setfill('-') << "|";
    for (int i = 0; i < n; ++i) cout << std::setw(11) << std::setfill('-') << "|";
    for (int i = 0; i < m; ++i) {
        cout << "\n" << std::setw(17) << std::setfill(' ') << students[i]  << "|"; //!
        for (int j = 0; j < n; ++j)
        {
            cout << std::setw(10) << matr[i][j] << std::setfill(' ') << "|";
        }
        cout << "\n" << std::setw(18) << std::setfill('-') << "|";
        for (int j = 0; j < n; ++j)
        {
            cout << std::setw(11) << std::setfill('-') << "|";
        }
    }
}
void numGood(int**& matr, string*& subjects, int m, int n, int data)
{
    int k = 0;

    // валидация
    if (data < 1 || data > n) {
        cout << "Неверный номер! Попробуйте еще раз\n";
        return;
    }
    //-------------

    for (int i = 0; i < m; ++i)
    {
        if (matr[i][data - 1] > 3) ++k;
    }
    cout << "\nКоличество успевающих студентов по предмету " << subjects[data - 1] << " " << k << "\n";
}
void average(int**& matr, string*& students, int m, int n, int data)
{
    double s = 0;

    // валидация
    if (data < 1 || data > m) {
        cout << "Неверный номер! Попробуйте еще раз\n";
        return;
    }
    //-------------

    for (int j = 0; j < n; ++j)
    {
        s += matr[data - 1][j];
    }

    cout << "\nСредний балл студента " << students[data - 1] << " равен " << s / n << "\n";
}
void searchRow(int**& matr, string*& students, string*& subjects, int data, int m, int n) {

    //валидация
    if (data < 1 || data > m) {
        cout << "Студент не найден! Попробуйте еще раз\n";
        return;
    }
    //-----------

    cout << "\n                 |";
    for (int i = 0; i < n; ++i) cout << std::setw(10) << std::setfill(' ') << subjects[i] << "|";
    cout << "\n";
    cout << std::setw(18) << std::setfill('-') << "|";
    for (int i = 0; i < n; ++i) cout << std::setw(11) << std::setfill('-') << "|";
    cout << "\n" << std::setw(17) << std::setfill(' ') << students[data - 1] << "|";
    for (int j = 0; j < n; ++j)
    {
        cout << std::setw(10) << matr[data - 1][j] << std::setfill(' ') << "|" << std::setfill(' ');
    }
    cout << "\n";
}
void searchCol(int**& matr, string*& students, string*& subjects, int data, int m, int n) {

    //валидация
    if (data < 1 || data > n) {
        cout << "Предмет не найден! Попробуйте еще раз\n";
        return;
    }
    //-----------

    cout << "\n                 |";
    cout << std::setw(10) << std::setfill(' ') << subjects[data - 1] << "|";
    cout << "\n";
    cout << std::setw(18) << std::setfill('-') << "|" << std::setfill(' ');
    cout << std::setw(11) << std::setfill('-') << "|" << std::setfill(' ');
    
    for (int i = 0; i < m; ++i)
    {
        cout << "\n" << std::setw(17) << std::setfill(' ') << students[i] << "|";
        cout << std::setw(10) << std::setfill(' ') << matr[i][data - 1] << "|";
        cout << "\n" << std::setw(18) << std::setfill('-') << "|";
        cout << std::setw(11) << std::setfill('-') << "|" << std::setfill(' ');
    }

    cout << "\n";
}
