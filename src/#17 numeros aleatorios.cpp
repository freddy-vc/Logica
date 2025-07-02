/*
    Resolución del ejercicio: 01/07/2025
    Crear un programa que genere n números aleatorios desde a hasta b y que imprima 6 por cada renglón.
*/

#include <iostream>
#include <windows.h>
#include <random>
#include <limits>
#include <iomanip>

using namespace std;

// Función para limpiar la entrada
void limpiarEntrada(){
    cin.clear(); // Limpiar error de entrada
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer de entrada
}

// Función para pedir la cantidad de números a generar
int pedirCantidad (){
    int num;
    while(true){
        cout << "Ingrese la cantidad de números a generar: ";
        cin >> num;
        if (!cin.fail() && num > 0) return num;
        
        cout << "Entrada inválida. La cantidad debe ser positiva!" << endl;
        limpiarEntrada();
    }
}

// Función para validar los límites
void pedirLimites(int& a,int& b){
    while(true){
        cout << "Ingrese el número inicial para generar números aleatorios: ";
        cin >> a;
        if (!cin.fail()) break;
        cout << "Entrada inválida. Intente nuevamente!" << endl;
        limpiarEntrada();
    }

    while(true){
        cout << "Ingrese el número final para generar números aleatorios: ";
        cin >> b;

        if (cin.fail()) {
            cout << "Entrada inválida. Intente nuevamente!" << endl;
            limpiarEntrada();
        } else if ( b < a){
            cout << "El número final debe ser mayor al número inicial!" << endl;
        } else {
            break;
        }
    }
}

// Función para generar un número aleatorio entre a y b
// El generador se pasa por referencia, el distribuidor se declara dentro
int numeroAleatorio(mt19937& gen, int a, int b){
    uniform_int_distribution<> dist(a, b); // Distribuidor para determinar el rango de los numeros a generar
    return dist(gen); // Se genera y retorna el número aleatorio
}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    int cantidad = pedirCantidad();
    int a, b;

    pedirLimites(a, b);

    random_device rd;     // Generador no determinista
    mt19937 gen(rd());    // Generador determinista con semilla aleatoria

    for (int i = 1; i <= cantidad; i++){
        cout << setw(5) << numeroAleatorio(gen, a, b); // Se pasa el generador y los límites con un ancho de 5 caracteres entre cada número

        if (i % 6 == 0) cout << endl; // Salto de línea cada 6 números
    }

    if (cantidad % 6 != 0) cout << endl; // Salto final si no terminó en múltiplo de 6

    return 0;
}
