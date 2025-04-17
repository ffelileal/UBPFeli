#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main (){
    float altura, suma = 0, promedio;
    int contador = 0;

    do {
        cout << "Ingrese una altura: ";
        cin >> altura;
        
        if (altura >= 0.5) {
            suma += altura;
            contador++;
        }
    } while (altura >= 0.5);

    if (contador > 0) {
        promedio = suma / contador;
        cout << "El promedio de altura es: " << promedio << " cm" << endl;
    } else {
        cout << "No se ingresaron alturas válidas." << endl;
    }

    return 0;

}

