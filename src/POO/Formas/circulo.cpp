#include "circulo.h"

Circulo::Circulo() : radio(0.0f) {}

Circulo::Circulo(float radio) : radio(radio) {}

float Circulo::getRadio() const { return radio; }

void Circulo::setRadio(float radio) { this->radio = radio; }

float Circulo::getArea() const { return PI * radio * radio; }

float Circulo::getPerimetro() const { return 2 * PI * radio; }

std::ostream& operator<<(std::ostream& os, const Circulo& c) {
    os << "Circulo:\n" << "Radio:\t" << c.radio << std::endl 
        << "Area:\t" << c.getArea() << std::endl << "Perimetro:\t" <<
        c.getPerimetro() << std::endl;

    return os;
}