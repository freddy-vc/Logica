#include "vehiculo.h"
#include "automovil.h"
#include "trailer.h"
#include "motocicleta.h"
#include "remolque.h"
#include "motocarguero.h"

#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    Motocicleta mt09("Yamaha", 2, "150", "ABC123", 150, 0.4, 0.15);
    mt09.print(std::cout);
    std::cout << std::endl;

    Remolque nissan("Nissan", 8, "xyz2000", "XYZ134", 2000, 1000, "Plastico");
    nissan.print(std::cout);
    std::cout << std::endl;

    Motocarguero suzuki26("Suzuki", 3, "VS1", "GDF562", 200, 0.4, 0.15, 220, "Metal");
    std::cout << suzuki26;

    return 0;
}