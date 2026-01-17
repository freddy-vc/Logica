#ifndef CUBO_H
#define CUBO_H

#include "cuadrado.h"

class Cubo : public Cuadrado {
    public:
        Cubo();
        Cubo(float l);
        float getSuperficie();
        float getVolumen();
        friend std::ostream& operator<<(std::ostream& os, Cubo& c);
};

#endif