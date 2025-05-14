#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
struct producto{
    int codigo;
    string nombre;
    float precio;
    int stock;
};
int main (){
    producto producto [3];
      for (int i = 0; i < 3; i++) {
         cout << "Codigo: ";
        cin >> producto[i].codigo;
        cout << "Ingrese el nombre del producto: ";
         cin >> producto[i].nombre;
        cout << "Ingrese el precio: ";
        cin >> producto[i].precio;
        cout << "Ingrese el stock: ";
        cin >> producto[i].stock;
       cout << endl; 
    }
     if (producto[0].stock > producto[1].stock) {
        cout << "La persona mayor es: " << producto[0].nombre << endl;
    } else if (producto[0].stock < producto[1].stock) {
        cout << "El producto con mayor stock es: " << producto[1].nombre << endl;
    } else {
        cout << "los productos tienen la misma cantidad de stock." << endl;
    }


  
    
}
