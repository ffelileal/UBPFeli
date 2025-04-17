#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    int alumnos;
    int bancos;
    int asientosTotales;
    int faltan;
    
    cout << "Ingresar la cantidad de alumnos: ";
    cin >> alumnos;
    cout << "Ingrese la cantidad de bancos: ";
    cin >> bancos;
    
    asientosTotales = bancos * 2;
    
    if (asientosTotales >= alumnos) {
        cout << "Los bancos alcanzan." << endl;
    } else {
        faltan = (alumnos - asientosTotales) / 2;
        cout << "No alcanzan los bancos. Se necesitan " << faltan << " bancos más." << endl;
    }
    
    return 0;
    
}
