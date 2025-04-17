#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    float Recaudacion, Promedio, Sueldo;
    cout << "Ingrese de cuanto fue su Recaudacion: ";
    cin >> Recaudacion;
    Promedio = Recaudacion / 30;
    cout << "Promedio diario recaudado: $" << Promedio << endl;
    
    if (Recaudacion > 1200) {
        Sueldo = Recaudacion * 0.3;
    } else {
        Sueldo = Recaudacion * 0.25;
    }
    cout << "Sueldo del chofer: $" << Sueldo << endl;
    
    if (Promedio < 80) {
        cout << "Este chofer posiblemente deba ser reemplazado." << endl;
    }
    return 0;
    
}
