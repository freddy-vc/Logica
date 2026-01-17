#include "trailer.h"

Trailer::Trailer() : capacidad(0.0f) {}

Trailer::Trailer(float capacidad) : capacidad(capacidad) {}

float Trailer::getCapacidad() const {
    return capacidad;
}

void Trailer::setCapacidad(float capacidad) {
    this->capacidad = capacidad;
}

void Trailer::print(std::ostream& out) const {
    out << "Capacidad: " << capacidad << std::endl;
}