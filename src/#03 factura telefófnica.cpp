/*
    Resolución de problema: 17/06/2025
    Determinar la cantidad total a pagar por una llamada telefónica, teniendo en cuenta lo siguiente:
    • toda llamada que dure menos de tres minutos (tres pasos) tiene un coste de 10 céntimos,
    • cada minuto adicional a partir de los tres primeros es un paso de contador y cuesta 5 céntimos.
*/

#include <iostream>
#include <windows.h>

using namespace std;

int main () {
    SetConsoleOutputCP(CP_UTF8);

    int duracion_llamada, minutos_adicionales;
    float factura = 0.10;

    do {
        cout << "Ingrese la duración de la llamada (min): ";
        cin >> duracion_llamada;
        if (duracion_llamada <= 0) {
            cout << "Ingrese una duracion positiva" << endl;
        }
    } while (duracion_llamada <= 0);

    if (duracion_llamada > 3) {
            minutos_adicionales = duracion_llamada - 3;
            factura += minutos_adicionales * 0.05;
    }
     cout << "Total a pagar: " << factura << " euros" << endl;

    return 0;
}