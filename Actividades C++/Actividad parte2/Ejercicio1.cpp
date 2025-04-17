#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    float num1, num2, num3, promedio, dif1, dif2, dif3;
    cout << "Ingrese 3 numeros: ";
    cin >> num1 >> num2 >> num3;
    promedio = (num1 + num2 + num3) / 3;
    if (promedio >= 10) {
        cout << "El promedio de los 3 numeros es: " << promedio << endl;
    }
    dif1 = num1 - promedio;
    dif2 = num2 - promedio;
    dif3 = num3 - promedio;
    cout << "La diferencia entre el primer numero y el promedio es: " << dif1 << endl;
    cout << "La diferencia entre el segundo numero y el promedio es: " << dif2 << endl;
    cout << "La diferencia entre el tercer numero y el promedio es: " << dif3 << endl;
    return 0;
 
}
