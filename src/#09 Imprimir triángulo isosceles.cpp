/*
    Resolución del problema: 24/06/2025
    Escribir un programa que visualice un triángulo isósceles.
                                    *
                                   ***
                                  *****
                                 *******
*/

#include <iostream>
#include <windows.h>
#include <string>
#include <limits>

using namespace std;


int validarEntrada(const string& mensaje) {
    int valor;
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

    int f = validarEntrada("De cuántas filas quieres el triángulo?: ");

    for (int i = 1; i <= f; i++){ // recorre cada fila desde 1 hasta f
        for (int j = f - i; j >= 1; j--){ // imprime los espacios necesarios para imprimir los asteriscos
            cout << ' ';
        }

        for (int k= 1; k < i*2; k++){ // imprime los astericos desde 1, agregandole 2 en 2.
            cout << '*';
        }

        cout << endl; // cambia de linea por cada fila.
    }

    return 0;
}