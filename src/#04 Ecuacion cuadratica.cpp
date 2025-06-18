/*
    Resolución del problema: 17/06/2025
    Diseñar un algoritmo para resolver una ecuación de segundo grado Ax2 + Bx + C = 0
*/
#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);

    double A, B, C, determinante;

    cout << "Ingrese el coeficiente de A: ";
    cin >> A;
    cout << "Ingrese el coeficiente de B: ";
    cin >> B;
    cout << "Ingrese el coeficiente de C: ";
    cin >> C;

    determinante = B*B-4*A*C;

    if (determinante > 0) { //Si el determinante es positivo, tiene 2 soluciones reales.
        double x1 = (-B+sqrt(determinante))/(2.0*A);
        double x2 = (-B-sqrt(determinante))/(2.0*A);
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
    } else if (determinante == 0) { //Si el determinante es igual a cero, tiene una única solución real.
        double x = -B / (2.0*A);
        cout << "Unica solución real: " << x << endl;
    } else { //Si el determinante es negativo, no hay soluciones reales.
        cout << "No tiene soluciones reales!" << endl;
    }

    return 0;
}
