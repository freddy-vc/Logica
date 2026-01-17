#ifndef CILINDRO_H
#define CILINDRO_H

#include "forma3d.h"
#include "circulo.h"

class Cilindro : public Forma3D, public Circulo {
    private:
        float altura;
    public:
        Cilindro();
        Cilindro(float radio, float altura);

        float getAltura() const;
        void setAltura(float altura);

        float getSuperficie() const override;
        float getVolumen() const override;

        friend std::ostream& operator<<(std::ostream& os, const Cilindro& c);
};

#endif