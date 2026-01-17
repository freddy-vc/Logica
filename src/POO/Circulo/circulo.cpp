#include "circulo.h"
#include <numbers>

Circulo::Circulo() : radio(0) {}

Circulo::Circulo(float r) : radio(r) {}

float Circulo::getRadio() { return radio; }

void Circulo::setRadio(float r) { this->radio = r; }

float Circulo::getPerimetro() { return 2 * std::numbers::pi * radio; }

float Circulo::getArea() { return std::numbers::pi * radio * radio; }

std::ostream& operator<<(std::ostream& os, Circulo& c) {
    os << "Circulo: " << std::endl << "Radio: " << c.getRadio() << std::endl <<
    "Perimetro: " << c.getPerimetro() << std::endl << "Área: " << c.getArea();

    return os;
}