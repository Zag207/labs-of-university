//Условие: Определить количество элементов массива, значение которых больше соседних элементов.

#include <iostream>
using std::cin;
using std::cout;


int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int n, first, last, k = 0;

    cin >> n;
    cin >> first;
    cin >> last;

    int* ar = new int[n];

    // Заполняем массив случайными числами в диапазоне [first; last]

    cout << "Полученный массив\n";

    for (int i = 0; i < n; ++i)
    {
        ar[i] = first + rand() % (last - first + 1);
        cout << ar[i] << " ";
    }
    
    for (int i = 0; i < n; ++i) {
        if (i == 0)
        {
            if (n == 1) break; //Если в массиве только 1 элемент

            k += ar[i] > ar[i + 1] ? 1 : 0;
        }
        else if(i == n - 1)
        {
            k += ar[i] > ar[i - 1] ? 1 : 0;
        }
        else
        {
            k += (ar[i] > ar[i - 1]) && (ar[i] > ar[i + 1]) ? 1 : 0;
        }
    }

    cout << "\nИскомое количество равно " << k;
    return 0;
}
