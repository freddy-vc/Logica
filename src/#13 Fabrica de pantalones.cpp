/*
    Resolución del problema: 28/06/2025
    Realice un algoritmo para resolver el siguiente problema: una fábrica de pantalones desea calcular cuál es el precio final de venta 
    y cuánto ganará por los N pantalones que produzca con el corte de alguno de sus modelos, para esto se cuenta con la siguiente información:
    a) Tiene dos modelos A y B, tallas 30, 32 y 36 para ambos modelos.
    b) Para el modelo A se utiliza 1.50 m de tela, y para el B 1.80 m.
    c) Al modelo A se le carga 80 % del costo de la tela, por mano de obra. Al modelo B se le carga 95 % del costo de la tela, por el mismo 
    concepto.
    d) A las tallas 32 y 36 se les carga 4 % del costo generado por mano de obra y tela, sin importar el modelo.
    e) Cuando se realiza el corte para fabricar una prenda sólo se hace de un solo modelo y una sola talla.
    f) Finalmente, a la suma de estos costos se les carga 30%, que representa la ganancia extra de la tienda.
*/

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <limits>

using namespace std;


void limpiarEntrada(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

char pedirModeloPantalon(const string& mensaje){
    char modelo;
    while(true){
        cout << mensaje;
        cin >> modelo;
        if (modelo == 'A' || modelo == 'B') return modelo;
        cout << "El modelo no esta en nuestro inventario!. Intente nuevamente" << endl;
    }
}

int pedirTallaPantalon(const string& mensaje){
    int talla;
    while(true){
        cout << mensaje;
        cin >> talla;
        if (!cin.fail() && (talla == 30 || talla == 32 || talla == 36)) return talla;
        cout << "No hay pantalones con esta talla." << endl;
        limpiarEntrada();
    }
}

float pedirCostoPorMetroDeTela(const string& mensaje){
    float costo;
    while(true){
        cout << mensaje;
        cin >> costo;
        if (!cin.fail() && costo >= 0) return costo;
        cout << "Entrada invalida. Ingrese un costo positivo" << endl;
        limpiarEntrada();
    }
}

int pedirCantidadPantalon(const string& mensaje){
    int cantidad;
    while(true){
        cout << mensaje;
        cin >> cantidad;
        if (!cin.fail() && cantidad >= 0) return cantidad;
        cout << "Entrada invalida. Ingrese una cantidad positiva" << endl;
        limpiarEntrada();
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    
    cout << "=== CALCULADORA DE COSTOS - FABRICA DE PANTALONES ===" << endl;
    cout << endl;
    
    char modelo = pedirModeloPantalon("Ingrese el modelo del pantalón (A, B): ");
    int talla = pedirTallaPantalon("Ingrese la talla del pantalón: ");
    float costoPorMetro = pedirCostoPorMetroDeTela("Ingrese el costo por metro de la tela: ");
    int cantidad = pedirCantidadPantalon("Ingrese la cantidad de pantalones a realizar: ");

    float metrosTela, costoTela, manoDeObra, aumentoTalla = 0, precioFinal, gananciaTotal;

    if (modelo == 'A'){
        metrosTela = 1.50;
        costoTela = costoPorMetro * metrosTela;
        manoDeObra = costoTela * 0.8;
    } else{
        metrosTela = 1.80;
        costoTela = costoPorMetro * metrosTela;
        manoDeObra = costoTela * 0.95;
    }

    float subtotal = costoTela + manoDeObra;

    if (talla == 32 || talla == 36)
        aumentoTalla = subtotal * 0.04;
    
    // Calcular costo total por pantalón
    float costoTotalPorPantalon = subtotal + aumentoTalla;
    
    // Calcular precio de venta por pantalón (costo + 30% ganancia)
    float precioVentaPorPantalon = costoTotalPorPantalon * 1.30;
    
    // Calcular ganancia por pantalón
    float gananciaPorPantalon = precioVentaPorPantalon - costoTotalPorPantalon;
    
    // Calcular totales para N pantalones
    float costoTotalProduccion = costoTotalPorPantalon * cantidad;
    float precioVentaTotal = precioVentaPorPantalon * cantidad;
    gananciaTotal = gananciaPorPantalon * cantidad;

    cout << endl;
    cout << "=== RESULTADOS DEL CÁLCULO ===" << endl;
    cout << fixed << setprecision(2);
    cout << endl;
    
    cout << "INFORMACIÓN DEL PRODUCTO:" << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Talla: " << talla << endl;
    cout << "Cantidad: " << cantidad << " pantalones" << endl;
    cout << "Metros de tela por pantalón: " << metrosTela << " m" << endl;
    cout << endl;
    
    cout << "COSTOS POR PANTALÓN:" << endl;
    cout << "Costo de tela: $" << costoTela << endl;
    cout << "Costo de mano de obra: $" << manoDeObra << endl;
    cout << "Cargo adicional por talla: $" << aumentoTalla << endl;
    cout << "Costo total por pantalón: $" << costoTotalPorPantalon << endl;
    cout << endl;
    
    cout << "PRECIOS Y GANANCIAS:" << endl;
    cout << "Precio de venta por pantalón: $" << precioVentaPorPantalon << endl;
    cout << "Ganancia por pantalón: $" << gananciaPorPantalon << endl;
    cout << endl;
    
    cout << "TOTALES PARA " << cantidad << " PANTALONES:" << endl;
    cout << "Costo total de producción: $" << costoTotalProduccion << endl;
    cout << "Precio de venta total: $" << precioVentaTotal << endl;
    cout << "Ganancia total: $" << gananciaTotal << endl;
    cout << endl;

    return 0;
}