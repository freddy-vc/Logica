#include "cubo.h"

Cubo::Cubo() : Cuadrado(0) {}

Cubo::Cubo(float l) : Cuadrado(l) {}

float Cubo::getSuperficie(){
    return 6 * getArea();
}

float Cubo::getVolumen(){
    return lado * lado * lado;
}

std::ostream& operator<<(std::ostream& os, Cubo& c){
    os << "Cubo: " << std::endl << "Lado: " << c.lado << std::endl << "Superficie: " <<
    c.getSuperficie() << std::endl << "Volumen: " << c.getVolumen();
    
    return os;
}
