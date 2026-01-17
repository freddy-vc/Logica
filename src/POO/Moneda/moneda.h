#ifndef MONEDA_H
#define MODENA_H

#include <iostream>

class Moneda {
    private:
        int dolar;
        int centavo;
    public:
        Moneda();
        Moneda(int d, int c);

        Moneda operator+(const Moneda& m) const;
        Moneda operator-(const Moneda& m) const;
        Moneda& operator*=(int n);
        Moneda& operator/=(int n);
        bool operator<(const Moneda& m) const;
        bool operator>(const Moneda& m) const;
        bool operator==(const Moneda& m) const;
        bool operator!=(const Moneda& m) const;
        
        friend std::ostream& operator<<(std::ostream& os, const Moneda& m);
        friend std::istream& operator>>(std::istream& is, Moneda& m);

};

#endif