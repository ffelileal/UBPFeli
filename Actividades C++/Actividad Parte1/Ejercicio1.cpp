#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int main() {
    cout << "Presione una tecla para iniciar el conteo: ";
    _getch();

    for (int i = 0; i <= 10; i++) {
        Sleep(2000);
        cout << i << endl;
    }

    return 0;
}

