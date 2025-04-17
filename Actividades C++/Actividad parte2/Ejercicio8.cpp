#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main() {
    float parcial1;
    float parcial2;
    float promedioTP;
    float recuperatorio;
    string condicion;

    cout << "Nota del primer parcial: ";
    cin >> parcial1;
    cout << "Nota del segundo parcial: ";
    cin >> parcial2;
    cout << "Promedio de trabajos prácticos: ";
    cin >> promedioTP;

    if (parcial1 >= 8 && parcial2 >= 8 && promedioTP >= 8) {
        condicion = "Promocionado";
    } else {
        cout << "Ingrese la nota del recuperatorio: ";
        cin >> recuperatorio;

        if (((parcial1 >= 4 && parcial2 >= 4) || (parcial1 >= 4 && recuperatorio >= 4) || (parcial2 >= 4 && recuperatorio >= 4)) && promedioTP >= 4) {
            condicion = "Regular";
        } else {
            condicion = "Libre";
        }
    }
    cout << "La condición final del alumno es: " << condicion << endl;
    return 0;
   
}