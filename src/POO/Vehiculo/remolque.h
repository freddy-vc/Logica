#ifndef REMOLQUE_H
#define REMOLQUE_H

#include "automovil.h"
#include "trailer.h"

class Remolque : virtual public Automovil, private Trailer {
    private:
        std::string carroceria;
    public:
        Remolque();
        Remolque(const std::string& fabricante, int cantidadLlantas, const std::string& chasis,
            const std::string& placa, float tamanioMotor, float capacidad, 
            const std::string& carroceria);

        std::string getCarroceria() const;

        void setCarroceria(const std::string& carroceria);

        void print(std::ostream& out) const override;
};

#endif