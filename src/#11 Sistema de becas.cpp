/*
    Resolución del problema: 27/06/2025
    El presidente de la república ha decidido estimular a todos los estudiantes de una universidad mediante la asignación de becas mensuales, 
    para esto se tomarán en consideración los siguientes criterios:
    Para alumnos mayores de 18 años con promedio mayor o igual a 9, la beca será de $2000; con promedio mayor o igual a 7.5, de $1000;
    para los promedios menores de 7.5 pero mayores o iguales a 6.0, de $500; a los demás se les enviará una carta de invitación incitándolos 
    a que estudien más en el próximo ciclo escolar.
    A los alumnos de 18 años o menores de esta edad, con promedios mayores o iguales a 9, se les dará $3000; con promedios menores a 9 
    pero mayores o iguales a 8, $2000; para los alumnos con promedios menores a 8 pero mayores o iguales a 6, se les dará $100, y a 
    los alumnos que tengan promedios menores a 6 se les enviará carta de invitación.
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <windows.h>

using namespace std;

void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int pedirEdad() {
    int edad;
    while (true) {
        cout << "Ingrese la edad del estudiante: ";
        cin >> edad;
        if (!cin.fail() && edad > 0) return edad;

        cout << "Entrada inválida. La edad debe ser mayor que 0." << endl;
        limpiarEntrada();
    }
}

float pedirPromedio() {
    float promedio;
    while (true) {
        cout << "Ingrese el promedio del estudiante (0 - 10): ";
        cin >> promedio;
        if (!cin.fail() && promedio >= 0 && promedio <= 10) return promedio;

        cout << "Entrada inválida. El promedio debe estar entre 0 y 10." << endl;
        limpiarEntrada();
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int edad = pedirEdad();
    float promedio = pedirPromedio();
    float beca = 0;

    cout << fixed << setprecision(2);

    if (edad > 18) {
        if (promedio >= 9.0)
            beca = 2000;
        else if (promedio >= 7.5)
            beca = 1000;
        else if (promedio >= 6.0)
            beca = 500;
    } else {
        if (promedio >= 9.0)
            beca = 3000;
        else if (promedio >= 8.0)
            beca = 2000;
        else if (promedio >= 6.0)
            beca = 100;
    }

    if (beca > 0)
        cout << "Usted recibirá una beca de $" << beca << " USD mensuales." << endl;
    else
        cout << "Te invitamos a que te esfuerces más en el próximo ciclo escolar." << endl;

    return 0;
}