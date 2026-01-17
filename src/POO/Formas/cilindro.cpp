#include "cilindro.h"

Cilindro::Cilindro() : Circulo(), altura(0.0f) {}

Cilindro::Cilindro(float radio, float altura) : Circulo(radio), altura(altura) {}

float Cilindro::getAltura() const { return altura; }

void Cilindro::setAltura(float altura) { this->altura = altura; }

float Cilindro::getSuperficie() const { return altura * getPerimetro(); }

float Cilindro::getVolumen() const { return altura * getArea(); }

std::ostream& operator<<(std::ostream& os, const Cilindro& c) {
    os << "Cilindro.\n" << "Radio:\t" << c.getRadio() << std::endl << 
        "Altura:\t" << c.getAltura() << std::endl << "Superficie:\t" <<
        c.getSuperficie() << std::endl << "Volumen:\t" << c.getVolumen() << std::endl;

    return os;
}