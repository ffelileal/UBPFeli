#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main() {
    string Letra;
    int contador = 0;

    for (int let = 1; let <= 10; let++) {
        cout << "Ingrese un Caracter: ";
        cin >> Letra;
        if (Letra == "A" or Letra == "a" or Letra == "E" or Letra == "e" or Letra == "I" or Letra == "i" or Letra == "O" or Letra == "o" or Letra =="U" or Letra == "u")
        contador++;
    }

    cout << "La cantidad de vocales ingresadas es: " << contador << endl;

    return 0;
}
