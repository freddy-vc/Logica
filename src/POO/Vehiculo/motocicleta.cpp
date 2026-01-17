#include "motocicleta.h"

Motocicleta::Motocicleta() : Automovil(), anchoManillar(0.0f), elevacionManillar(0.0f) {}

Motocicleta::Motocicleta(const std::string& fabricante, int cantidadLlantas, const std::string& chasis,
    const std::string& placa, float tamanioMotor, float anchoManillar, 
    float elevacionManillar) : Automovil(fabricante, cantidadLlantas, chasis, placa, tamanioMotor),
    anchoManillar(anchoManillar), elevacionManillar(elevacionManillar) {}
        
float Motocicleta::getAnchoManillar() const{
    return anchoManillar;
}

float Motocicleta::getElevacionManillar() const{
    return elevacionManillar;
}

void Motocicleta::setAnchoManillar(float anchoManillar){
    this->anchoManillar = anchoManillar;
}
void Motocicleta::setElevacionManillar(float elevacionManillar){
    this->elevacionManillar = elevacionManillar;
}

void Motocicleta::print(std::ostream& out) const{
    Automovil::print(out);
    out << "Ancho del manillar: " << anchoManillar << std::endl;
    out << "Elevación del manillar: " << elevacionManillar << std::endl;
}