#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
struct alumno {
  string nombre;
  int notas;
  
};
int main (){
   alumno alumno[3];
    float promedio;
        cout << "Ingrese el nombre del alumno: ";
        cin >> alumno[0].nombre;
        cout << "Ingrese la nota 1: ";
        cin >> alumno[0].notas;
        cout << "Ingrese la nota 2: ";
        cin >> alumno[0].notas;
        cout << "Ingrese la nota 3: ";
        cin >> alumno[0].notas;
        cout << endl;
    promedio = (alumno[0].notas + alumno[1].notas + alumno[2].notas) / 3;
    if (promedio >=6) {
        cout << "El alumno " << alumno[0].nombre << " esta aprobado" << endl;
    } else {
        cout << "El alumno " << alumno[0].nombre << " No esta aprobado" << endl;
    }   
}
