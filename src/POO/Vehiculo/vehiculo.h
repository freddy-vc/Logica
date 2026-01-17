#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>

class Vehiculo {
protected:
    std::string fabricante;          
    virtual void print(std::ostream& out) const; 

private:
    std::string chasis;               

public:
    int cantidadLlantas;              

    Vehiculo();
    Vehiculo(const std::string& fabricante,
             int cantidadLlantas,
             const std::string& chasis);
    virtual ~Vehiculo() = default;

    std::string getFabricante() const;
    int getCantidadLlantas() const;
    std::string getChasis() const;

    void setFabricante(const std::string& fabricante);
    void setCantidaLlantas(int cantidadLlantas);
    void setChasis(const std::string& chasis);
};

#endif