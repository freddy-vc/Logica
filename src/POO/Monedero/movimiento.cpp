#include "movimiento.h"

Movimiento::Movimiento() : moneda(), transaccion(nullptr), valor(0.0f) {}

Movimiento::Movimiento(const CriptoMoneda& moneda, Transaccion* transaccion, double valor) : 
    moneda(moneda), transaccion(transaccion), valor(valor) {}

double Movimiento::getValor() const{ return valor; }
Transaccion* Movimiento::getTransaccion() { return transaccion; }

void Movimiento::setValor(double valor) { this->valor = valor; }

std::ostream& operator<<(std::ostream& out, const Movimiento& m) {
    out << m.moneda << m.transaccion->print() << "Valor: " << m.valor << "\n";

    return out;
}