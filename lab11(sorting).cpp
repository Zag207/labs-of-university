#include <iostream>
using std::cin;
using std::cout;

void init(int**&mat, int m, int n, int first, int last) {
    srand(time(0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = first + rand() % (last - first + 1);
        }
    }
}

void print(int**& mat, int m, int n) {
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

//сортировка выбором
void sort(int**& mat, int n, int i) {
    int min, tmp, minI;

    for (int p = 0; p < n - 1; ++p) {
        min = mat[i][p];
        minI = p;

        for (int j = p + 1; j < n; ++j)
        {
            minI = min > mat[i][j] ? j : minI;
            min = min > mat[i][j] ? mat[i][j] : min;
        }

        if (min < mat[i][p]) {
            tmp = mat[i][minI];
            mat[i][minI] = mat[i][p];
            mat[i][p] = tmp;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, m, first, last;
    cout << "Введите размерности матрицы через пробел: ";
    cin >> n >> m;
    cout << "Введите минимальный и максимальный возможный элемент матрицы через пробел: ";
    cin >> first >> last;

    int** mat = new int*[n];

    for (int i = 0; i < n; ++i)
    {
        mat[i] = new int[m];
    }

    init(mat, n, m, first, last);
    cout << "\nИсходная матрица\n";
    print(mat, n, m);

    //Какую строку сортируем
    int i;
    cout << "Введите номер строки, которую выхотите отсортировать: ";
    cin >> i;

    sort(mat, m, i - 1);
    cout << "\nОтсортированая матрица\n";
    print(mat, n, m);


    //очищаю память
    for (int i = 0; i < n; ++i)
    {
        delete[] mat[i];
    }

    delete[] mat;
    return 0;
}
