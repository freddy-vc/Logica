#include "hora.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Hora Hora1(12, 59, 59);
    Hora Hora2;
    std::cout << "Ingrese los valores de la hora 2 (hh:mm:ss)" << std::endl;
    std::cin >> Hora2;

    std::cout << "Hora 1: " << Hora1 << std::endl;
    std::cout << "Hora 2 " << Hora2 << std::endl;

    std::cout << "Hora 1 en segundos: " << Hora1.TotalSegundos() << std::endl;
    std::cout << "Hora 2 en segundos: " << Hora2.TotalSegundos() << std::endl;

    std::cout << "Hora 1 con preincremento: " << ++Hora1 << std::endl;

    std::cout << "Hora1 - Hora2: " << Hora1 - Hora2 << std::endl;

    std::cout << "Hora1 + 300 segundos: " << (Hora1 += 300)  << std::endl;
    std::cout << "Hora1 - 300 segundos: " << (Hora1 -= 300)  << std::endl;

    return 0;
}