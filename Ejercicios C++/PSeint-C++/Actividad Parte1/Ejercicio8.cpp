#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
char nombre[50];
int nom;
for (nom = 1; nom <= 5; nom++){
    cout << "Ingrese un nombre: ";
    cin >> nombre;
    cout << "El nombre ingresado es: " << nombre << endl;
    system("pause");
    system("cls");


}
return 0;
}