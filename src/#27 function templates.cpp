#include <iostream>
#include <windows.h>

using namespace std;

// Función para imprimir un arreglo
template<typename T, int N>
void print(T(&array)[N]){
    for(int i=0; i < N; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

// Función para encontrar el menor de un arreglo
template<typename T, int N>
T smallest(T(&array)[N]){
    T smallest = array[0];

    for(int i = 1; i < N; i++){
        if (array[i]< smallest)
            smallest  = array[i];
    }
    
    return smallest;
}

// Función para ordenar un arreglo mediante selection sort
template<typename T, int N>
void selectionSort(T(&array)[N]) {

    for(int i = 0; i < N - 1; i++) {

        int min = i;

        // Buscar el índice del menor elemento
        for(int j = i + 1; j < N; j++) {
            if (array[j] < array[min])
                min = j;
        }

        // Intercambiar array[i] con array[min]
        T aux = array[i];
        array[i] = array[min];
        array[min] = aux;
    }
}

// Función para encontrar un valor en un arreglo
template<typename T, int N>
bool findValue(T(&array)[N], T search){
    for(int i = 0; i < N; i++){
        if(array[i] == search)
            return true;
    }

    return false;
}

// Función para revertir el orden de un array
template<typename T, int N>
void invest(T(&array)[N]){
    int i = 0;
    int j = N - 1;

    while(i < j){
        T aux = array[i];
        array[i] = array[j];
        array[j] = aux;

        i++;
        j--;
    }
}


int main(){
    SetConsoleOutputCP(CP_UTF8);

    int arr1[4] = {7, 3, 5, 1};
    double arr2[3] = {7.5, 6.1, 4.6};
    print(arr1);
    print(arr2);

    cout << "Small 1: " << smallest(arr1) << endl;;
    cout << "Small 2: " << smallest(arr2) << endl;


    selectionSort(arr1);
    print(arr1);

    invest(arr2);
    print(arr2);

    return 0;
}