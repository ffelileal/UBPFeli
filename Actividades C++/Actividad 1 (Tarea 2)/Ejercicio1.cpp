#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main (){
    int  Nota1, Nota2, Nota3;
    float promedio;
    cout << "Ingrese sus 3 notas: " << endl;
    cin >> Nota1;
    cin >> Nota2;
    cin >> Nota3;
    promedio = (Nota1 + Nota2 + Nota3) / 3;
    if (promedio >= 6){
        cout << "El alumno esta aprobado con " << promedio << endl;
    }else{
        cout << "El alumno no esta aprobado" << endl;
    }
    return 0;
}

