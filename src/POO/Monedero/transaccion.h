#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <iostream>

class Transaccion {
    private:
        std::string token;
        std::string fecha_hora;
    public:
        Transaccion();
        Transaccion(std::string token, std::string fecha_hora);
        
        std::string getToken() const;
        std::string getFechaHora() const;

        void setToken(const std::string& token);
        void setFechaHora(const std::string& fecha_hora);

        std::string print();
        virtual int getTipo() = 0;
};

#endif