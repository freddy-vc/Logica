/*
    Resolución al ejercicio: 27/06/2025
    Cierta empresa proporciona un bono mensual a sus trabajadores, el cual puede ser por su antigüedad o bien por el monto de su 
    sueldo (el que sea mayor), de la siguiente forma: 
    Cuando la antigüedad es mayor a 2 años pero menor a 5, se otorga 20 % de su sueldo; cuando es de 5 años o más, 30 %. 
    Ahora bien, el bono por concepto de sueldo, si éste es menor a $1000, se da 25 % de éste, cuando éste es mayor a $1000, 
    pero menor o igual a $3500, se otorga 15% de su sueldo, para más de $3500. 10%. 
    Realice el algoritmo correspondiente para calcular los dos tipos de bono, asignando el mayor.
*/

#include <iostream>
#include <windows.h>
#include <limits>
#include <iomanip>

using namespace std;

// Función para limpiar la entrada en caso de fallos.
void limpiarEntrada(){
    cin.clear(); // Limpia el error de entrada
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer de entrada
}

// Función para pedir la antigüedad del trabajador
int pedirAntiguedad(){
    int antiguedad;
    while (true) {
        cout << "Ingrese la antigüedad del trabajador (años): ";
        cin >> antiguedad;
        if (!cin.fail() && antiguedad >= 0) return antiguedad;

        cout << "Entrada inválida. La antigüedad debe ser positiva." << endl;
        limpiarEntrada();
    }
}

// Función para pedir el sueldo del trabajador
float pedirSueldo(){
    float sueldo;
    while (true) {
        cout << "Ingrese el sueldo del trabajador: $";
        cin >> sueldo;
        if (!cin.fail() && sueldo >= 0) return sueldo;

        cout << "Entrada inválida. El sueldo debe ser positivo." << endl;
        limpiarEntrada();
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8); // Permitir caracteres UTF-8 en Windows

    int antiguedad = pedirAntiguedad();
    float sueldo = pedirSueldo();
    float bonoAntiguedad = 0, bonoSueldo = 0, bonoFinal;

    cout << fixed << setprecision(2);

    // Calcular bono por antigüedad
    if (antiguedad >= 5)
        bonoAntiguedad = sueldo * 0.30;
    else if (antiguedad > 2)
        bonoAntiguedad = sueldo * 0.20;

    // Calcular bono por sueldo
    if (sueldo < 1000)
        bonoSueldo = sueldo * 0.25;
    else if (sueldo <= 3500)
        bonoSueldo = sueldo * 0.15;
    else
        bonoSueldo = sueldo * 0.10;

    // Escoger el mayor de los dos bonos
    bonoFinal = (bonoAntiguedad > bonoSueldo) ? bonoAntiguedad : bonoSueldo;

    // Mostrar resultados
    cout << "\nBono por antigüedad: $" << bonoAntiguedad << " USD" << endl;
    cout << "Bono por sueldo: $" << bonoSueldo << " USD" << endl;
    cout << "El bono asignado será: $" << bonoFinal << " USD" << endl;

    return 0;
}