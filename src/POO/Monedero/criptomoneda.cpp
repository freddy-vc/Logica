#include "criptomoneda.h"

CriptoMoneda::CriptoMoneda() : identificador(""), nombre("") {}
CriptoMoneda::CriptoMoneda(std::string id, std::string nombre) : identificador(id), nombre(nombre) {}

std::string CriptoMoneda::getIdentificador() const { return identificador; }
std::string CriptoMoneda::getNombre() const { return nombre; }
        
void CriptoMoneda::setIdentificador(const std::string& id) { this->identificador = id; }
void CriptoMoneda::setNombre(const std::string& nombre) { this->nombre = nombre; }

std::ostream& operator<<(std::ostream& out, const CriptoMoneda &c) {
    out << "[" << c.identificador << "] " << c.nombre << std::endl;

    return out;
}
