/*
    Resolución del ejercicio: 20/07/2025
    Realice un programa que imprima los n primeros números de la serie de Fibonacci
*/


#include <iostream>
#include <windows.h>
#include <iomanip>
#include <limits>

using namespace std;

// Función para validar la cantidad de números a mostrar
int validarEntrada() {
    int cantidad;

    while (true) {
        cout << "Introduzca la cantidad de números a mostrar de la serie Fibonacci: ";
        cin >> cantidad;

        if (!cin.fail() && cantidad > 0) return cantidad;

        cout << "Ingrese una cantidad válida. Intente nuevamente!" << endl;
        cin.clear(); // Limpiar el error de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer de entrada
    }
}

// Función para imprimir la serie de Fibonacci
void imprimirFibonacci(int cantidad) {
    int anterior = 0, actual = 1, siguiente;

    for (int i = 0; i < cantidad; ++i) {
        cout << anterior << setw(5);
        siguiente = anterior + actual;
        anterior = actual;
        actual = siguiente;
    }
    cout << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int cantidad = validarEntrada();
    imprimirFibonacci(cantidad);
    return 0;
}
