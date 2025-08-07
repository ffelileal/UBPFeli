#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
    char nombre[30], apellido[30];
    char nombreCompleto[61];

    cout << "Ingrese su nombre: ";
    cin >> nombre;

    cout << "Ingrese su apellido: ";
    cin >> apellido;

    nombreCompleto[0] = '\0';

    strcat(nombreCompleto, nombre);
    strcat(nombreCompleto, " ");
    strcat(nombreCompleto, apellido);

    string cadenaFinal = nombreCompleto;

    cout << "Nombre completo: " << cadenaFinal << endl;
    cout << "Longitud total: " << cadenaFinal.length() << endl;

    return 0;
}
