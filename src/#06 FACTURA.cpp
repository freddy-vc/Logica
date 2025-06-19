/*
    Resolución del problema: 19/06/2025
    Escribir un algoritmo que permita emitir la factura correspondiente a una compra de un artículo determinado, 
    del que se adquieren una o varias unidades. El IVA a aplicar es del 15 por 100 y si el precio bruto (precio venta más IVA)
    es mayor de 1.000 euros, se debe realizar un descuento del 5 por 100.
*/

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <limits> 

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    string producto;
    int cantidad;
    float precio_unitario, precio_bruto, subtotal, descuento = 0.0, IVA, total;

    cout << "Ingrese el nombre del producto: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, producto);

    while (producto.empty()) {
        cout << "❌ El nombre del producto no puede estar vacío. Intente de nuevo: ";
        getline(cin, producto);
    }

    // Leer el precio unitario
    do {
        cout << "Ingrese el precio por unidad del producto: ";
        cin >> precio_unitario;

        if (cin.fail() || precio_unitario <= 0) {
            cin.clear(); // Eliminar los flags de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer con los carácteres que causaron el error
            cout << "❌ Entrada inválida. El precio debe ser un número positivo.\n";
        }

    } while (precio_unitario <= 0);

    // Leer cantidad
    do {
        cout << "Ingrese la cantidad a comprar: ";
        cin >> cantidad;

        if (cin.fail() || cantidad <= 0) {
            cin.clear(); // Eliminar los flags de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer con los carácteres que causaron el error
            cout << "❌ Entrada inválida. La cantidad debe ser un número entero positivo.\n";
        }

    } while (cantidad <= 0);

    // Cálculos
    subtotal = precio_unitario * cantidad;
    IVA = subtotal * 0.15;
    precio_bruto = subtotal + IVA;

    if (precio_bruto > 1000) {
        descuento = precio_bruto * 0.05;
    }

    total = precio_bruto - descuento;

    cout << fixed << setprecision(2); // mostrar 2 decimales

    // Imprimir factura
    cout << "\n+-------- FACTURA --------+" << endl;
    cout << "Producto: " << producto << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Subtotal sin IVA: " << subtotal << " euros" << endl;
    cout << "IVA (15%): " << IVA << " euros" << endl;
    cout << "Precio bruto (con IVA): " << precio_bruto << " euros" << endl;

    if (descuento > 0) {
        cout << "Descuento aplicado (5%): -" << descuento << " euros" << endl;
    }

    cout << "Total a pagar: " << total << " euros" << endl;
    cout << "+-------------------------+" << endl;

    return 0;
}
