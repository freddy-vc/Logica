#include "recibir.h"

Recibir::Recibir() : Transaccion() {}

Recibir::Recibir(std::string token, std::string fecha_hora) : Transaccion(token, fecha_hora) {}

int Recibir::getTipo() { return 2; }