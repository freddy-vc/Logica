#include "cuentabancaria.h"
#include <sstream>
#include <iomanip>

CuentaBancaria::CuentaBancaria() {
    nombre = "";
    documento = "";
    tipo_documento = "";
    saldo = 0.0;
    bloqueo = false;
}
CuentaBancaria::CuentaBancaria(std::string nom, std::string doc, std::string tipodoc, double saldo, bool bloqueo) {
    this->nombre = nom;
    this->documento = doc;
    this->tipo_documento = tipodoc;
    this->saldo = saldo;
    this->bloqueo = bloqueo;
}

std::string CuentaBancaria::getNombre() const {
    return nombre;
} 

std::string CuentaBancaria::getDocumento() const {
    return documento;
}

std::string CuentaBancaria::getTipoDocumento() const {
    return tipo_documento;
}

double CuentaBancaria::getSaldo() const {
    return saldo;
}

std::string CuentaBancaria::getBloqueo() const {
    return (bloqueo) ?  "Bloqueado" : "Activo";
}
   
void CuentaBancaria::setNombre(const std::string& nom) {
    this->nombre = nom;
}

void CuentaBancaria::setDocumento(const std::string& doc) {
    this->documento = doc;
}

void CuentaBancaria::setTipoDocumento(const std::string& tipodoc) {
    this->tipo_documento = tipodoc;
}

void CuentaBancaria::setSaldo(const double& saldo) {
    this->saldo = saldo;
}

void CuentaBancaria::setBloqueo(const bool& bloqueo) {
    this->bloqueo = bloqueo;
}

void CuentaBancaria::bloquearCuenta() {
    if (!bloqueo){
        bloqueo = true;
        std::cout << "Cuenta bloqueada con exito!" << std::endl;
    } else {
        bloqueo = false;
        std::cout << "Cuenta desbloqueada con exito!" << std::endl;
    }
}

void CuentaBancaria::resetear() {
    nombre = "";
    documento = "";
    tipo_documento = "";
    saldo = 0.0;
    bloqueo = false;
}

std::string CuentaBancaria::toString() {
    std::ostringstream salida;

    salida << std::fixed << std::setprecision(2);

    salida << "\nInformación de la cuenta:\n"
        << " Cliente: " << getNombre() << "\n"
        << "Tipo de documento: " << getTipoDocumento() << "\n"
        << "Número de documento: " << getDocumento() << "\n"
        << "Saldo: " << getSaldo() << "\n"
        << "Estado: " << getBloqueo() << "\n";

    return salida.str();
}