#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main (){
    string Nombre;
    int total, correctas;
    float porcentaje;

    cout << "Ingresae el nombre del postulante" << endl;
    cin >> Nombre;
    cout << "Ingrese la cantidad total de preguntas" << endl;
    cin >> total;
    cout << "Ingrese la cantidad de respuestas correctas" << endl;
    cin >> correctas;

    porcentaje = (float(correctas) / float(total)) * 100;
    cout << "Postulante: " << Nombre << endl;
    cout << "Porcentaje de respuestas correctas: " << porcentaje << "%" << endl;

    if (porcentaje >= 90) {
        cout << "Nivel: Nivel Superior" << endl;
    } else if (porcentaje >= 75) {
        cout << "Nivel: Nivel Medio" << endl;
    } else if (porcentaje >= 50) {
        cout << "Nivel: Nivel Regular" << endl;
    } else {
        cout << "Nivel: Fuera de Nivel" << endl;
    }
 


    return 0;
}

