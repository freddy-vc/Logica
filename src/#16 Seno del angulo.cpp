/*
    Resolución del problema: 1/07/2025
    Supuesto que nuestro compilador no tiene la función seno. Podríamos calcular el seno de x mediante la siguiente serie:
    sen(x) = x – (x^3)/3! + (x^5)/5! - (x^7)/7! + ... (hasta 17 términos)
    x (ángulo en radianes).
*/

#include <iostream>
#include <windows.h>

#define M_PI 3.14159265358979323846

using namespace std;

// Función para calcular la potencia de un número
double potencia(double base, int exp) {
    double resultado = 1.0;
    for (int i = 1; i <= exp; ++i) {
        resultado *= base;
    }
    return resultado;
}

// Función para calcular el factorial de un número
double factorial(int n) {
    double resultado = 1.0;
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

// Función para calcular el seno
double sen(double grados) {
    double x = grados * M_PI / 180.0; // Convertir a radianes
    double resultado = 0.0;

    for (int i = 0; i < 17; ++i) {
        int exponente = 2 * i + 1; // Numeros impares
        double termino = potencia(x, exponente) / factorial(exponente);
        if (i % 2 == 0) { // Si el indice es par; se suma, sino, se resta
            resultado += termino;
        } else {
            resultado -= termino;
        }
    }

    return resultado;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double angulo;

    while(true){
        cout << "Ingrese el ángulo en grados: ";
        cin >> angulo;

        if (!cin.fail()) break; 

        cout << "Entrada inválida. Intente nuevamente." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << "El seno aproximado de " << angulo << "° es: " << sen(angulo) << endl;


    return 0;
}
