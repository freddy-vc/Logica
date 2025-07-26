/*
    Resolución del problema: 24/07/2025
    Se desea permutar las filas I y J de una matriz (array) de dos dimensiones (M*N): M filas, N columnas.
*/

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <random>
#include <limits>

using namespace std;

const int ROWS = 3;    // Inicializar las filas
const int COLUMNS = 3; // Inicializar las columnas

// Función para imprimir la matriz
void imprimirMatriz(int matriz[ROWS][COLUMNS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++)
            cout << setw(4) << matriz[i][j];
        cout << endl;
    }
}

// Función para validar la entrada
int validarEntrada(const string& mensaje) {
    int valor;
    while(true) {
        cout << mensaje;
        cin >> valor;
        if(!cin.fail() && (valor >= 1 && valor <= ROWS)) return valor;
        cout << "Ingrese una fila válida entre 1 y " << ROWS << endl;
        cin.clear(); // Limpiar el error de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
    }
}

// Función para rellenar la matriz con números aleatorios
void rellenarMatrizAleatoria(int matriz[ROWS][COLUMNS]) {
    random_device rd;                          // Semilla aleatoria del sistema
    mt19937 gen(rd());                         // Motor de números aleatorios (Mersenne Twister)
    uniform_int_distribution<> distrib(1, 100); // Distribución uniforme entre 1 y 100

    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLUMNS; j++)
            matriz[i][j] = distrib(gen);
}

// Función para permutar dos filas de la matriz
void permutarFilas(int matriz[ROWS][COLUMNS], int filaA, int filaB) {
    int AUX[COLUMNS];
    for(int i = 0; i < COLUMNS; i++) {
        AUX[i] = matriz[filaA][i];
        matriz[filaA][i] = matriz[filaB][i];
        matriz[filaB][i] = AUX[i];
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int matriz[ROWS][COLUMNS];

    // Rellenar la matriz con números aleatorios
    rellenarMatrizAleatoria(matriz);

    int filaA, filaB;

    filaA = validarEntrada("Ingrese la primera fila a intercambiar: ") - 1;

    do {
        filaB = validarEntrada("Ingrese la segunda fila a intercambiar: ") - 1;
        if(filaA == filaB)
            cout << "Las filas deben ser diferentes!" << endl;
    } while(filaA == filaB);

    cout << "Matriz Original: " << endl;
    imprimirMatriz(matriz);

    // Permutar filas
    permutarFilas(matriz, filaA, filaB);

    cout << "Matriz Permutada: " << endl;
    imprimirMatriz(matriz);

    return 0;
}