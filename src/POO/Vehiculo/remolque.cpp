#include "remolque.h"

Remolque::Remolque() : Automovil(), Trailer(), carroceria("") {}
Remolque::Remolque(const std::string& fabricante, int cantidadLlantas, const std::string& chasis,
    const std::string& placa, float tamanioMotor, float capacidad, 
    const std::string& carroceria) : Automovil(fabricante, cantidadLlantas, chasis, placa, tamanioMotor),
    Trailer(capacidad), carroceria("") {}

std::string Remolque::getCarroceria() const{
    return carroceria;
}

void Remolque::setCarroceria(const std::string& carroceria){
    this->carroceria = carroceria;
}

void Remolque::print(std::ostream& out) const{
    Automovil::print(out);
    Trailer::print(out);
    out << "Carroceria: " << carroceria << std::endl;
}