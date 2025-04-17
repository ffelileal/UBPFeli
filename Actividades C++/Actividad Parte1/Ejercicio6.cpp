#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main() {
    int edad, promedio = 0, prom;

    for (int i = 1; i <= 5; i++) {
        cout << "Ingrese una edad: ";
        cin >> edad;
        promedio += edad;
    }

    prom = promedio / 5;
    cout << "El promedio de las edades ingresadas es: " << prom << endl;

    return 0;
}

