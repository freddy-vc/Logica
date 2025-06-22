/*
    Resolución del problema: 21/06/2025
    Calcular la nota media de los alumnos de una clase considerando n-número de alumnos 
    y c-número de notas de cada alumno.
*/

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <limits>

using namespace std;

// Función para calcular la nota media de n alumnos con c notas
float calcularNotaPromedio(int n, int c) {
    float nota, sumaTotal = 0;

    for (int i = 1; i <= n; i++) {
        cout << "\nAlumno " << i << ":" << endl;

        for (int j = 1; j <= c; j++) {
            do {
                cout << "  Ingrese la nota " << j << ": ";
                cin >> nota;

                if (cin.fail() || nota < 0 || nota > 5) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "  ❌ Nota inválida. Ingrese un valor entre 0 y 5." << endl;
                }

            } while (nota < 0 || nota > 5);

            sumaTotal += nota;
        }
    }

    return sumaTotal / (n * c); // Promedio general
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n, c;

    // Validación del número de alumnos
    do {
        cout << "Ingrese la cantidad de alumnos de la clase: ";
        cin >> n;

        if (cin.fail() || n <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Entrada inválida. La cantidad de alumnos debe ser un número entero positivo." << endl;
        }
    } while (n <= 0);

    // Validación del número de notas
    do {
        cout << "Ingrese la cantidad de notas por alumno: ";
        cin >> c;

        if (cin.fail() || c <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Entrada inválida. La cantidad de notas debe ser un número entero positivo." << endl;
        }
    } while (c <= 0);

    cout << fixed << setprecision(2);

    float promedio = calcularNotaPromedio(n, c);

    cout << "\n🎓 La nota promedio del curso es: " << promedio << endl;

    return 0;
}