#ifndef CRIPTOMONEDA_H
#define CRIPTOMONEDA_H

#include <iostream>

class CriptoMoneda {
    private:
        std::string identificador;
        std::string nombre;
    public:
        CriptoMoneda();
        CriptoMoneda(std::string id, std::string nombre);

        std::string getIdentificador() const;
        std::string getNombre() const;
        
        void setIdentificador(const std::string& id);
        void setNombre(const std::string& nombre);

        friend std::ostream& operator<<(std::ostream& out, const CriptoMoneda &c);
};


#endif