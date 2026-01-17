#include "forma2d.h"
#include "forma3d.h"
#include "circulo.h"
#include "cilindro.h"
#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    Circulo circulo (5);
    std::cout << circulo << std::endl;

    Cilindro cilindro(10,5);
    std::cout << cilindro;

    return 0;
}