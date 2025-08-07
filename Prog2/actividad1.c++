#include <iostream>
using namespace std;

int main() {
    int puntuaciones[30];
    int cantidadPares = 0;

    cout << "Ingrese las puntuaciones de los 30 niveles:\n";

    for (int i = 0; i < 30; i++) {
        cout << "Nivel " << (i + 1) << ": ";
        cin >> puntuaciones[i];

        if (puntuaciones[i] % 2 == 0) {
            cantidadPares++;
        }
    }

    cout << "\nCantidad de niveles con puntuacion par: " << cantidadPares << endl;

    return 0;
}
