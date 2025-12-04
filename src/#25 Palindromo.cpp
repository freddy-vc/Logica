/*
    Resolución del problema: 02/12/2025
    Escribir un programa para determinar si una oración es un palíndromo o no.
*/

#include <iostream>
#include <windows.h>

using namespace std;

//Función para limpiar la frase (pasar a minuscula y limpiar espacios)
string limpiarCadena(const string& frase){
    string limpia = "";

    for(int i = 0; i < frase.length(); i++){
        char c = frase[i];

        //Convertir a minúscula si es letra mayúscula
        if (c >= 'A' && c <= 'Z'){
            c += 32; //Convertir a minúscula (código ASCII)
        }

        //Guardar en la cadena solo letras y números
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            limpia += c;
        }
    }

    return limpia;
}

//Función para saber si es palindromo
bool esPalindromo (const string& frase){
    int i = 0;
    int j = frase.length() - 1;

    while (i < j){
        if (frase[i] != frase[j]) return false;

        i++;
        j--;
    }
    return true;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    string frase;

    cout << "Ingrese la frase: ";
    getline(cin, frase);
    
    if(esPalindromo(limpiarCadena(frase))){
        cout << "La frase es palindromo." << endl;
    } else{
        cout << "La frase no es palindromo." << endl;
    }

    return 0;
}