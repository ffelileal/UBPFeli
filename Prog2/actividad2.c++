#include <iostream>
using namespace std;

int main() {
    int calificaciones[10];
    int favoritas = 0;

    cout << "Ingrese la calificación (1 a 10) de cada cancion:\n";

    for (int i = 0; i < 10; i++) {
        int puntuacion;

        do {
            cout << "Cancion " << (i + 1) << ": ";
            cin >> puntuacion;

            if (puntuacion < 1 || puntuacion > 10) {
                cout << "Calificacion inválida. Debe estar entre 1 y 10.\n";
            }
        } while (puntuacion < 1 || puntuacion > 10);

        calificaciones[i] = puntuacion;

        if (puntuacion >= 8) {
            favoritas++;
        }
    }

    cout << "\nCantidad de canciones favoritas (8 o más): " << favoritas << endl;

    return 0;
}
