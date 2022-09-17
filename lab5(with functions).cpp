#include <iostream>
#include <cmath>

using namespace std;

struct functionResults {
    double a;
    int iEven, factEven, iOdd, factOdd;
};

struct functionResults calculateA(int i, int iEven, int factEven, int iOdd, int factOdd, double x) {
    functionResults res;
    double a;

    if (i == 1) {
        factOdd *= (i + 1);
        a = pow(-1, i) * pow(cos(x), i / 2.0) * iOdd / factOdd;
    }
    else if (i == 2) {
        factEven *= (i + 1);
        a = pow(-1, i) * pow(cos(x), i / 2.0) * iEven / factEven;
    }

    else if (i % 2 != 0 && i > 1) {
        iOdd *= i;
        factOdd *= (i + 1);
        a = pow(-1, i) * pow(cos(x), i / 2.0) * iOdd / factOdd;
    }
    else if (i % 2 == 0 && i > 2) {
        iEven *= i;
        factEven *= (i + 1);
        a = pow(-1, i) * pow(cos(x), i / 2.0) * iEven / factEven;
    }
    res.iEven = iEven;
    res.factEven = factEven;
    res.iOdd = iOdd;
    res.factOdd = factOdd;
    res.a = a;
    return res;
}


int main()
{
    setlocale(LC_ALL, "Rus");

    double x, E1, summaN;
    int N, iEven, factEven, iOdd, factOdd;
    functionResults res;

    summaN = 0;

    // Для умножения и факториала
    iEven = factEven = 2;
    iOdd = factOdd = 1;

    std::cout << "Введите x, N, E через пробел" << "\n";
    std::cin >> x >> N >> E1;

    // Вычисляю сумму N слагаемых
    for (int i = 1; i <= N; ++i) {
        res = calculateA(i, iEven, factEven, iOdd, factOdd, x);
        summaN += res.a;
        iEven = res.iEven;
        factEven = res.factEven;
        iOdd = res.iOdd;
        factOdd = res.factOdd;
    }

    double summaE1, summaE2;
    int count1, count2;
    int i = 0;
    summaE1 = summaE2 = count1 = count2 = 0;

    // Возвращаю к исходному
    iEven = factEven = 2;
    iOdd = factOdd = 1;

    // сумма для E1
    do {
        ++i;

        res = calculateA(i, iEven, factEven, iOdd, factOdd, x);
        iEven = res.iEven;
        factEven = res.factEven;
        iOdd = res.iOdd;
        factOdd = res.factOdd;

        if (abs(res.a) > E1) {
            summaE1 += res.a;
            count1 += 1;
        }
    } while (abs(res.a) > E1);

    double E2 = E1 * 10;
    i = 0;

    // Возвращаю к исходному
    iEven = factEven = 2;
    iOdd = factOdd = 1;

    // сумма для E2
    do {
        ++i;

        res = calculateA(i, iEven, factEven, iOdd, factOdd, x);
        iEven = res.iEven;
        factEven = res.factEven;
        iOdd = res.iOdd;
        factOdd = res.factOdd;

        if (abs(res.a) > E1) {
            summaE1 += res.a;
            count1 += 1;
        }
    } while (abs(res.a) > E1);

    std::cout << "Сумма первых N элементов равна" << summaN << "\n";
    std::cout << "Сумма элементов больших E1 по модулю и их количество" << summaE1 << count1 << "\n";
    std::cout << "Сумма элементов больших E2 по модулю и их количество" << summaE2 << count2 << "\n";
}
