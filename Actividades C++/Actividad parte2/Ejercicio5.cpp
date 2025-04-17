#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    float precio1, precio2, precio3, cant1, cant2, cant3;
    float total1, total2, total3, totalGeneral;
    
    cout << "Ingrese precio y cantidad del producto 1: ";
    cin >> precio1 >> cant1;
    cout << "Ingrese precio y cantidad del producto 2: ";
    cin >> precio2 >> cant2;
    cout << "Ingrese precio y cantidad del producto 3: ";
    cin >> precio3 >> cant3;
    
    total1 = precio1 * cant1;
    total2 = precio2 * cant2;
    total3 = precio3 * cant3;
    totalGeneral = total1 + total2 + total3;
    
    cout << "Total producto 1: $" << total1 << endl;
    cout << "Total producto 2: $" << total2 << endl;
    cout << "Total producto 3: $" << total3 << endl;
    cout << "Total sin descuento: $" << totalGeneral << endl;
    
    if (totalGeneral > 100) {
        totalGeneral *= 0.9;
        cout << "Se aplica un 10% de descuento. Total con descuento: $" << totalGeneral << endl;
    }
    
    return 0;
    
}
