#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main (){
    int edad, cuota;
    cout << "Ingrese su edad: ";
    cin >> edad;
    cuota = 0;
    if (edad > 0 && edad <= 15){
        cuota = 10;
        cout << "La cuota de infantiles es de: $" << cuota << endl;
    } else if (edad > 15 && edad <= 21){
        cuota = 15;
        cout << "La cuota de cadetes es de: $" << cuota << endl;
    } else if (edad > 21 && edad <= 50){
        cuota = 20;
        cout << "La cuota de Socios activos es de: $" << cuota << endl;
    } else if (edad > 60){
        cuota = 0;
        cout << "La cuota de socios mayores es de: $" << cuota << endl;
    } else {
        cout << "Edad no valida" << endl;
    }

   

    }