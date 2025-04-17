#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main (){
    char caracter;
    int contador = 0;
    
    for (int letra = 1; letra <= 15; letra++) {
        cout << "Ingrese el caracter numero:  " << letra << ": ";
        cin >> caracter;
        
        if (caracter >= 'a' && caracter <= 'z') {
            caracter -= 32; 
        }
        
        if (caracter == 'A') {
            contador++;
        }
    }
    
    cout << "La cantidad de letras A ingresadas es: " << contador << endl;
    
    return 0;

}

