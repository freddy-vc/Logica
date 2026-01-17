#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <iostream>

class CuentaBancaria {
    private:
        std::string nombre;
        std::string documento;
        std::string tipo_documento;
        double saldo;
        bool bloqueo;

    public:
        CuentaBancaria();
        CuentaBancaria(std::string nom, std::string doc, std::string tipodoc, double saldo, bool bloqueo);

        // getters
        std::string getNombre() const;
        std::string getDocumento() const;
        std::string getTipoDocumento() const;
        double getSaldo() const;
        std::string getBloqueo() const;

        //setters
        void setNombre(const std::string& nom);
        void setDocumento(const std::string& doc);
        void setTipoDocumento(const std::string& tipodoc);
        void setSaldo(const double& saldo);
        void setBloqueo(const bool& bloqueo);

        void bloquearCuenta();
        void resetear();
        std::string toString();
};


#endif