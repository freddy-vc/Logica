#include "hora.h"
#include <iomanip>

Hora::Hora() : horas(0), minutos(0), segundos(0) {}

// Constructor por parametros con sus respectivas válidaciones.
Hora::Hora(int h, int m, int s) {
    if ( h >= 0 && h <= 23)
        horas = h;
    else    
        horas = 0;

    if ( m >= 0 && m <= 59)
        minutos = m;
    else    
        minutos = 0;

    if ( s >= 0 && s <= 59)
        segundos = s;
    else    
        segundos = 0;    
}

Hora& Hora::operator++() {
    segundos++;

    if (segundos == 60) {
        segundos = 0;
        minutos++;
        
        if (minutos == 60) {
            minutos = 0;
            horas++;
        }

        if (horas == 24) {
            horas = 0;
        }
    }

    return *this;
}

Hora Hora::operator++(int) {
    Hora temp = *this;
    ++(*this);
    
    return *this;
}

Hora& Hora::operator+=(int segs) {
     int total = TotalSegundos() + segs;

    // Ajuste circular de 24 horas
    total %= 86400;
    if (total < 0)
        total += 86400;

    horas = total / 3600;
    total %= 3600;
    minutos = total / 60;
    segundos = total % 60;

    return *this;
}
Hora& Hora::operator-=(int segs) {
    int total = TotalSegundos() - segs;

    // Ajuste circular de 24 horas
    total %= 86400;
    if (total < 0)
        total += 86400;

    horas = total / 3600;
    total %= 3600;
    minutos = total / 60;
    segundos = total % 60;

    return *this;
}

int Hora::operator-(const Hora& h) {
    return TotalSegundos() - h.TotalSegundos();
}

std::ostream& operator<<(std::ostream& os, const Hora& h) {
    os << std::setw(2) << std::setfill('0') << h.horas   << ":"
       << std::setw(2) << std::setfill('0') << h.minutos << ":"
       << std::setw(2) << std::setfill('0') << h.segundos;

    return os;
}

std::istream& operator>>(std::istream& is, Hora& h) {
    int ho, mi, se;
    is >> ho >> mi >> se;

    // Validación de rangos
    h.horas   = (ho >= 0 && ho <= 23) ? ho : 0;
    h.minutos = (mi >= 0 && mi <= 59) ? mi : 0;
    h.segundos = (se >= 0 && se <= 59) ? se : 0;

    return is;
}

// Función para cálcular la duración del tiempo en segundos
int Hora::TotalSegundos() const{
    return horas * 3600 + minutos * 60 + segundos;
}

