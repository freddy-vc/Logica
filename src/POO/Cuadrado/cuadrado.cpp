#include "cuadrado.h"

Cuadrado::Cuadrado() : lado(0) {}

Cuadrado::Cuadrado(float l) : lado(l) {}

float Cuadrado::getLado(){
    return lado;
}

void Cuadrado::setLado(float l){
    this->lado = l;
}

float Cuadrado::getPerimetro(){
    return 4 * lado;
}

float Cuadrado::getArea(){
    return lado * lado;
}

std::ostream& operator<<(std::ostream& os, Cuadrado& c){
    os << "Cuadrado:" << std::endl << "Lado: " << c.getLado() << std::endl 
    << "Perimetro: " << c.getPerimetro() << std::endl << "Área: " << c.getArea();

    return os;
}