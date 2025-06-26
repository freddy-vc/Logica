/*
    Resolución al ejercicio: 25/06/2025
    El dueño de un estacionamiento requiere el algoritmo que le permita determinar cuánto debe cobrar
    por el uso del estacionamiento a sus clientes. Las tarifas que se tienen son:
    Las dos primeras horas a $5 c/u.
    Las siguientes tres a $4 c/u.
    Las cinco siguientes a $3 c/u.
    Después de diez horas el costo por cada una es de $2 c/u.
*/

#include <iostream>
#include <windows.h>
#include <limits>

using namespace std;

// Función para validar la entrada.
int validarEntrada (const string& mensaje){
    int valor;

    do{
        cout << mensaje;
        cin >> valor;

        if(cin.fail() || valor <= 0){
            cin.clear(); // Limpia el error si lee un valor diferente a un entero.
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); // Limpia el buffer
            cout << "Entrada inválida. Las horas deben ser un valor entero positivo." << endl;
        }
    }while(valor <= 0);

    return valor;
}


int main(){

    int horas = validarEntrada("Ingrese la cantidad de horas de uso del estacionamiento: ");
    float total_a_cobrar = 0;

    if (horas <= 2){
        total_a_cobrar = horas * 5;
    } else if (horas <= 5){
        total_a_cobrar = (horas - 2) * 4 + (2 * 5);
    } else if (horas <= 10){
        total_a_cobrar = (horas - 5) * 3 + (3 * 4) + (2 *5);
    } else {
        total_a_cobrar = (horas - 10) * 2 + (5 * 3) + (3 * 4) + (2 * 5);
    }

    cout << "El total a cobrar es de: " << total_a_cobrar << " euros" << endl;
    

    return 0;
}