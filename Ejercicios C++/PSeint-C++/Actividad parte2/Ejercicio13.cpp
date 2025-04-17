#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cmath> 
using namespace std;
int main (){
    float t1, t2, t3, t4, promedio, diferencia;

    cout << "Ingrese la primera temperatura:" << endl;
    cin >> t1;
    cout << "Ingrese la segunda temperatura:" << endl;
    cin >> t2;
    cout << "Ingrese la tercera temperatura:" << endl;
    cin >> t3;
    cout << "Ingrese la cuarta temperatura:" << endl;
    cin >> t4;

    promedio = (t1 + t2 + t3 + t4) / 4;
    cout << "El promedio de las temperaturas es: " << promedio << endl;

    cout << "Temperaturas con diferencia mayor a 10.5 grados:" << endl;

    diferencia = abs(t1 - promedio);
    if (diferencia > 10.5) {
        cout << "Temperatura 1: " << t1 << endl;
    }

    diferencia = abs(t2 - promedio);
    if (diferencia > 10.5) {
        cout << "Temperatura 2: " << t2 << endl;
    }

    diferencia = abs(t3 - promedio);
    if (diferencia > 10.5) {
        cout << "Temperatura 3: " << t3 << endl;
    }

    diferencia = abs(t4 - promedio);
    if (diferencia > 10.5) {
        cout << "Temperatura 4: " << t4 << endl;
    }

    return 0;

}

