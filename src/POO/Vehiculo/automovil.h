#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include "vehiculo.h"

class Automovil : protected Vehiculo {
    protected:
        float tamanioMotor;
        void print(std::ostream& out) const override;
    public:
        std::string placa;

        Automovil();
        Automovil(const std::string& fabricante, int cantidadLlantas, const std::string& chasis,
            const std::string& placa, float tamanioMotor);
        
        std::string getPlaca() const;
        float getTamanioMotor() const;
        
        void setPlaca(const std::string& placa);
        void setTamanioMotor(float tamanioMotor);
};



#endif