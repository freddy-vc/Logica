#include "transaccion.h"

Transaccion::Transaccion() : token(""), fecha_hora("") {}

Transaccion::Transaccion(std::string token, std::string fecha_hora) : 
    token(token), fecha_hora(fecha_hora) {}
        
std::string Transaccion::getToken() const { return token; }
std::string Transaccion::getFechaHora() const { return fecha_hora; }

void Transaccion::setToken(const std::string& token) { this->token = token; }
void Transaccion::setFechaHora(const std::string& fecha_hora) { this->fecha_hora = fecha_hora; }

std::string Transaccion::print() { 
    return "Token: " + token + "\nFecha y hora: " + fecha_hora + "\n";
}