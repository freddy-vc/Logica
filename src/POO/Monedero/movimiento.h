#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include "transaccion.h"
#include "criptomoneda.h"

class Movimiento{
    private:
        CriptoMoneda moneda;
        Transaccion* transaccion;
        double valor;
    public:
        Movimiento();
        Movimiento(const CriptoMoneda& moneda, Transaccion* transaccion, double valor);

        double getValor() const;
        Transaccion* getTransaccion();
        void setValor(double valor);

        friend std::ostream& operator<<(std::ostream& out, const Movimiento& m);
};

#endif