#include <iostream>
using namespace std;

int main() {
    float temperatura, mayor = -9999; // Inicializamos con un valor muy bajo

    for (int i = 1; i <= 4; i++) {
        cout << "Ingrese la temperatura " << i << ": ";
        cin >> temperatura;

        if (temperatura > mayor) {
            mayor = temperatura;
        }
    }

    cout << "La mayor temperatura registrada es: " << mayor << endl;

    return 0;
}

