/*
    Resolución del problema: 06/07/2025
    Función que permite deducir si una fecha leída del teclado es válida.
*/

#include <iostream>
#include <windows.h>
#include <limits>

using namespace std;

// Función para determinar si un año es bisiesto
bool esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// Función que valida una fecha
bool fechaValida (int dia, int mes, int anio){
    if (dia < 1 || mes < 1 || mes > 12 || anio < 1) return false;
    
    int diaEnMes;

    switch (mes) {
        case 2:
            diaEnMes = esBisiesto(anio) ? 29 : 28;
            break;
        case 4: case 6: case 9: case 11:
            diaEnMes = 30;
            break;
        default:
            diaEnMes = 31;
            break;
    }

    return dia <= diaEnMes;
}

// Función para válidar la entrada
int validarEntrada(const string& mensaje){
    int valor;

    while(true){
        cout << mensaje;
        cin >> valor;
        if (!cin.fail()) return valor;
        cout << "Entrada inválida. Intente nuevamente!" << endl;
        cin.clear(); // Limpiar error de la entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer de entrada
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int dia = validarEntrada("Ingrese el día: ");
    int mes = validarEntrada("Ingrese el mes: ");
    int anio = validarEntrada("Ingrese el año: ");

    if (fechaValida(dia, mes, anio)) {
        cout << "La fecha " << dia << "/" << mes << "/" << anio << " es válida." << endl;
    } else {
        cout << "La fecha ingresada no es válida." << endl;
    }

    return 0;
}
