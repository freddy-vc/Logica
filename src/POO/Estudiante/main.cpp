#include "estudiante.h"
#include <iostream>
#include <windows.h>
#include <limits>

// Validar entrada de un entero
int validarEntrada(const std::string& mensaje) {
    int valor;
    while(true) {
        std::cout << mensaje;
        std::cin >> valor;

        if (!std::cin.fail()) return valor;

        std::cin.clear(); // Limpiar error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // Limpiar buffer de entrada
        std::cout << "Entrada inválida. Intente nuevamente!" << std::endl;
    }
}

float validarNota(const std::string& mensaje) {
    float nota;

    while(true) {
        std::cout << mensaje;
        std::cin >> nota;

        if (!std::cin.fail() || (nota >= 0.0 && nota <= 5.0)) return nota;

        std::cin.clear(); // Limpiar error
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // Limpiar buffer de entrada
        std::cout << "Entrada inválida. Intente nuevamente, la nota debe estar entre 0 y 5!" << std::endl;

    }
}

// Crear estudiante desde entrada
Estudiante crearEstudiante() {
    std::string nom, doc, tipodoc, asig;

    std::cout << "Ingrese el nombre del estudiante: ";
    getline(std::cin, nom);
    std::cout << "Ingrese el número de documento del estudiante: ";
    getline(std::cin, doc);
    std::cout << "Ingrese el tipo de documento del estudiante: ";
    getline(std::cin, nom);
    std::cout << "Ingrese la asignatura del estudiante: ";
    getline(std::cin, nom);
    float nota1 = validarNota("Ingrese la nota del corte 1: ");
    float nota2 = validarNota("Ingrese la nota del corte 2: ");
    float nota3 = validarNota("Ingrese la nota del corte 3: ");

    return Estudiante(nom, doc, tipodoc, asig, nota1, nota2, nota3);
}

// Validar posición del estudiante
int validarPosicion(int numEstudiantes, const std::string &mensaje)
{
    int pos;

    while (true)
    {
        pos = validarEntrada(mensaje) - 1;

        if (pos >= 0 && pos < numEstudiantes)
            return pos;

        std::cout << "Posición inválida. Debe ser un número entre 1 y " << numEstudiantes << ".\n";
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Estudiante estudiantes[3]; // 3 Estudiantes permitidos
    estudiantes[0] = Estudiante("Freddy Vega", "113472841", "CC", "POO", 3.7, 4.4, 4.1);
    estudiantes[1] = Estudiante("Nidia Cisneros", "113412341", "CC", "EDD", 3.1, 3.9, 3.7);

    int numEstudiantes = 2; //Contador de estudiantes

    bool salir = false;

    while(!salir) {

        std::cout << "Menú:" << std::endl;
        std::cout << "1. Crear un estudiante" << std::endl;
        std::cout << "2. Modificar datos" << std::endl;
        std::cout << "3. Mostrar datos estudiante" << std::endl;
        std::cout << "4. Eliminar estudiante" << std::endl;
        std::cout << "5. Salir" << std::endl;

        int opcion = validarEntrada("¿Que desea realizar?: ");
        
        switch (opcion) {
        
        case 1: {
            if (numEstudiantes >= 3) {
                std::cout << "Ya se han creado 3 los estudiantes permitidos." << std::endl;
                break;
            }

            std::cout << "\nCreación del estudiante (" << numEstudiantes + 1 << "/3)\n";
            estudiantes[numEstudiantes] = crearEstudiante();
            numEstudiantes++;

            break;
        }

        case 2: {
            if (numEstudiantes == 0) {
                std::cout << "No hay estudiantes para editar\n";
                break;
            }

            int estEditar = validarPosicion(numEstudiantes, "Seleccione el estudiante a editar (1-" + std::to_string(numEstudiantes) + "): ");
            estudiantes[estEditar] = crearEstudiante();
            std::cout << "Estudiante actualizado correctamente." << std::endl;

            break;
        }
        case 3: {
            if (numEstudiantes == 0) {
                std::cout << "No hay estudiantes para mostrar." << std::endl;
                break;
            }

            int estMostrar = validarPosicion(numEstudiantes, "Seleccione el estudiante a mostrar (1-" + std::to_string(numEstudiantes) + "): ");
            std::cout << estudiantes[estMostrar].toString();

            break;
        }
        case 4: {
            if (numEstudiantes == 0) {
                std::cout << "No hay estudiantes para eliminar." << std::endl;
                break;
            }

            int estEliminar = validarPosicion(numEstudiantes, "Seleccione el estudiante a eliminar (1-" + std::to_string(numEstudiantes) + "): ");
            
            for (int i = estEliminar; i < numEstudiantes - 1; i++) {
                estudiantes[i] = estudiantes [i+1]; // Correr estudiantes hacia la izquierda
            }

            // Resetear el último estudiante
            estudiantes[numEstudiantes - 1].resetear();

            // Reducir el contador de estudiantes
            numEstudiantes--;

            break;
        }
        case 5: {
            std::cout << "\nSaliendo del programa..." << std::endl;
            salir = true;
            break;
        }
        default:
            std::cout << "Opción inválida debe ser un número del 1 al 5. Intente nuevamente!" << std::endl;
            break;
        }
    }

    return 0;
}