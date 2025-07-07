/*
    Resolución del problema: 02/07/2025
    Imprimir los n primeros numeros primos
*/

#include <iostream>
#include <windows.h>
#include <limits>

using namespace std;

bool esPrimo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++ ){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

int pedirCantidad(){
    int n;
    while(true){
        cout << "Ingrese la cantidad de numeros primos a imprimir: ";
        cin >> n;
        if (!cin.fail() && n > 0) return n;
        cout << "Entrada inválida. La cantidad debe ser positiva!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return n;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n = pedirCantidad();
    int numero = 2;
    int contador = 0;

    while (contador < n){
        if (esPrimo(numero)){
            cout << numero << '\t';
            contador++;
        }
        numero++;
    }
    return 0;
}