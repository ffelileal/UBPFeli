#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main (){
    float sueldo1, sueldo2, sueldo3, sueldo4, mayor, descuento;

    cout << "Ingrese los cuatro últimos sueldos del empleado:" << endl;
    cin >> sueldo1 >> sueldo2 >> sueldo3 >> sueldo4;

    mayor = sueldo1;
    if (sueldo2 > mayor) {
        mayor = sueldo2;
    }
    if (sueldo3 > mayor) {
        mayor = sueldo3;
    }
    if (sueldo4 > mayor) {
        mayor = sueldo4;
    }

    if (mayor > 700) {
        descuento = mayor * 0.02;
        cout << "El mayor sueldo es: " << mayor << endl;
        cout << "El descuento del 2% es: " << descuento << endl;
    } else {
        cout << "El mayor sueldo es: " << mayor << endl;
        cout << "No corresponde descuento." << endl;
    }

    return 0;
}