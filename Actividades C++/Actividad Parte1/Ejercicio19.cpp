#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main (){
    int suma = 0;
    char tecla;
    
    cout << "Apriete una tecla Aleatoria" << endl;
    cin >> tecla; 
    
    for (int mult = 5; mult <= 100; mult += 5) {
        suma += mult;
    }
    
    cout << "La suma de los múltiplos de 5 entre 1 y 100 es: " << suma << endl;
    
    return 0;

}
