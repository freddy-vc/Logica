#include "estudiante.cpp"
#include "list.cpp"

#include <iomanip>
#include <fstream>
#include <vector>

vector<string> leerEstudiantes() {
    ifstream archivo("estudiantes.csv");
    string linea;
    vector<string> est;

    string nombre;
    while(getline(archivo, linea)){
        int pos = linea.find(' ');
        nombre = linea.substr(pos + 1) + " " + linea.substr(0,pos);
        est.push_back(nombre);
    }
    archivo.close();

    return est;
}


void ordenarEstudiantes(const vector<string>& nombres, List<Estudiante>& lista) {
    vector<string> ordenados = nombres;

    for (int i = 0; i < ordenados.size() - 1; i++) {
        for (int j = 0; j < ordenados.size() - 1 - i; j++) {
            if (ordenados[j] > ordenados[j + 1]) {
                swap(ordenados[j], ordenados[j + 1]);
            }
        }
    }

    for (int i = 0; i < ordenados.size(); i++) {
        lista.insert(i, Estudiante(ordenados[i]));
    }
}

int main() {
    List<Estudiante> estudiantes;
    vector<string> nombres = leerEstudiantes();

    ordenarEstudiantes(nombres, estudiantes);

    for(int i = 0; i < estudiantes.size(); i++) {
        cout << "Ingrese las notas para " 
             << estudiantes.get(i).getNombre() << endl;

        int n;
        cout << "Cantidad de notas (max 4): ";
        cin >> n;

        for(int j = 0; j < n; j++){
            float cal;
            cout << "Ingrese la calificación " << j + 1 << ": ";
            cin >> cal;
            estudiantes.get(i).addCalificacion(cal);
        }
    }

    for(int i = 0; i < estudiantes.size(); i++){
        cout << estudiantes.get(i);
    }

    return 0;
}