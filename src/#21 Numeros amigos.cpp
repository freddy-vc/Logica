/*
    Resolución del ejercicio: 21/07/2025
    Dado dos números a y b, verificar si son números amigos.
*/

#include <iostream>
#include <windows.h>
#include <limits>

using namespace std;

// Función para validar la entrada
int validarEntrada(const string& mensaje){
    int num;
    while(true){
        cout << mensaje;
        cin >> num;

        if (!cin.fail() && num > 0) return num;

        cout << "Ingrese un número natural válido." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
}

// Función para cálcular la suma de los divisores propios de un número
int sumaDivisores(int num){
    int sum = 0;
    for(int i = 1; i < num; i++){
        if (num % i == 0){
            sum += i;
        }
    }
    return sum;
}

// Función para determinar si 2 numeros son amigos
bool sonAmigos(int a, int b){
    int sum1 = sumaDivisores(a);
    int sum2 = sumaDivisores(b);

    return sum1 == b && sum2 == a;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    int num1 = validarEntrada("Ingrese el primer número: ");
    int num2 = validarEntrada("Ingrese el segundo número: ");

    if (sonAmigos(num1,num2)) 
        cout <<  num1 << " y " << num2 << " son amigos" << endl;
    else
        cout <<  num1 << " y " << num2 << " no son amigos" << endl;

    return 0;
}
