#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    int cantidad;
    float precioPorUnidad, total;

    cout << "Ingrese la cantidad de alfajores que desea comprar: ";
    cin >> cantidad;

    if (cantidad >= 5) {
        precioPorUnidad = 80;
    } else {
        precioPorUnidad = 100; 
    }

    total = cantidad * precioPorUnidad;

    cout << "El precio por unidad es: $" << precioPorUnidad << endl;
    cout << "El total a pagar es: $" << total << endl;

    return 0;
}


