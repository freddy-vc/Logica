#ifndef HORA_H
#define HORA_H

#include <iostream>

class Hora {
    private:
        int horas;
        int minutos;
        int segundos;
    public:
        Hora();
        Hora(int h, int m, int s);
        
        Hora& operator++();
        Hora operator++(int);
        Hora& operator+=(int segundos);
        Hora& operator-=(int segundos);
        int operator-(const Hora& h);

        friend std::ostream& operator<<(std::ostream& os, const Hora& h);
        friend std::istream& operator>>(std::istream& is, Hora& h);

        int TotalSegundos() const;
};


#endif