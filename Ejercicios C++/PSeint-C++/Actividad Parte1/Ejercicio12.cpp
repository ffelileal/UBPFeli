#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    float num1, num2;
    int resultado;
    cout << "Ingrese 2 numeros: ";
    cin >> num1 >> num2;
    resultado = 0;
    for (int n = 1; n <= num2; n++) { 
        resultado = resultado + num1;
    }    
    cout << "El resultado  es: " << resultado << endl;
    
    
}