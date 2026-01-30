#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include "list.h"

using namespace std;

class Estudiante {
    private:
        string nombre;
        List<float> calificaciones;
    public:
        Estudiante();
        Estudiante(string nom);

        string getNombre() const;
        void setNombre(string &nom);
        void addCalificacion(float cal);
        float getCalificacion(int pos) const;
        float getPuntajeTotal() const;
        float getPromedio() const;

        friend ostream& operator<<(ostream& out, const Estudiante& e);
};


#endif