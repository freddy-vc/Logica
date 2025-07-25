/*
    Resolución del problema: 24/07/2025
    Realizar un programa que calcule la multiplicación de dos matrices bidimensionales de 3x3
*/

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <random>

using namespace std;

const int ROWS = 3;
const int COLUMNS = 3;


void imprimirMatriz (int matriz[ROWS][COLUMNS]){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++)
            cout << setw(4) << matriz[i][j];
        cout << endl;
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    int A [ROWS][COLUMNS];
    int B[ROWS][COLUMNS];
    int C[ROWS][COLUMNS]  =  {0};

    // Configurar el generador de números aleatorios
    random_device rd;                          // Fuente de entropía
    mt19937 gen(rd());                         // Motor Mersenne Twister
    uniform_int_distribution<> distrib(1, 9);  // Números entre 1 y 9

    // Rellenar matrices A y B con números aleatorios
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            A[i][j] = distrib(gen);
            B[i][j] = distrib(gen);
        }
    }

    // Multiplicación de matrices
    for(int i = 0; i < ROWS; i++){
       for(int j = 0; j < COLUMNS; j++){
            for (int k = 0; k < COLUMNS; k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        } 
    }

    cout << "Matriz A:\n";
    imprimirMatriz(A);

    cout << "\nMatriz B:\n";
    imprimirMatriz(B);

    cout << "\nMatriz C (A × B):\n";
    imprimirMatriz(C);

    return 0;
}



