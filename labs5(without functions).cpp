#include <iostream>
#include <cmath>


int main() {
	setlocale(LC_ALL, "Rus");
    
    double x, E1, summaN, a;
    int N;
    
    summaN = 0
    
    // Для умножения и факториала
    int iEven = factEven = 2;
    int iOdd = factOdd = 1;
    
    // факториал?
    int fact = 1;
    
    std::cout << "Введите x, N, E через enter" << "\n";
    std::cin >> x >> N >> E1;
    
    // Вычисляю сумму N слагаемых
    for(int i = 1; i <= N; ++i){
        if (i == 1){
            factOdd *= (i+1);
            a = pow(-1, i)*pow(cos(x), i/2.0)*iOdd/factOdd;
            summaN += a;
            continue
        }
        if(i == 2){
            factEven *= (i+1);
            a = pow(-1, i)*pow(cos(x), i/2.0)*iEven/factEven;
            summaN += a;
            continue
        }
        
        if(i % 2 != 0 && i > 1){
            iOdd *= i;
            factOdd *= (i+1);
            a = pow(-1, i)*pow(cos(x), i/2.0)*iOdd/factOdd;
            summaN += a;
        }
        else if(i % 2 == 0 && i > 2){
            iEven *= i;
            factEven *= (i+1);
            a = pow(-1, i)*pow(cos(x), i/2.0)*iEven/factEven;
            summaN += a;
        }
    }
    
    double summaE1 = summaE2 = 0;
    int count1 = count2 = 0;
    int i = 0;
    a = 0;
    
    // Возвращаю к исходному
    iEven = factEven = 2;
    iOdd = factOdd = 1;
    
    // сумма для E1
    do{
        ++i;
        
        if (i == 1){
            factOdd *= (i+1);
            a = pow(-1, i)*pow(cos(x), i/2.0)*iOdd/factOdd;
        }
        if(i == 2){
            factEven *= (i+1);
            a = pow(-1, i)*pow(cos(x), i/2.0)*iEven/factEven;
        }
        
        if(i % 2 != 0 && i > 1){
            iOdd *= i;
            factOdd *= (i+1);
            a = pow(-1, i)*pow(cos(x), i/2.0)*iOdd/factOdd;
        }
        else if(i % 2 == 0 && i > 2){
            iEven *= i;
            factEven *= (i+1);
            a = pow(-1, i)*pow(cos(x), i/2.0)*iEven/factEven;
        }
        
        if(abs(a) > E1){
            summaE1 += a;
            count1 += 1;            
        }
    }while(abs(a) > E1);
    
    double E2 = E1*10;
    
    int i = 0;
    a = 0;
    
    // Возвращаю к исходному
    iEven = factEven = 2;
    iOdd = factOdd = 1;
    
    // сумма для E2
    do{
        ++i;
        
        if (i == 1){
            factOdd *= (i+1);
            a = pow(-1, i)*pow(cos(x), i/2.0)*iOdd/factOdd;
        }
        if(i == 2){
            factEven *= (i+1);
            a = pow(-1, i)*pow(cos(x), i/2.0)*iEven/factEven;
        }
        
        if(i % 2 != 0 && i > 1){
            iOdd *= i;
            factOdd *= (i+1);
            a = pow(-1, i)*pow(cos(x), i/2.0)*iOdd/factOdd;
        }
        else if(i % 2 == 0 && i > 2){
            iEven *= i;
            factEven *= (i+1);
            a = pow(-1, i)*pow(cos(x), i/2.0)*iEven/factEven;
        }
        
        if(abs(a) > E2){
            summaE2 += a;
            count2 += 1;            
        }
    }while(abs(a) > E2);
    
    std::cout <<"Сумма первых N элементов равна" <<summaN << "\n";
    std::cout <<"Сумма элементов больших E1 по модулю и их количество" << summaE1 << count1 << "\n";
    std::cout <<"Сумма элементов больших E2 по модулю и их количество" << summaE2 << count2 << "\n";
}
