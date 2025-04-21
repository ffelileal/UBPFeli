#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main (){
    int Km, Valor_Peaje;
    float precio_combustible, consumo, Precio_Final;

    cout << "Ingrese la cantidad de kilometros a recorrer: ";
    cin >> Km;
    cout << "Ingrese el precio de un litro de combustible: ";
    cin >> precio_combustible;
    cout << "Ingrese el valor del peaje: ";
    cin >> Valor_Peaje;

    consumo = (Km / 13) * precio_combustible;
    Precio_Final = (consumo * 2) + (Valor_Peaje * 4);

    if (Km > 400) {
        Precio_Final += 50;
    }

    cout << "El precio del viaje es de: $" << Precio_Final << endl;
    

}
