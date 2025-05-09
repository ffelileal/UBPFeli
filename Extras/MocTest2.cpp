#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
   int socio, sociocorrecto, intentos;
   intentos = 3;
    sociocorrecto = 12345678;
    do
    { cout << "ingresar el numero de socio" << endl;
        cin >> socio;
        intentos--;
        if (intentos == 0) {
            cout << "Se han agotado los intentos." << endl;
            break;
        }
    } while (socio != sociocorrecto);

}

