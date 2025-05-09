#include <iostream>
#include <string>
using namespace std;

int main() {
    int contadorSi = 0;
    string respuesta;

    for (int i = 1; i <= 10; i++) {
        cout << "Confirme asistencia (sí/no): ";
        cin >> respuesta;

        if (respuesta == "sí" || respuesta == "si" || respuesta == "SI" || respuesta == "Sí") {
            contadorSi++;
        }
    }

    cout << "La cantidad de asistencias confirmadas (sí) es: " << contadorSi << endl;

    return 0;
}