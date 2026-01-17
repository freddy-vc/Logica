#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>

class Estudiante {
    private:
        std::string nombre;
        std::string documento;
        std::string tipo_documento;
        std::string asignatura;
        float nota_corte1;
        float nota_corte2;
        float nota_corte3;
    public:
        Estudiante();
        Estudiante(std::string nom, std::string doc, std::string tipodoc, std::string asig, float nota1, float nota2, float nota3);

        std::string getNombre();
        void setNombre(const std::string& nom);
        std::string getDocumento();
        void setDocumento(const std::string& doc);
        std::string getTipoDocumento();
        void setTipoDocumento(const std::string& tipodoc);
        std::string getAsignatura();
        void setAsignatura(const std::string& asig);
        float getNotaCorte1();
        void setNotaCorte1(const float& nota1);
        float getNotaCorte2();
        void setNotaCorte2(const float& nota2);
        float getNotaCorte3();
        void setNotaCorte3(const float& nota3);

        float obtenerPromedio();
        std::string siAprobo();
        void resetear();
        std::string toString();
};

#endif