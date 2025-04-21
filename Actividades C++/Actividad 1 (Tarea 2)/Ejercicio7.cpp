#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main (){
    float largo, ancho, superfice,preciometros, preciototal;
    cout << "Ingrese el largo del terreno: ";
    cin >> largo;
    cout << "Ingrese el ancho del terreno: ";
    cin >> ancho;
    superfice = largo * ancho;
    cout << "Ingrese el precio del metro cuadrado: ";
    cin >> preciometros;
    preciototal = superfice * preciometros;
    cout << "La superfice del terreno es: " << superfice << endl;
    cout << "El precio total del terreno es: " << preciototal << endl;

}