/*
    Resolución del problema: 02/12/2025
    Escribe un programa que pida al usuario ingresar 5 números enteros 
    (un solo input, cada número separados por coma) y encuentre la suma y el 
    promedio de esos números
*/

#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>

using namespace std;

void imprimirVector(const vector<int>& numeros){
    for (int num : numeros){
        cout << num << setw(4);
    }
    cout << endl;
}

void stringToVector(const string& nums, vector<int>& numeros){
    string numero = "";
    for (int i = 0; i < nums.length(); i++){
        if(nums[i] == ','){
            numeros.push_back(stoi(numero));
            numero = "";
        } else {
            numero += nums[i];
        }
    }

    //Último número
    if(!numero.empty()){
        numeros.push_back(stoi(numero));
    }
}

int sumaVector(const vector<int>& numeros){
    int suma = 0;

    for (int num : numeros){
        suma += num;
    }

    return suma;
}

double promedioVector(const vector <int>& numeros){
    return static_cast<double>(sumaVector(numeros)) / numeros.size();
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    string numeros;
    vector<int> convert;

    cout << "Ingrese los números separados por coma. Ej: (1,2,3,4,5)" << endl;
    getline(cin, numeros);

    stringToVector(numeros, convert);
    imprimirVector(convert);
    cout << "Suma: \t" << sumaVector(convert) << endl;
    cout << "Promedio: \t" << promedioVector(convert) << endl;
    
    return 0;
}
