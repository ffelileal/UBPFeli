#include <iostream>
using namespace std;

int main() {
    float total = 0, valor;
    string dias[] = {"lunes", "martes", "miércoles", "jueves", "viernes"};

    for (int i = 0; i < 5; i++) {
        cout << "ingrese la cantidad de horas de los dias: " << dias[i] << ": ";
        cin >> valor;
        total += valor;
    }

    cout << "El total de  cantidad de horas de clases es de: " << total << endl;

    return 0;
}

