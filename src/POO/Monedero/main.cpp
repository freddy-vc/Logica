#include "monedero.h"
#include <limits>
#include <windows.h>


int validarEntrada(int min, int max, const std::string& mensaje) {
    int valor;

    while(true){
        std::cout << mensaje;
        std::cin >> valor;

        if (!std::cin.fail() && (valor >= min && valor <= max)) return valor;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout << "Ingrese un número del " << min << " al " << max << ".\n";
    }
}

void crearMovimiento(Monedero& monedero){
    int opcion = validarEntrada(1,2,"\n1. Enviar\n2. Recibir.\n ¿Que tipo de movimiento desea realizar?: ");

    switch (opcion)
    {
    case 1:
        monedero.enviarMoneda();
        break;
    case 2:
        monedero.recibirMoneda();
        break;
    
    default:
        break;
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    Monedero monedero;

    bool salir = false;
    int opcion;

    do{
        std::cout << "=== Menú de Opciones ===\n"
            << "1. Crear moneda.\n"
            << "2. Ver monedas.\n" 
            << "3. Crear movimiendo.\n" 
            << "4. Ver movimientos.\n" 
            << "5. Calcula saldo de una moneda.\n" 
            << "6. Salir del sistema.\n\n";
        
        opcion = validarEntrada(1,6,"Ingrese el número correspondiente a la opción deseada: ");

        switch (opcion){
        case 1:{
            monedero.crearMoneda();
            break;
        }
        case 2:{
            monedero.verMonedas();
            break;
        }
        case 3:{
            crearMovimiento(monedero);
            break;
        }
        case 4:{
            std::cout << monedero.verMovimientos();
            break;
        }
        case 5:{
            /* code */
            break;
        }
        case 6:{
            std::cout << "\nSaliendo del programa...\n";
            salir = true;
            break;
        }
        default:
            break;
        }
        



    }while(!salir);



    return 0;
}