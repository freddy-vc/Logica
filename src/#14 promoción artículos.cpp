/*
    Resolución del problema: 29/06/2025
    Realice el algoritmo para determinar cuánto pagará una persona que adquiere N artículos, los cuales están de promoción. 
    Considere que si su precio es mayor o igual a $200 se le aplica un descuento de 15%, y si su precio es mayor a $100 pero menor a $200, 
    el descuento es de 12%; de lo contrario, sólo se le aplica 10%. Se debe saber cuál es el costo y el descuento que tendrá cada uno de 
    los artículos y finalmente cuánto se pagará por todos los artículos obtenidos.
*/

#include <iostream>
#include <windows.h>
#include <limits>
#include <iomanip>

using namespace std;

void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int pedirCantidadDeArticulos(const string& mensaje) {
    int n;
    while (true) {
        cout << mensaje;
        cin >> n;
        if (!cin.fail() && n > 0) return n;
        cout << "Entrada inválida. La cantidad debe ser positiva." << endl;
        limpiarEntrada();
    }
}

float pedirPrecioArticulo(int numeroArticulo) {
    float precio;
    while (true) {
        cout << "Ingrese el precio del artículo " << numeroArticulo << ": $";
        cin >> precio;
        if (!cin.fail() && precio > 0) return precio;
        cout << "Entrada inválida. El precio debe ser positivo." << endl;
        limpiarEntrada();
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n = pedirCantidadDeArticulos("Ingrese la cantidad de artículos a pagar: ");
    float precio, descuento, precioFinal, total_a_pagar = 0;

    cout << fixed << setprecision(2);

    for (int i = 1; i <= n; i++) {
        precio = pedirPrecioArticulo(i);

        // Determinar descuento
        if (precio >= 200) {
            descuento = precio * 0.15;
        } else if (precio > 100) {
            descuento = precio * 0.12;
        } else {
            descuento = precio * 0.10;
        }

        precioFinal = precio - descuento;
        total_a_pagar += precioFinal;

        // Mostrar detalle del artículo
        cout << "Artículo #" << i << ": \n";
        cout << "Precio original: $" << precio << endl;
        cout << "Descuento aplicado: $" << descuento << endl;
        cout << "Precio final: $" << precioFinal << endl << endl;
    }

    // Total a pagar
    cout << "Total a pagar por los " << n << " artículos: $" << total_a_pagar << " USD." << endl;

    return 0;
}
