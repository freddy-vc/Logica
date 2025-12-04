/*
    Resolución del problema: 30/06/2025
    El gerente de una compañía automotriz desea determinar el impuesto que va a pagar por cada uno de los automóviles que posee, 
    además del total que va a pagar por cada categoría y por todos los vehículos, basándose en la siguiente clasificación:
    Los vehículos con clave 1 pagan 10% de su valor.
    Los vehículos con clave 2 pagan 7% de su valor.
    Los vehículos con clave 3 pagan 5% de su valor.
*/

#include <iostream>
#include <windows.h>
#include <limits>
#include <iomanip>

using namespace std;

// Función para limpiar errores de entrada
void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Función para pedir la cantidad total de autos
int pedirCantidadDeAutos() {
    int cantidad;
    while (true) {
        cout << "Ingrese la cantidad de automóviles en inventario: ";
        cin >> cantidad;
        if (!cin.fail() && cantidad > 0) return cantidad;

        cout << "Entrada inválida. La cantidad debe ser positiva!" << endl;
        limpiarEntrada();
    }
}

// Función para pedir el precio de un automóvil
float pedirPrecioAutomovil(int n) {
    float precio;
    while (true) {
        cout << "Ingrese el precio del automóvil " << n << ": ";
        cin >> precio;
        if (!cin.fail() && precio > 0) return precio;

        cout << "Entrada inválida. El precio debe ser positivo." << endl;
        limpiarEntrada();
    }
}

// Función para pedir la clave del automóvil (1, 2 o 3)
int pedirClave(int n) {
    int clave;
    while (true) {
        cout << "Ingrese la clave (1, 2 o 3) del vehículo " << n << ": ";
        cin >> clave;
        if (!cin.fail() && (clave >= 1 && clave <= 3)) return clave;

        cout << "Clave inválida. Debe estar entre 1 y 3." << endl;
        limpiarEntrada();
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Soporte para acentos en consola

    int cantidad = pedirCantidadDeAutos();
    int clave;
    float precio, impuesto;

    // Totales por categoría
    float total_cat1 = 0, total_cat2 = 0, total_cat3 = 0;
    float total_general = 0;

    cout << fixed << setprecision(2); // Formato de salida a 2 decimales

    for (int i = 1; i <= cantidad; i++) {
        precio = pedirPrecioAutomovil(i);
        clave = pedirClave(i);

        // Calcular impuesto y acumularlo según clave
        switch (clave) {
            case 1:
                impuesto = precio * 0.10;
                total_cat1 += impuesto;
                break;
            case 2:
                impuesto = precio * 0.07;
                total_cat2 += impuesto;
                break;
            case 3:
                impuesto = precio * 0.05;
                total_cat3 += impuesto;
                break;
        }

        total_general += impuesto;

        // Mostrar resumen del vehículo
        cout << "\n→ Automóvil " << i << ":" << endl;
        cout << "   Precio: $" << precio << " USD" << endl;
        cout << "   Impuesto a pagar: $" << impuesto << " USD" << endl;
    }

    // Mostrar resumen general
    cout << "\n======= RESUMEN GENERAL =======" << endl;
    cout << "Total impuesto categoría 1: $" << total_cat1 << " USD" << endl;
    cout << "Total impuesto categoría 2: $" << total_cat2 << " USD" << endl;
    cout << "Total impuesto categoría 3: $" << total_cat3 << " USD" << endl;
    cout << "Total general de impuestos: $" << total_general << " USD" << endl;

    return 0;
}