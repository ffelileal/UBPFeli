#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    string lib;
    int precio =0; 

    cout << "Usted posee libreta universitaria? " << endl;
    cin >> lib;
    precio = 150;

    if (lib == "si" || lib == "Si" || lib == "SI"){
        cout << "El Cafe tiene un valor de: $"<< precio << endl;
    }else{
        precio = 200;
        cout << "El cafe tiene un valor de : $" << precio<< endl;
    }
}