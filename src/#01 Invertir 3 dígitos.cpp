/*
    Resolución de problema: 24/1/2025
    Construya un programa que ingresado un número de 3 dígitos, se obtenga como resultado el
    número ingresado y el inversio de dicho número
*/

#include <iostream>
#include <limits>
#include <windows.h>

using namespace std;

const int MIN_NUMERO = 100;
const int MAX_NUMERO = 999;

int invertirNumero(int numero) {
    int numeroInvertido = (numero % 10) * 100;  // Primer dígito (unidad)
    numero /= 10;
    numeroInvertido += (numero % 10) * 10;      // Segundo dígito (decenas)
    numero /= 10;
    numeroInvertido += numero;                  // Tercer dígito (centenas)
    return numeroInvertido;
}

int obtenerNumeroValido() {
    int numero;
    while (true) {
        cout << "Ingrese un número de 3 dígitos: ";
        cin >> numero;

        if (cin.fail()) {
            cin.clear();  // Limpiar el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no válida. Por favor, ingrese un número entero." << endl;
        } else if (numero >= MIN_NUMERO && numero <= MAX_NUMERO) {
            return numero;
        } else {
            cout << "El número debe tener 3 dígitos." << endl;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int numero = obtenerNumeroValido();

    cout << "El número ingresado es: " << numero << endl;
    cout << "El número invertido es: " << invertirNumero(numero) << endl;

    return 0;
}