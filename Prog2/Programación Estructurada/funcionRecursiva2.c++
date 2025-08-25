#include <iostream>
using namespace std;

void invertir(int nro) {

    if (nro < 10) {  // Sale de la recursión si el número tiene un dígito
        cout << nro;
    } else {

        cout << nro % 10;   // Calcula el módulo/resto (último dígito)
        invertir(nro / 10); // Llama a la función recursiva con la parte entera (sin el último dígito)
    }
}

int main() {
    int nro;
    cout << "Ingrese el numero a invertir: ";
    cin >> nro;

    cout << "\nNumero ingresado: " << nro;
    cout << "\nNumero INVERTIDO: ";
    invertir(nro);
    cout << endl << endl;

    return 0;
}
