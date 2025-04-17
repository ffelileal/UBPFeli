#include <iostream>
using namespace std;

int main() {
    int aprobados = 0; // Contador de aprobados

    for (int a = 1; a <= 10; a++) { // Iterar de 1 a 10
        int nota;
        cout << "Ingrese una nota: ";
        cin >> nota;

        if (nota >= 6) { // Verificar si la nota es aprobatoria
            aprobados++;
        }
    }

    cout << "Cantidad de aprobados: " << aprobados << endl;

    return 0;
}
