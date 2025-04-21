#include <iostream>
#include <stdlib.h>
#include <iomanip> 
#include <conio.h>

using namespace std;

int main (){
    int  Nota1, Nota2, Nota3;
    float promedio;
    cout << "Ingrese sus 3 notas: " << endl;
    cin >> Nota1;
    cin >> Nota2;
    cin >> Nota3;
   promedio = (Nota1 + Nota2 + Nota3) / 3.0;
   cout << fixed << setprecision(2); 
    if (promedio >= 6){
        cout << "El alumno esta aprobado con: " << promedio << endl;
    }else{
        cout << "El alumno esta desaprobbado con: " <<promedio << endl;
    }
    return 0;
}

