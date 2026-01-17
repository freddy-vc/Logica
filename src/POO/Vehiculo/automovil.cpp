#include "automovil.h"

Automovil::Automovil() : Vehiculo(), placa(""), tamanioMotor(0.0f) {}
Automovil::Automovil(const std::string& fabricante, int cantidadLlantas, const std::string& chasis, 
    const std::string& placa, float tamanioMotor) : Vehiculo(fabricante, cantidadLlantas, chasis),
    placa(placa), tamanioMotor(tamanioMotor) {}
        
std::string Automovil::getPlaca() const{
    return placa;
}

float Automovil::getTamanioMotor() const{
    return tamanioMotor;
}
        
void Automovil::setPlaca(const std::string& placa){
    this->placa = placa;
}
void Automovil::setTamanioMotor(float tamanioMotor){
    this->tamanioMotor = tamanioMotor;
}

void Automovil::print(std::ostream& out) const{
    Vehiculo::print(out);
    out << "Placa: " << placa << std::endl;
    out << "Tamaño del motor: " << tamanioMotor << std::endl;
}
