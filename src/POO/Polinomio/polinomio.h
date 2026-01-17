#ifndef POLINOMIO_H 
#define POLINOMIO_H

#include <vector>

class Polinomio { 
    public: 
        // Constructor por defecto 
        Polinomio();
        // Constructor por parámetros 
        Polinomio(int coef4, int coef3, int coef2, int coef1, int coef0);
        // Constructor por copia 
        Polinomio(const Polinomio &otro);
        // Constructor por parámetros con vector
        Polinomio(const std::vector<int>& coefs);
        // Destructor
        ~Polinomio();
        // Método para imprimir el polinomio 
        void imprimir(); 
        // Método para multiplicar por un escalar
        void multiplicarPorEscalar(int escalar); 
    public: 
        // Atributos del polinomio de grado 4 
        int coeficiente4; 
        int coeficiente3; 
        int coeficiente2; 
        int coeficiente1; 
        int coeficiente0; 
}; 

#endif