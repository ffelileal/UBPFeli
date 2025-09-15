#include <iostream>
using namespace std;

// Función recursiva: cuenta regresiva entre dos números
void cuentaRegresiva(int a, int b) {
    if (a < b) return;   // Caso base: cuando el inicial es menor al final
    cout << a << " ";
    cuentaRegresiva(a - 1, b); // Llamada recursiva
}

int main() {
    int inicio, fin;
    cout << "Ingrese el numero inicial: ";
    cin >> inicio;
    cout << "Ingrese el numero final: ";
    cin >> fin;

    cout << "Cuenta regresiva: ";
    cuentaRegresiva(inicio, fin);
    cout << endl;

    return 0;
}
