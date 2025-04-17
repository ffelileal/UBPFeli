#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main (){
    float num1, num2, num3, num4, aux;

    cout << "Ingrese el primer número:" << endl;
    cin >> num1;
    cout << "Ingrese el segundo número:" << endl;
    cin >> num2;
    cout << "Ingrese el tercer número:" << endl;
    cin >> num3;
    cout << "Ingrese el cuarto número:" << endl;
    cin >> num4;

    if (num1 > num2) {
        aux = num1;
        num1 = num2;
        num2 = aux;
    }
    
    if (num1 > num3) {
        aux = num1;
        num1 = num3;
        num3 = aux;
    }
    
    if (num1 > num4) {
        aux = num1;
        num1 = num4;
        num4 = aux;
    }
    
    if (num2 > num3) {
        aux = num2;
        num2 = num3;
        num3 = aux;
    }
    
    if (num2 > num4) {
        aux = num2;
        num2 = num4;
        num4 = aux;
    }
    
    if (num3 > num4) {
        aux = num3;
        num3 = num4;
        num4 = aux;
    }

    cout << "Números ordenados de menor a mayor:" << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    cout << num4 << endl;

    return 0;
    
}

