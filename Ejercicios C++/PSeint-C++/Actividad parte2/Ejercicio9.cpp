#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    float lado1, lado2, lado3, ang1, ang2, ang3;
    cout << "Ingrese los tres lados del triangulo:" << endl;
    cin >> lado1 >> lado2 >> lado3;
    cout << "Ingrese los tres angulos del triangulo:" << endl;
    cin >> ang1 >> ang2 >> ang3;

    if ( lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1 && ang1 + ang2 + ang3 == 180) {
        cout << "Pueden formar un triangulo." << endl;
    } else {
        cout << "No pueden formar un triangulo." << endl;
    }
    return 0;
    
    

}