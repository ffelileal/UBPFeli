#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char cadena[51];

    cout << "Ingrese una cadena: ";
    cin >> cadena;

    int longitud = strlen(cadena);

    for (int i = 0; i < longitud; i++) {
        cout << cadena[i];
        if (i < longitud -1) {
            cout << "-";
        }
    }

    cout << endl << "Longitud: " << longitud << endl;

    return 0;
}
