#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
struct agenda {
   string nombre;
   string telefono;
   string correo;
};
int main (){
   agenda contactos[5];
   for (int i=0; i<5; i++){
      cout << "Ingrese el nombre del contacto " << i+1 << ": ";
      cin >> contactos[i].nombre;
      cout << "Ingrese el telefono del contacto " << i+1 << ": ";
      cin >> contactos[i].telefono;
      cout << "Ingrese el correo del contacto " << i+1 << ": ";
      cin >> contactos[i].correo;
   }

   cout << "\nContactos con correo @gmail.com:" << endl;
    for (int i = 0; i < 5; i++) {
        string correo = contactos[i].correo;
        if (correo.size() >= 10 && correo.substr(correo.size() - 10) == "@gmail.com") {
            cout << contactos[i].nombre << " - " << contactos[i].telefono << " - " << correo << endl;
        }
      } 

    
}