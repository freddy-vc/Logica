/*
    Resolución del pr oblema: 22/06/2025
    Algoritmo que nos calcule el área de un triángulo conociendo sus lados.
*/

#include <iostream>
#include <windows.h>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;

// Función para válidar las entradas
float validarEntrada(const string& mensaje) {
    float valor;
    do {
        cout << mensaje;
        cin >> valor;

        if (cin.fail() || valor <= 0) {
            cin.clear(); // limpiar error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar búfer de entrada
            cout << "Entrada inválida. Ingrese un número positivo.\n";
        }

    } while (valor <= 0);

    return valor;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    float a, b, c, p, area;

    a = validarEntrada("Ingrese la longitud del cateto A: ");
    b = validarEntrada("Ingrese la longitud del cateto B: ");
    c = validarEntrada("Ingrese la longitud de la hipotenusa: ");

    p = (a + b + c) / 2; // Fórmula del semiperimetro

    cout << fixed << setprecision(1); // Imprimir con un decimal

    if (p > a && p > b && p > c) {
        area = sqrt(p * (p - a) * (p - b) * ( p - c)); // Fórmula de Heron para calculár el área de un triángulo conociendo sus lados
        cout << "El área del triángulo es de: "  << area <<  " u²" << endl;
    } else {
        cout << "No es un triángulo" << endl;
    }

    return 0;
}