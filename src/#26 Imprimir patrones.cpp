/*
    Resolución del problema: 04/12/2025
    Escriba un programa que imprima alguno de los siguientes cuatro patrones.
    El tipo de patrón (1 al 4) y el tamaño del patrón (1 al 9) son dados por el usuario.

    type 1          type 2          type 3          type 4
    *               *****           *****               *
    **              ****             ****              **
    ***             ***               ***             ***
    ****            **                 **            ****
    *****           *                   *           *****
*/

#include <iostream>
#include <windows.h>
#include <limits>


using namespace std;

//Función para validar la entrada de un entero
int validarEntrada(const string& mensaje) {
    int valor;
    do {
        cout << mensaje << endl;
        cin >> valor;

        if (cin.fail() || valor <= 0) {
            cin.clear(); // limpiar error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar búfer de entrada
            cout << "Entrada inválida. Ingrese un número positivo.\n";
        }

    } while (valor <= 0);

    return valor;
}

//Función para válidar el tamaño del patron (1-9)
int validarTamano() {
    int tamano;
    do {
        tamano = validarEntrada("Ingrese el tamaño del patron (1-9).");
        if (tamano < 1 || tamano > 9)
            cout << "Tamaño inválido. Debe ser entre 1 y 9.\n";
    } while (tamano < 1 || tamano > 9);

    return tamano;
}

void type1(int size){
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}

void type2(int size){
    for (int i = size; i >= 1; i--){
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }
}

void type3(int size){
    for (int i = size; i >= 1; i--){
        for(int j = size; j > i; j--)
            cout << " ";

        for (int k = 1; k <= i; k++)
            cout << "*";
        cout << endl;
    }
}

void type4(int size){
    for (int i = 1; i <= size; i++) {
        for(int j = size; j > i; j--)
            cout << " ";

        for (int k = 1; k <= i; k++)
            cout << "*";
        cout << endl;
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    int opcion;

    do{
        opcion = validarEntrada("Ingrese el tipo de patron a imprimir (1-4) y 5 para salir.");
        switch (opcion){
        case 1:
            type1(validarTamano());
            break;
        case 2:
            type2(validarTamano());
            break;
        case 3:
            type3(validarTamano());
            break;
        case 4:
            type4(validarTamano());
            break;
        case 5:
            cout << "Saliendo el programa..." << endl;
            break;
        default:
            cout << "Opción invalida!.Por favor ingrese un número del (1-4)." << endl;
            break;
        }
    }while (opcion != 5);

        return 0;
    }