#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main(){
    int numeros;
    do {
        cout << "Ingrese un numero: ";
        cin >> numeros;
        if (numeros < 0) {
            cout << "El numero es negativo" << endl;
        } else if (numeros > 0) {
            cout << "El numero es positivo" << endl;
        } else {
            cout << "El numero es cero" << endl;
        }
    } while (numeros != 0);
}