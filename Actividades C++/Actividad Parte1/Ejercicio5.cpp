#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int main() {
    cout << "Presione una tecla para iniciar el conteo: ";
    int contador = 0;
    int num = 0;
    _getch();
    while (contador <= 10) {
        Sleep(1200);
        cout << num << endl;
        num += 2;
        contador++;
    }
    cout << "Fin del conteo." << endl;

    return 0;
}
