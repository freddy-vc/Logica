#include "estudiante.h"

Estudiante::Estudiante() : nombre(""), calificaciones() {}
Estudiante::Estudiante(string nom) : nombre(nom) {}

string Estudiante::getNombre() const { return nombre;}
void Estudiante::setNombre(string &nom) { this->nombre = nom; }

void Estudiante::addCalificacion(float cal) {
    calificaciones.insert(calificaciones.size(), cal);
}
float Estudiante::getCalificacion(int pos) const {
    return calificaciones.get(pos);
}

float Estudiante::getPuntajeTotal() const {
    float total = 0;
    for(int i = 0; i < calificaciones.size(); i++){
        total += getCalificacion(i);
    }
    return total;
}

float Estudiante::getPromedio() const {
    return (calificaciones.size() > 0) ? getPuntajeTotal() / calificaciones.size() : 0;
}

ostream& operator<<(ostream& out, const Estudiante& e) {
    out << "Nombre: " << e.getNombre() << endl << "Calificaciones: ";
    for(int i = 0; i < e.calificaciones.size(); i++){
        out << e.getCalificacion(i) << " ";
    }
    out << endl << "Puntaje total: " << e.getPuntajeTotal() << endl << "Promedio: " 
        << e.getPromedio() << endl << endl;

    return out;
}