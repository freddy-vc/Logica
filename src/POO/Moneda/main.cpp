#include "moneda.h"
#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    // Caso 1: Constructores y operador <<
    Moneda m1;              // constructor por defecto
    Moneda m2(3, 50);       // constructor con parámetros

    std::cout << "Caso 1:\n";
    std::cout << "m1 = " << m1 << std::endl;
    std::cout << "m2 = " << m2 << std::endl;

    // Caso 2: Operador +
    Moneda m3 = m2 + Moneda(2, 75);

    std::cout << "\nCaso 2:\n";
    std::cout << "m2 + 2.75 = " << m3 << std::endl;

    // Caso 3: Operador -
    Moneda m4 = m2 - Moneda(5, 00);

    std::cout << "\nCaso 3:\n";
    std::cout << "m2 - 5.00 = " << m4 << std::endl;

    // Caso 4: Operadores *= y /=
    Moneda m5(4, 20);

    std::cout << "\nCaso 4:\n";
    std::cout << "m5 inicial = " << m5 << std::endl;

    m5 *= 2;
    std::cout << "m5 *= 2 -> " << m5 << std::endl;

    m5 /= 2;
    std::cout << "m5 /= 2 -> " << m5 << std::endl;

    // Caso 5: Comparaciones <, > y ==
    Moneda a(3, 50);
    Moneda b(4, 10);
    Moneda c(3, 50);

    std::cout << "\nCaso 5:\n";
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;

    std::cout << "a < b : " << (a < b) << std::endl;
    std::cout << "b > a : " << (b > a) << std::endl;
    std::cout << "a == c : " << (a == c) << std::endl;

    return 0;
}