#include "cuentabancaria.h"
#include <windows.h>
#include <iomanip>
#include <limits>

// Función para validar un número entero
int validarEntrada(const std::string& mensaje) {
    int valor;

    while(true) {
        std::cout << mensaje;
        std::cin >> valor;
        if (!std::cin.fail()) return valor;

        std::cin.clear(); // Limpiar error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer de entrada
        std::cout << "Entrada inválida. Intente nuevamente!" << std::endl;
    }
}

// Funcion para validar la posicion de las cuentas
int validarPosicion(int numCuentas, const std::string& mensaje) {
    int pos;

    while(true){
        pos = validarEntrada(mensaje) - 1;

        if (pos >= 0 && pos < numCuentas) return pos;

        std::cout << "Posición inválida. Debe ser un número entre 1 y " << numCuentas << ".\n";
    }
}

// Funcion para validar el saldo
double validarSaldo(const std::string& mensaje) {
    double saldo;

    while(true) {
        std::cout << mensaje;
        std::cin >> saldo;

        if (!std::cin.fail() && saldo >= 0.0) return saldo;

        std::cin.clear(); // Limpiar error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // Limpiar buffer de entrada
        std::cout << "Entrada inválida. Intente nuevamente, el saldo debe ser positivo" << std::endl;
    }
}

// Funcion para crear una cuenta
CuentaBancaria crearCuenta(int &numCuentas) {
    std::string nom, doc, tipodoc;
    double saldo;
    bool bloqueo;

    std::cout << "\nCreando cuenta..." << std::endl;
    std::cout << "Ingrese el nombre del cliente: " << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, nom);
    std::cout << "Ingrese el tipo de documento del cliente " << std::endl;
    getline(std::cin, tipodoc);
    std::cout << "Ingrese el documento del cliente: " << std::endl;
    getline(std::cin, doc);
    saldo = validarSaldo("Ingrese el saldo: ");
    bloqueo = false;

    std::cout << "Cuenta creada con exito!" << std::endl;
    numCuentas++;

    return CuentaBancaria(nom, doc, tipodoc, saldo, bloqueo);
}

// Función para consignar
void consignar(CuentaBancaria cuentas[], int numCuentas) {
    int cConsignar = validarPosicion(numCuentas, "Ingrese el número de la cuenta a consignar (1-" + std::to_string(numCuentas) + "): ");
    double valor = validarSaldo("Ingrese la cantidad a consignar: ");

    double nuevoSaldo = cuentas[cConsignar].getSaldo() + valor;
    cuentas[cConsignar].setSaldo(nuevoSaldo);

    std::cout << "Consignación exitosa!" << std::endl;
}

// Función para retirar
void retirar(CuentaBancaria cuentas[], int numCuentas) {
    int cRetirar = validarPosicion(numCuentas, "Ingrese el número de la cuenta a retirar (1-" + std::to_string(numCuentas) + "): ");
    double valor;
    while(true) {
        valor = validarEntrada("Ingrese la cantidad a retirar: ");
        if (cuentas[cRetirar].getSaldo() >= valor) 
            break;

        std::cout << "La cantidad a retirar supera el saldo. Intente nuevamente!" << std::endl;
    }
    double nuevoSaldo = cuentas[cRetirar].getSaldo() - valor;
    cuentas[cRetirar].setSaldo(nuevoSaldo);

    std::cout << "Retiro exitoso!" << std::endl;
}

// Función para mostrar saldos
void mostrarCuentas(CuentaBancaria cuentas[], int numCuentas){
    for(int i = 0; i < numCuentas; i++) {
        std::cout << cuentas[i].toString();
    }
}

// Función para eliminar una cuenta
void eliminarCuenta(CuentaBancaria cuentas[], int& numCuentas) {
    int cEliminar = validarPosicion(numCuentas, "Ingrese la posición de la cuenta a eliminar (1-" + std::to_string(numCuentas) + "): ");

    for (int i = cEliminar; i < numCuentas - 1; i++) {
        cuentas[i] = cuentas[i + 1]; // Correr las cuentas hacia la izquierda del arreglo
    }

    cuentas[numCuentas - 1].resetear(); // Resetear la última cuenta (posición sobrante)

    std::cout << "Cuenta eliminada con exito!" << std::endl;
    numCuentas--; // Reducir el contador de las cuentas
}


int main() {
    SetConsoleOutputCP(CP_UTF8);

    CuentaBancaria cuentas[3]; // Limite de cuentas bancarias

    // Precargar 2 cuentas
    cuentas[0] = CuentaBancaria("Freddy Vega", "123417402", "CC", 1430000, false);
    cuentas[1] = CuentaBancaria("Nidia Cisneros", "147234010", "CC", 21722000, true);

    int numCuentas = 2; // Contador de cuentas bancarias

    bool salir = false;

    while(!salir) {
        std::cout << "Menú: " << std::endl;
        std::cout << "1. Crear cuenta bancaria." << std::endl;
        std::cout << "2. Bloquear cuenta." << std::endl;
        std::cout << "3. Retiro/consignaciones" << std::endl;
        std::cout << "4. Mostrar saldos." << std::endl;
        std::cout << "5. Eliminar cuenta." << std::endl;
        std::cout << "6. Salir" << std::endl;

        int opcion = validarEntrada("¿Qué desea realizar?: ");

        switch (opcion) {
        case 1: {
            if (numCuentas >= 3) {
                std::cout << "Ya se han creado las 3 cuentas permitidas." << std::endl;
                break;
            }
            cuentas[numCuentas] = crearCuenta(numCuentas);
            break;
        }
        case 2: {
            if (numCuentas == 0){
                std::cout << "No hay cuentas para bloquear!" << std::endl;
                break;
            }

            int bloqCuenta = validarPosicion(numCuentas, "Ingrese la posición de la cuenta a bloquear o desbloquear (1-" + std::to_string(numCuentas) + "): ");
            cuentas[bloqCuenta].bloquearCuenta();
            break;
        }
        case 3: {
            if (numCuentas == 0){
                std::cout << "No hay cuentas para consignar o retirar!" << std::endl;
                break;
            }

            while(true) {
                std::cout << "\n1. Retirar.\n2. Consignar.\n3. Salir.\n";
                int op = validarEntrada("¿Que desea realizar?: ");

                if (op == 3) {
                    std::cout << "Saliendo del submenú de retiro/consignar..." << std::endl; 
                    break;
                }
                switch (op) {
                case 1:
                    retirar(cuentas, numCuentas);
                    break;
                case 2:
                    consignar(cuentas, numCuentas);
                    break;
                default:
                    std::cout << "Opción inválida. Intente nuevamente!" << std::endl;
                    break;
                }
            }
            break;
        }
        case 4: {
            if (numCuentas == 0){
                std::cout << "No hay cuentas para mostrar!" << std::endl;
                break;
            }
            mostrarCuentas(cuentas, numCuentas);
            break;
        }
        case 5: {
            if (numCuentas == 0){
                std::cout << "No hay cuentas para eliminar!" << std::endl;
                break;
            }
            eliminarCuenta(cuentas, numCuentas);
            break;
        }
        case 6:
            std::cout << "Saliendo del programa..." << std::endl;
            salir = true;
            break;
        
        default:
            std::cout << "Opcion inválida. Ingrese un número del (1-6)" << std::endl;
            break;
        }
    }

    return 0;
}
