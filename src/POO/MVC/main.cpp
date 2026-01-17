#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class Empleado{
    private:
        float salario;
        string nombre;
    public:
        Empleado(string nombre, float salario) : salario(salario), nombre(nombre) {}
        float getSalario() { return salario; }
        void setSalario(float salario) { this-> salario = salario; }
        string getNombre() { return nombre; }
        void setNombre(string nombre) { this->nombre = nombre; }

        friend ostream& operator<<(ostream& out, Empleado e) {
            out << "Nombre: " << e.nombre << "\tSalario: " << e.salario;
            return out;
        }
};

class EmpleadoModel{ 
    private: 
        vector<Empleado> empleados; 
    public: 
        void addEmpleado(string nombre,float salario){ 
            empleados.emplace_back(nombre,salario); 
        } 
        vector<Empleado> getEmeplados(){ 
            return empleados; 
        } 
        Empleado getEmpleado(int index){ 
            return empleados[index]; 
        } 
        void updateEmpleado(int index,string nombre,float salario){ 
            if(index >=0 && index <empleados.size()){ 
                empleados[index] = Empleado(nombre,salario); 
            }
        } 
        void removeEmpleado(int index){ 
            if(index >=0 && index<empleados.size()){ 
                empleados.erase(empleados.begin()+index); 
            } 
        } 
};

class EmpleadoView{ 
    public: 
        void mostrarEmpleados(const vector<Empleado>& empleados){ 
            cout << "Empleados:" << endl; 
            for(const Empleado& empleado:empleados){ 
                cout << empleado <<endl; 
            } 
        }
        void mostrarEmpleado(const Empleado& empleado){ 
            cout << "Empleado:" << endl; 
            cout << empleado << endl; 
        } 
        Empleado solicitarDatosEmpleado(){ 
            string nombre; 
            float salario; 
            cout << "Ingrese el nombre del empleado: "; 
            cin >> nombre; 
                cout << "Ingrese el salario del empleado: "; 
                cin >> salario; 

                return Empleado(nombre,salario); 
        } 
        int solicitarIndiceEmpleado(){ 
            int index; 
            cout<<"Ingrese el indice del usuario:"; 
            cin>>index; 

            return index; 
        } 
};

class EmpleadoController{ 
    private: 
        EmpleadoModel empleadoModel; 
        EmpleadoView empleadoView; 
    public: 
        void show(){ 
            vector<Empleado> empleados = empleadoModel.getEmeplados(); 
            empleadoView.mostrarEmpleados(empleados); 
        } 
        void show(int index){ 
            Empleado empleado = empleadoModel.getEmpleado(index); 
            empleadoView.mostrarEmpleado(empleado); 
        }
        void create(){ 
            Empleado empleado = empleadoView.solicitarDatosEmpleado(); 
            empleadoModel.addEmpleado(empleado.getNombre(), empleado.getSalario()); 
        } 
        void update(){ 
            int index = empleadoView.solicitarIndiceEmpleado(); 
            Empleado empleado = empleadoView.solicitarDatosEmpleado(); 
            empleadoModel.updateEmpleado(index,empleado.getNombre(), empleado.getSalario()); 
        } 
        void remove(){ 
            int index = empleadoView.solicitarIndiceEmpleado(); 
            empleadoModel.removeEmpleado(index); 
        } 
};

int main() {

    EmpleadoController controlador; 
    int opcion; 
    do{ 
        std::cout <<"===CRUD de Usuarios===\n"; 
        std::cout<<"1. Agregar Usuario\n"; 
        std::cout<<"2. Mostrar Usuarios\n"; 
        std::cout<<"3. Actualizar Usuario\n"; 
        std::cout<<"4. Eliminar Usuario\n"; 
        std::cout<<"0. Salir\n"; 
        std::cout<<"Ingrese una opción:"; 
        std::cin >> opcion; 
        switch(opcion){ 
            case 1: 
                controlador.create(); 
                break; 
            case 2: 
                controlador.show(); 
                break; 
            case 3: 
                controlador.update(); 
                break; 
            case 4: 
                controlador.remove();
                break; 
            case 0: 
                std::cout<<"Saliendo del programa...\n"; 
                break; 
            default: 
                std::cout<<"Opción inválida. Intentenuevamente.\n"; 
                break; 
        } 
        std::cout<<"---------------------------\n"; 
    }while(opcion!=0); 
    
    return 0;
}

