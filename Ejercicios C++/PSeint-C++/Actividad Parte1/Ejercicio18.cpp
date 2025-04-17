#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main (){
    int edad;
    do
    { cout << " Ingrese una edad: ";
        cin >> edad;
       
    } while (edad<100);
    cout << "La edad ingresada es: " << edad <<" anios de edad " << endl;

}
