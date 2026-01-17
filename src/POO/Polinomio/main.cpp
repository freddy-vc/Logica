#include <iostream>
#include <windows.h>
#include <limits>
#include "polinomio.h"

using namespace std;

// Función para válidar la entrada
int validarEntrada(const string &mensaje)
{
    int valor;

    while (true)
    {
        cout << mensaje;
        cin >> valor;

        if (!cin.fail())
            return valor;

        cin.clear();                                         // Limpiar error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer de entrada
        cout << "Entrada inválida. Debe ingresar un número entero.\n";
    }
}

// Validar posición del polinomio
int validarPosicion(int numPolinomios, const string &mensaje)
{
    int pos;

    while (true)
    {
        pos = validarEntrada(mensaje) - 1;

        if (pos >= 0 && pos < numPolinomios)
            return pos;

        cout << "Posición inválida. Debe ser un número entre 1 y " << numPolinomios << ".\n";
    }
}

// Función para ingresar los 5 coeficientes
Polinomio crearPolinomioDesdeEntrada()
{
    int c4 = validarEntrada("  Ingrese coeficiente de x^4: ");
    int c3 = validarEntrada("  Ingrese coeficiente de x^3: ");
    int c2 = validarEntrada("  Ingrese coeficiente de x^2: ");
    int c1 = validarEntrada("  Ingrese coeficiente de x^1: ");
    int c0 = validarEntrada("  Ingrese coeficiente de x^0: ");
    return Polinomio(c4, c3, c2, c1, c0);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Polinomio polinomios[3];
    int numPolinomios = 0;

    bool salir = false;

    while (!salir)
    {

        cout << "\n========= MENÚ DE POLINOMIOS =========\n";
        cout << "1. Crear un nuevo polinomio\n";
        cout << "2. Editar un polinomio existente\n";
        cout << "3. Mostrar un polinomio\n";
        cout << "4. Multiplicar un polinomio por un escalar\n";
        cout << "5. Mostrar el coeficiente mayor entre los polinomios creados\n";
        cout << "6. Salir\n";
        cout << "=======================================\n";

        int opcion = validarEntrada("Seleccione una opción: ");

        switch (opcion)
        {

        // 1. CREAR POLINOMIO
        case 1:
        {
            if (numPolinomios >= 3)
            {
                cout << "Ya existen los 3 polinomios permitidos. No se pueden crear más.\n";
                break;
            }

            cout << "\nCreación de polinomio (" << numPolinomios + 1 << "/3)\n";
            polinomios[numPolinomios] = crearPolinomioDesdeEntrada();
            numPolinomios++;

            cout << "Polinomio creado con éxito.\n";
            break;
        }

        // 2. EDITAR POLINOMIO
        case 2:
        {
            if (numPolinomios == 0)
            {
                cout << "No hay polinomios creados para editar.\n";
                break;
            }

            cout << "\nEditar polinomio\n";
            string mensajeEditar = "Seleccione polinomio (1-" + to_string(numPolinomios) + "): ";
            int pEditar = validarPosicion(numPolinomios, mensajeEditar);
            polinomios[pEditar] = crearPolinomioDesdeEntrada();

            cout << "Polinomio actualizado correctamente.\n";
            break;
        }

        // 3. MOSTRAR POLINOMIO
        case 3:
        {
            if (numPolinomios == 0)
            {
                cout << "No existen polinomios para mostrar.\n";
                break;
            }

            cout << "\nMostrar polinomio\n";
            string mensajeMostrar = "Seleccione polinomio (1-" + to_string(numPolinomios) + "): ";
            int pMostrar = validarPosicion(numPolinomios, mensajeMostrar);

            polinomios[pMostrar].imprimir();
            break;
        }

        // 4. MULTIPLICAR POR ESCALAR
        case 4:
        {
            if (numPolinomios == 0)
            {
                cout << "No existen polinomios para multiplicar.\n";
                break;
            }

            cout << "\nMultiplicar polinomio por escalar\n";
            string mensajeMul = "Seleccione polinomio (1-" + to_string(numPolinomios) + "): ";
            int pMul = validarPosicion(numPolinomios, mensajeMul);

            int escalar = validarEntrada("Ingrese escalar: ");

            cout << "Polinomio original: ";
            polinomios[pMul].imprimir();

            polinomios[pMul].multiplicarPorEscalar(escalar);

            cout << "Resultado: ";
            polinomios[pMul].imprimir();

            break;
        }

        // 5. COEFICIENTE MAYOR ENTRE TODOS
        case 5:
        {
            if (numPolinomios == 0)
            {
                cout << "No hay polinomios creados.\n";
                break;
            }

            cout << "\nMayor coeficiente entre todos los polinomios\n";

            int mayor = numeric_limits<int>::min();

            for (int i = 0; i < numPolinomios; i++)
            {

                if (polinomios[i].coeficiente4 > mayor)
                    mayor = polinomios[i].coeficiente4;

                if (polinomios[i].coeficiente3 > mayor)
                    mayor = polinomios[i].coeficiente3;

                if (polinomios[i].coeficiente2 > mayor)
                    mayor = polinomios[i].coeficiente2;

                if (polinomios[i].coeficiente1 > mayor)
                    mayor = polinomios[i].coeficiente1;

                if (polinomios[i].coeficiente0 > mayor)
                    mayor = polinomios[i].coeficiente0;
            }

            cout << "El coeficiente mayor es: " << mayor << "\n";
            break;
        }

        // 6. SALIR
        case 6:
        {
            cout << "Saliendo del programa...\n";
            salir = true;
            break;
        }

        default:
            cout << "Opción no válida. Intente nuevamente.\n";
            break;
        }
    }

    return 0;
}
