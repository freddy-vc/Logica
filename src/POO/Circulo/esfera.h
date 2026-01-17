#ifndef ESFERA_H
#define ESFERA_H

#include "circulo.h"

class Esfera : public Circulo {

    public:
        Esfera();
        Esfera(float r);
        float getSuperficie();
        float getVolumen();
        friend std::ostream& operator<<(std::ostream& os, Esfera& c);
};

#endif