#ifndef MOTOCARGUERO_H
#define MOTOCARGUERO_H

#include "motocicleta.h"
#include "remolque.h"

class Motocarguero : public Motocicleta, public Remolque {
    public:
        Motocarguero();
        Motocarguero(const std::string& fabricante, int cantidadLlantas, const std::string& chasis, 
        const std::string& placa, float tamanioMotor, float anchoManillar, float elevacionManillar, 
        float capacidad, const std::string& carroceria);

        void print(std::ostream& out) const override;

        friend std::ostream& operator<<(std::ostream& out, const Remolque& r);
};


#endif