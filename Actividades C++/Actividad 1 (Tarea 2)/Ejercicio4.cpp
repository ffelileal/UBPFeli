#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main(){
float precio, precioFinal;

cout << "ingrese el valor del producto: ";
cin >> precio;

while(precio != 0){
    precioFinal = precio - (precio * 0.15);
    cout << "El el precio final es de: $" << precioFinal << endl;
    cout << "ingrese el valor del producto: ";
    cin >> precio;


}
return 0;
}

