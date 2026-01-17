#include "cuadrado.h"
#include "cubo.h"
#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    Cuadrado cuadrado(5);
    std::cout << cuadrado << std::endl;

    Cubo cubo(7);

    std::cout <<  cubo << std::endl;


    return 0;
}