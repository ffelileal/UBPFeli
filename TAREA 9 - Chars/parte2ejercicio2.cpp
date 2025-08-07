#include <iostream>
#include <cstring> 
using namespace std;

int main() {
    char cadena1[51], cadena2[51];

    cout << "Ingrese la primera cadena (max 50 caracteres): ";
    cin >> cadena1;
    cout << "Ingrese la segunda cadena (max 50 caracteres): ";
    cin >> cadena2;

    int resultado = strcmp(cadena1, cadena2);
    if (resultado == 0) {
        cout << "Las cadenas son iguales." << endl;
    }
    else if (resultado < 0) {
        cout << "La primera cadena es menor alfabeticamente." << endl;
    }
    else {
        cout << "La primera cadena es mayor alfabeticamente." << endl;
    }

    int longitud = strlen(cadena1);
    if (longitud >= 5) {    
        cout << "Subcadena desde la posicion 2 (longitud 4): ";
        for (int i = 1; i < 5; i++) {
            cout << cadena1[i];
        }
        cout << endl;
    }
    else {
        cout << "La cadena es demasiado corta para extraer una subcadena de longitud 4 desde la posici�n 2." << endl;
    }

    return 0;
}
