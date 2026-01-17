#include "monedero.h"
#include <limits>
#include <random>
#include <ctime>
#include <sstream>

std::string generarToken(int longitud) {
    const std::string caracteres =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, caracteres.size() - 1);

    std::string token;
    for (int i = 0; i < longitud; i++) {
        token += caracteres[dist(gen)];
    }
    return token;
}

Monedero::Monedero() : monedas(), movimientos() {}

void Monedero::crearMoneda() {
    std::string identificador, nombre;

    std::cout << "Ingrese el identificador de la moneda: ";
    std::cin.ignore();
    getline(std::cin, identificador);

    std::cout << "Ingrese el nombre de la moneda: ";
    std::cin.ignore();
    getline(std::cin, nombre);

    monedas.push_back(CriptoMoneda(identificador, nombre));

    std::cout << "\n¡Moneda creada exitosamente!\n\n";
}

void Monedero::verMonedas() {
    if(!monedas.empty()){
        std::cout << "\nMonedas disponibles:\n";
        for(int i = 0; i < monedas.size(); i++) {
            std::cout << i << ". " << monedas[i];
        }
    } else {
        std::cout << "\n¡No hay monedas disponibles!\n\n";
    }
}

void Monedero::editarMoneda() {
    if(!monedas.empty()){
        int index;

        while(true){
            std::cout << "\nMonedas disponibles:\n";
            for(int i = 0; i < monedas.size(); i++) {
                std::cout << i << ". " << monedas[i];
            }

            std::cout << "Ingrese el número de la moneda a editar: ";
            std::cin >> index;

            if (!std::cin.fail() && (index >= 0 && index <= (monedas.size() - 1))) {
                std::string newId, newNombre;

                std::cout << "Ingrese el nuevo identificador de la moneda: ";
                std::cin.ignore();
                getline(std::cin, newId);

                std::cout << "Ingrese el nuevo nombre de la moneda: ";
                std::cin.ignore();
                getline(std::cin, newNombre);

                monedas[index].setIdentificador(newId);
                monedas[index].setNombre(newNombre);

                std::cout << "\n¡Moneda editada correctamente!\n\n";

                return;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "\nIngrese un número entre el 0 y el " << (monedas.size() - 1) << ".\n\n";
        }
    } else {
        std::cout << "\n¡No hay monedas disponibles para editar!\n\n";
    }
}

void Monedero::eliminarMoneda() {
    if(!monedas.empty()){
        int index;

        while(true){
            std::cout << "\nMonedas disponibles:\n";
            for(int i = 0; i < monedas.size(); i++) {
                std::cout << i << ". " << monedas[i];
            }

            std::cout << "Ingrese el número de la moneda a eliminar: ";
            std::cin >> index;

            if (!std::cin.fail() && (index >= 0 && index <= (monedas.size() - 1))) {
                monedas.erase(monedas.begin() + index);

                std::cout << "\n¡Moneda eliminada correctamente!\n\n";

                return;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "\nIngrese un número entre el 0 y el " << (monedas.size() - 1) << ".\n\n";
        }
    } else {
        std::cout << "\n¡No hay monedas disponibles para eliminar!\n\n";
    }
}
        
void Monedero::enviarMoneda() {
    if(!monedas.empty()){
        int index;
        CriptoMoneda moneda;

        Transaccion* newTransaccion;
        std::string token;
        std::string fecha_hora;

        double valor;

        bool salir = false;
        
        while(!salir){
            std::cout << "\nMonedas disponibles:\n";
            for(int i = 0; i < monedas.size(); i++) {
                std::cout << i << ". " << monedas[i];
            }

            std::cout << "Ingrese el número de la moneda a enviar: ";
            std::cin >> index;

            if (!std::cin.fail() && (index >= 0 && index <= (monedas.size() - 1))) {
                moneda = monedas[index];

                salir = true;
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "\nIngrese un número entre el 0 y el " << (monedas.size() - 1) << ".\n\n";
            }
        }

        salir = false;

        while(!salir){
            std::cout << "Ingrese la cantidad a enviar: ";
            std::cin >> valor;

            if (!std::cin.fail() && valor > 0) {
                salir = true;
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "\nIngrese una cantidad positiva.\n\n";
            }
        }

        token = generarToken(16);

        time_t timer;
        time (&timer);
        fecha_hora = ctime(&timer);

        newTransaccion = new Enviar(token, fecha_hora);
        
        Movimiento newMovimiento(moneda, newTransaccion, valor);

        movimientos.push_back(newMovimiento);

        std::cout << "\n¡Monedas enviadas exitosamente!\n\n";
    } else {
        std::cout << "\n¡No hay monedas disponibles para enviar!\n\n";
    }
}

void Monedero::recibirMoneda() {
    if(!monedas.empty()){
        int index;
        CriptoMoneda moneda;

        Transaccion* newTransaccion;
        std::string token;
        std::string fecha_hora;

        double valor;

        bool salir = false;
        
        while(!salir){
            std::cout << "\nMonedas disponibles:\n";
            for(int i = 0; i < monedas.size(); i++) {
                std::cout << i << ". " << monedas[i];
            }

            std::cout << "Ingrese el número de la moneda a recibir: ";
            std::cin >> index;

            if (!std::cin.fail() && (index >= 0 && index <= (monedas.size() - 1))) {
                moneda = monedas[index];

                salir = true;
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "\nIngrese un número entre el 0 y el " << (monedas.size() - 1) << ".\n\n";
            }
        }

        salir = false;

        while(!salir){
            std::cout << "Ingrese la cantidad a recibir: ";
            std::cin >> valor;

            if (!std::cin.fail() && valor > 0) {
                salir = true;
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "\nIngrese una cantidad positiva.\n\n";
            }
        }

        token = generarToken(16);

        time_t timer;
        time (&timer);
        fecha_hora = ctime(&timer);

        newTransaccion = new Recibir(token, fecha_hora);
        
        Movimiento newMovimiento(moneda, newTransaccion, valor);

        movimientos.push_back(newMovimiento);

        std::cout << "\n¡Monedas enviadas exitosamente!\n\n";
    } else {
        std::cout << "\n¡No hay monedas disponibles para recibir!\n\n";
    }  
}

std::string Monedero::verMovimientos() {
    std::stringstream ss;

    ss << "\nEnviados:\n";
    for(Movimiento& m : movimientos){
        if(m.getTransaccion()->getTipo() == 1) {
            ss << "* "  << m;
        }
    }

    ss << "\nRecibidos:\n";
    for(Movimiento& m : movimientos){
        if(m.getTransaccion()->getTipo() == 2) {
            ss << "* "  << m;
        }
    }

    return ss.str();
}


