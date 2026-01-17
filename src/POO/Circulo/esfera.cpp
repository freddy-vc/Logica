#include "esfera.h"

Esfera::Esfera() : Circulo(0) {}

Esfera::Esfera(float r) : Circulo(r) {}

float Esfera::getSuperficie() { return 2 * getRadio() * getPerimetro(); }

float Esfera::getVolumen() { return (4.0f / 3.0f ) * getRadio() * getArea(); }

std::ostream& operator<<(std::ostream& os, Esfera& c) {
    os << "Esfera: " << std::endl << "Radio: " << c.getRadio() << std::endl <<
    "Superficie: " << c.getSuperficie() << std::endl << "Volumen: " << c.getVolumen();

    return os;
}