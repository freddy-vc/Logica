#include "vehiculo.h"

Vehiculo::Vehiculo() : fabricante(""), chasis(""), cantidadLlantas(0) {}

Vehiculo::Vehiculo(const std::string& fabricante, int cantidadLlantas, 
    const std::string& chasis) : fabricante(fabricante), cantidadLlantas(cantidadLlantas), 
    chasis(chasis) {}

std::string Vehiculo::getFabricante() const{
    return fabricante;
}

int Vehiculo::getCantidadLlantas() const{
    return cantidadLlantas;
}

std::string Vehiculo::getChasis() const{
    return chasis;
}

void Vehiculo::setFabricante(const std::string& fabricante){
    this->fabricante = fabricante;
}

void Vehiculo::setCantidaLlantas(int cantidadLlantas){
    this->cantidadLlantas = cantidadLlantas;
}

void Vehiculo::setChasis(const std::string& chasis){
    this->chasis = chasis;
}

void Vehiculo::print(std::ostream& out) const{
    out << "Fabricante: " << fabricante << std::endl;
    out << "Chasis: " << chasis << std::endl;
    out << "Cantidad de llantas: " << cantidadLlantas << std::endl;
}