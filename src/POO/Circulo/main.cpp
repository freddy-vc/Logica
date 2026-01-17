#include "circulo.h"
#include "esfera.h"
#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    Circulo cir(5);

    std::cout << cir << std::endl;

    Esfera esf(5);

    std::cout << esf << std::endl;

    return 0;
}