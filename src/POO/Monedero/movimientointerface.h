#ifndef MOVIMIENTOINTERFACE_H
#define MOVIMIENTOINTERFACE_H

#include <iostream>

class MovimientoIntereface {
    public:
        virtual void enviarMoneda() = 0;
        virtual void recibirMoneda() = 0;
        virtual std::string verMovimientos() = 0;
};

#endif