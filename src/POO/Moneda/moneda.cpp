#include "moneda.h"
#include <iomanip>

Moneda::Moneda() : dolar(0), centavo(0) {}

Moneda::Moneda(int d, int c){
    if (d >= 0)
        dolar = d;
    else
        dolar = 0;

    if (c >= 0 && c <= 99)
        centavo  = c;
    else
        centavo = 0;
}

Moneda Moneda::operator+(const Moneda& m) const { 
    int totalCentavos = (dolar * 100 + centavo) + (m.dolar * 100 + m.centavo);
    int newDolar = totalCentavos / 100;
    int newCentavo = totalCentavos % 100;

    return Moneda(newDolar, newCentavo);
}

Moneda Moneda::operator-(const Moneda& m) const { 
    int totalCentavos = (dolar * 100 + centavo) - (m.dolar * 100 + m.centavo);
    int newDolar = totalCentavos / 100;
    int newCentavo = totalCentavos % 100;

    return Moneda(newDolar, newCentavo);
}

Moneda& Moneda::operator*=(int n){
    int totalCentavos = (dolar * 100 + centavo) * n;

    if (totalCentavos < 0) totalCentavos = 0;

    dolar = totalCentavos / 100;
    centavo = totalCentavos % 100;

    return *this;
}

Moneda& Moneda::operator/=(int n){
    if (n == 0) {
        dolar = 0;
        centavo = 0;

        return *this;
    }

    int totalCentavos = (dolar * 100 + centavo) / n;

    if (totalCentavos < 0) totalCentavos = 0;

    dolar = totalCentavos / 100;
    centavo = totalCentavos % 100;

    return *this;
}

bool Moneda::operator<(const Moneda& m) const {
    return ((dolar * 100 + centavo) < (m.dolar * 100 + m.centavo)) ? true : false;
}

bool Moneda::operator>(const Moneda& m) const {
    return ((dolar * 100 + centavo) > (m.dolar * 100 + m.centavo)) ? true : false;
}

bool Moneda::operator==(const Moneda& m) const {
    return ((dolar * 100 + centavo) == (m.dolar * 100 + m.centavo)) ? true : false;
}

bool Moneda::operator!=(const Moneda& m) const {
    return ((dolar * 100 + centavo) != (m.dolar * 100 + m.centavo)) ? true : false;
}

std::ostream& operator<<(std::ostream& os, const Moneda& m) {
    os << "$" << m.dolar << "." << std::setw(2) << std::setfill('0') << m.centavo;

    return os;
}


std::istream& operator>>(std::istream& is, Moneda& m){
    int d, c;
    is >> d >> c;

    m.dolar   = (d >= 0) ? d : 0;
    m.centavo = (c >= 0 && c <= 99) ? c : 0;

    return is;
}

