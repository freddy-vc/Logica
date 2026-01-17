#ifndef CIRCULO_H
#define CIRCULO_H

#include "forma2d.h"
#include <iostream>

constexpr double PI = 3.14159265358979323846;

class Circulo : public Forma2D {
    private:
        float radio;
    public:
        Circulo();
        Circulo(float radio);

        float getRadio() const;
        void setRadio(float radio);

        float getArea() const override;
        float getPerimetro() const override;

        friend std::ostream& operator<<(std::ostream& os, const Circulo& c);
};

#endif