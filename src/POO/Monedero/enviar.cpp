#include "enviar.h"

Enviar::Enviar() : Transaccion() {}

Enviar::Enviar(std::string token, std::string fecha_hora) : Transaccion(token, fecha_hora) {}

int Enviar::getTipo() { return 1; }