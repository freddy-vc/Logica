#include "estudiante.h"

Estudiante::Estudiante(){ 
    nombre = "";
    documento = "";
    tipo_documento = "";
    asignatura = "";
    nota_corte1 = 0.0;
    nota_corte2 = 0.0;
    nota_corte3 = 0.0;
}

Estudiante::Estudiante(std::string nom, std::string doc, std::string tipodoc, std::string asig, float nota1, float nota2, float nota3) {
    this->nombre = nom;
    this->documento = doc;
    this->tipo_documento = tipodoc;
    this->asignatura = asig;
    this->nota_corte1 = nota1;
    this->nota_corte2 = nota2;
    this->nota_corte3 = nota3;
}

std::string Estudiante::getNombre() {
    return nombre;
}

void Estudiante::setNombre(const std::string& nom) {
    this->nombre = nom;
}

std::string Estudiante::getDocumento() {
    return documento;
}

void Estudiante::setDocumento(const std::string& doc) {
    this->documento = doc;
}

std::string Estudiante::getTipoDocumento() {
    return tipo_documento;
}

void Estudiante::setTipoDocumento(const std::string& tipodoc) {
    this->tipo_documento = tipodoc;
}

std::string Estudiante::getAsignatura() {
    return asignatura;
}

void Estudiante::setAsignatura(const std::string& asig) {
    this->asignatura = asig;
}

float Estudiante::getNotaCorte1() {
    return nota_corte1;
}

void Estudiante::setNotaCorte1(const float& nota1) {
    this->nota_corte1 = nota1;
}

float Estudiante::getNotaCorte2() {
    return nota_corte2;
}

void Estudiante::setNotaCorte2(const float& nota2) {
    this->nota_corte2 = nota2;
}

float Estudiante::getNotaCorte3() {
    return nota_corte3;
}

void Estudiante::setNotaCorte3(const float& nota3) {
    this->nota_corte3 = nota3;
}

float Estudiante::obtenerPromedio() {

    return nota_corte1 * 0.3 + nota_corte2 * 0.3 + nota_corte3 * 0.4;
}

std::string Estudiante::siAprobo() {
    if (obtenerPromedio() >= 3.0) return "Asignatura aprobada!\n";

    return "Asignatura desaprobada!\n";
}

void Estudiante::resetear() {
    nombre = "";
    documento = "";
    tipo_documento = "";
    asignatura = "";
    nota_corte1 = 0.0;
    nota_corte2 = 0.0;
    nota_corte3 = 0.0;
}

std::string Estudiante::toString() {
    return ("\nInformación del estudiante:\nNombre: " + nombre + ".\nTipo de documento: " 
            + tipo_documento + ".\nDocumento: " + documento + ".\nAsignatura: "
            + asignatura + ".\nNota Corte 1: " + std::to_string(nota_corte1) + "\tNota Corte 2: "
            + std::to_string(nota_corte2) + "\tNota Corte 3: " + std::to_string(nota_corte3) + "\nPromedio: "
            + std::to_string(obtenerPromedio())) + "\nEstado: " + siAprobo() + "\n";

}
