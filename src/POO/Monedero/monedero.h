#ifndef MONEDERO_H
#define MONEDERO_H

#include "criptomonedainterface.h"
#include "movimientointerface.h"
#include "criptomoneda.h"
#include "movimiento.h"
#include "enviar.h"
#include "recibir.h"

#include <vector>

class Monedero : public CriptoMonedaInterface, public MovimientoIntereface {
    private:
        std::vector<CriptoMoneda> monedas;
        std::vector<Movimiento> movimientos;
    public:
        Monedero();

        void crearMoneda() override;
        void verMonedas() override;
        void editarMoneda() override;
        void eliminarMoneda() override;
        
        void enviarMoneda() override;
        void recibirMoneda() override;
        std::string verMovimientos() override;
};

#endif