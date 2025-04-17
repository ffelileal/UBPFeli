#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    string clave, claveCorrecta;
    int intentos;
    claveCorrecta   = "Hola123";
    intentos =3;

    do
    { cout << "ingresar la clave" << endl;
        cin >> clave;
        intentos--;
        if (intentos == 0) {
            cout << "Se han agotado los intentos." << endl;
            break;
        }
    } while (clave != claveCorrecta);

}