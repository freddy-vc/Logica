#include "motocarguero.h"

Motocarguero::Motocarguero(): Automovil(), Motocicleta(), Remolque() {}

Motocarguero::Motocarguero(const std::string& fabricante, int cantidadLlantas,
    const std::string& chasis, const std::string& placa, float tamanioMotor, float anchoManillar,
    float elevacionManillar, float capacidad, const std::string& carroceria)
    : Automovil(fabricante, cantidadLlantas, chasis, placa, tamanioMotor),
    Motocicleta(fabricante, cantidadLlantas, chasis, placa, tamanioMotor, anchoManillar, elevacionManillar),
    Remolque(fabricante, cantidadLlantas, chasis, placa, tamanioMotor, capacidad, carroceria) {}

void Motocarguero::print(std::ostream& out) const{
    Remolque::print(out);
    out << "Ancho del manillar: " << getAnchoManillar() << std::endl;
    out << "Elevación del manillar: " << getAnchoManillar() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Remolque& r){
    r.print(out);

    return out;
}
