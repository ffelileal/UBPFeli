#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
int num, suma;
suma = 0;
do {
    cout << "Ingrese un numero: ";
    cin >> num;
    if (num >= 0) {
        suma += num;
    }
} while (num >= 0);
cout << "El resultado obtenido es: " << suma << endl;
return 0;
}

