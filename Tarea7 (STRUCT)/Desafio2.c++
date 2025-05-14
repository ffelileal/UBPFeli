#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Persona {
    string nombre;
    int edad;
};

int main() {
    Persona personas[2];
    cout << "Ingrese los datos de las personas:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Nombre de la persona " << i + 1 << ": ";
        cin >> personas[i].nombre;
        cout << "Edad de la persona " << i + 1 << ": ";
        cin >> personas[i].edad;
    }
    if (personas[0].edad > personas[1].edad) {
        cout << "La persona mayor es: " << personas[0].nombre << endl;
    } else if (personas[0].edad < personas[1].edad) {
        cout << "La persona mayor es: " << personas[1].nombre << endl;
    } else {
        cout << "Ambas personas tienen la misma edad." << endl;
    }

    return 0;
   
}
