#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;


int main()
{
    setlocale(LC_ALL, "Rus");
    double matr[6][9];

    //Вещественный рандомайзер
    srand(time(0));
    double first, last;
    cin >> first >> last;
    сout << "\n";
    //---------------------------
    
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 9; ++j) {
            //cin >> matr[i][j];

            //Вычисляю рандомайзером
            matr[i][j] = (double)rand() / RAND_MAX - (last - first) - first;

            //Вывод матрицы
            cout << std::setw(6) << std::right << std::setprecision(4) << matr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
    double max = matr[0][0], min = matr[5][8], tmp;
    int maxI = 0, minI = 5;

    //Для теста
    /*int maxJ = 0, minJ = 8;*/
    //-------------------------

    //Нахожу максимальный и минимальный
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 9; ++j) {
            maxI = matr[i][j] > max ? i : maxI;
            minI = matr[i][j] < min ? i : minI;

            //Для теста
            /*maxJ = matr[i][j] > max ? j : maxJ;
            minJ = matr[i][j] < min ? j : minJ;*/
            //----------------

            max = matr[i][j] > max ? matr[i][j] : max;
            min = matr[i][j] < min ? matr[i][j] : min;
        }
        
    }

    //Для теста (Вывод максимального и минимального с координатами)
    /*cout << max << " " << maxI << " " << maxJ << "\n";
    cout << min << " " << minI << " " << minJ << "\n\n";*/
    //----------------

    //Меняю строки местами
    for (int j = 0; j < 9; ++j)
    {
        tmp = matr[maxI][j];
        matr[maxI][j] = matr[minI][j];
        matr[minI][j] = tmp;
    }

    //Вывод итоговой матрицы
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 9; ++j) {
            cout << std::setw(6) << std::right << std::setprecision(4) << matr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
