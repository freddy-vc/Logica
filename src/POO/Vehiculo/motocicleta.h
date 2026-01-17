#ifndef MOTOCICLETA_H
#define MOTOCICLETA_H

#include "automovil.h"

class Motocicleta : virtual public Automovil {
    private:
        float anchoManillar;
        float elevacionManillar; 
    public:
        Motocicleta();
        Motocicleta(const std::string& fabricante, int cantidadLlantas, const std::string& chasis,
            const std::string& placa, float tamanioMotor, float anchoManillar, 
            float elevacionManillar);
        
        float getAnchoManillar() const;
        float getElevacionManillar() const;

        void setAnchoManillar(float anchoManillar);
        void setElevacionManillar(float elevacionManillar);

        void print(std::ostream& out) const override;
};


#endif