#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    string clave, claveCorrecta;
    claveCorrecta   = "Hola123";
    do
    { cout << "ingresar la clave" << endl;
        cin >> clave;
    } while (clave != claveCorrecta);
    cout << "Ingreso exitoso" << endl;
    return 0;
}



