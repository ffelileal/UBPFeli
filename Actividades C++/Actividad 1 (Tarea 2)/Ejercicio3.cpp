#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main() {
    int Suma = 0, contador = 0, numero;

    do {
        cout << "Ingrese un numero: ";
        cin >> numero;

        if (numero != 0) { 
            Suma += numero;
            contador++;
        }
    } while (numero != 0); 

    cout << "Cantidad de numeros ingresados: " << contador << endl;
    cout << "Suma total: " << Suma << endl;

    return 0;
}