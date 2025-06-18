/*
    Resolución del problema: 17/06/2025
    Se desea calcular independiente la suma de los números pares e impares comprendidos entre 1 y 200.
*/

#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);

    int sumImpar = 0, sumPar = 0, MIN = 1, MAX = 200;

    for (int i = MIN; i <= MAX; i++) {
        (i % 2 == 0) ? sumPar += i : sumImpar += i; //Si "i" es par, se suma a la sumatoria par, sino se suma a la sumatoria impar.
    }

    cout << "Suma de impares: " << sumImpar << endl;
    cout << "Suma de pares: " << sumPar << endl;
    
    return 0;
}
