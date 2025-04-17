#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    float promedio;
    int suma, cantidad;
    suma = 0;
    cout << "Ingrese la cantidad de alumnos: ";
    cin >> cantidad;
    for (int alum = 1;alum <= cantidad; alum++)
    {
        cout << "Ingrese la nota del alumno " << alum << ": ";
        int nota;
        cin >> nota;
        suma = suma + nota;
    }
    promedio = suma / cantidad;
    cout << "El promedio de las notas es: " << promedio << endl;

}