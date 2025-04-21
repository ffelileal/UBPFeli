#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main (){
    int n1, n2, n3, n4, n5;
    cout << "Ingrese 5 numeros de una sola cifra: ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
    if (n1 == n5 && n2 == n4) {
        cout << "El numero es capicua" << endl;
    } else {
        cout << "El numero no es capicua" << endl;
    }
}