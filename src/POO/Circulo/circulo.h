#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>

class Circulo {
    private:
        float radio;
    public:
        Circulo();
        Circulo(float r);
        float getRadio();
        void setRadio(float r);
        float getPerimetro();
        float getArea();
        friend std::ostream& operator<<(std::ostream& os, Circulo& c);
};

#endif