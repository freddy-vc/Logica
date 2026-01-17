#ifndef ENVIAR_H
#define ENVIAR_H

#include "transaccion.h"

class Enviar : public Transaccion {
    public:
        Enviar();
        Enviar(std::string token, std::string fecha_hora);
        int getTipo() override;
};


#endif