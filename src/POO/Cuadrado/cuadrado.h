#ifndef CUADRADO_H
#define CUADRADO_H

#include <iostream>

class Cuadrado {
    protected:
        float lado;
    public:
        Cuadrado();
        Cuadrado(float l);
        float getLado();
        void setLado(float l);
        float getPerimetro();
        float getArea();
        friend std::ostream& operator<<(std::ostream& os, Cuadrado& c);
};

#endif