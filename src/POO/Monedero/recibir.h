#ifndef RECIBIR_H
#define RECIBIR_H

#include "transaccion.h"

class Recibir : public Transaccion {
    public:
        Recibir();
        Recibir(std::string token, std::string fecha_hora);
        int getTipo() override;
};


#endif