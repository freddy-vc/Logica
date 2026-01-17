#include "polinomio.h" 
#include <iostream>

// Constructor por defecto 
Polinomio::Polinomio() { 
    coeficiente4 = 0; 
    coeficiente3 = 0; 
    coeficiente2 = 0; 
    coeficiente1 = 0; 
    coeficiente0 = 0; 
} 

// Constructor por parámetros 
Polinomio::Polinomio(int coef4, int coef3, int coef2, int coef1, int coef0) { 
    this->coeficiente4 = coef4; 
    this->coeficiente3 = coef3; 
    this->coeficiente2 = coef2; 
    this->coeficiente1 = coef1; 
    this->coeficiente0 = coef0; 
} 

// Constructor por copia 
Polinomio::Polinomio(const Polinomio &otro) { 
    coeficiente4 = otro.coeficiente4;
    coeficiente3 = otro.coeficiente3; 
    coeficiente2 = otro.coeficiente2; 
    coeficiente1 = otro.coeficiente1; 
    coeficiente0 = otro.coeficiente0; 
}

// Constructor por parámetros con vector
Polinomio::Polinomio(const std::vector<int>& coefs){
     // Inicializar en caso de que el vector sea corto
    coeficiente4 = 0;
    coeficiente3 = 0;
    coeficiente2 = 0;
    coeficiente1 = 0;
    coeficiente0 = 0;

      // Caso 1: El vector tiene suficientes coeficientes
    if (coefs.size() >= 5) {
        coeficiente4 = coefs[0];
        coeficiente3 = coefs[1];
        coeficiente2 = coefs[2];
        coeficiente1 = coefs[3];
        coeficiente0 = coefs[4];
    }
    // Caso 2: El vector tiene menos de 5 elementos
    else {
        for (size_t i = 0; i < coefs.size(); i++) {
            switch (i) {
                case 0: coeficiente4 = coefs[i]; break;
                case 1: coeficiente3 = coefs[i]; break;
                case 2: coeficiente2 = coefs[i]; break;
                case 3: coeficiente1 = coefs[i]; break;
            }
        }
    }
}

// Destructor de la clase Polinomio 
Polinomio::~Polinomio() { 
    std::cout << "El objeto Polinomio se destruyó." << std::endl;
}

// Método para imprimir el polinomio 
void Polinomio::imprimir() { 
    std::cout << coeficiente4 << "x^4 + " << coeficiente3 << "x^3 + " << 
    coeficiente2 << "x^2 + " << coeficiente1 << "x + " << coeficiente0 << std::endl; 
} 

// Método para multiplicar por un escalar 
void Polinomio::multiplicarPorEscalar(int escalar) { 
    coeficiente4 *= escalar; 
    coeficiente3 *= escalar;
    coeficiente2 *= escalar; 
    coeficiente1 *= escalar; 
    coeficiente0 *= escalar; 
}