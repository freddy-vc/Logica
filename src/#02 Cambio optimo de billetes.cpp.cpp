/*
    Resolución de problema: 5/02/2025
    Escriba un programa que calcule el número minimo de billetes 20,10,5,1 dolares que se necesita para cambiar un cheque.
    Considere que el valor del cheque es un numero entero que se debe ingresar por input.
*/

#include <iostream>
#include <windows.h>
#include <limits>

using namespace std;

// Función para calcular los billetes
void calcularBilletes(int cheque) {

    int B20 = cheque / 20;
    cheque %= 20; // Residuo después de extraer billetes de 20
    int B10 = cheque / 10;
    cheque %= 10; // Residuo después de extraer billetes de 10
    int B5 = cheque / 5;
    cheque %= 5; // Residuo después de extraer billetes de 5
    int B1 = cheque; // Lo que queda son billetes de 1

    // Mostrar los resultados
    if (B20 > 0){
        cout << "Se necesitan " << B20 << " billetes de $20" << endl;
    }
    if (B10 > 0) {
        cout << "Se necesitan " << B10 << " billetes de $10" << endl;
    }
    if (B5 > 0) {
        cout << "Se necesitan " << B5 << " billetes de $5" << endl;
    }
    if (B1 > 0) {
        cout << "Se necesitan " << B1 << " billetes de $1" << endl;
    }
}

int main () {
    SetConsoleOutputCP(CP_UTF8);

    int cheque;

    while (true) {
        cout << "Ingrese el valor del cheque a descambiar: " << endl;
        cin >> cheque;

        if(cin.fail()){
            cin.clear(); // Limpiar el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no válida. Por favor, ingrese un número entero positivo." << endl;
        } else if (cheque <= 0){
            cout << "El cheque debe ser un número positivo mayor a 0." << endl;
        } else{
            break;
        }
    }

    calcularBilletes(cheque);

    return 0;
}