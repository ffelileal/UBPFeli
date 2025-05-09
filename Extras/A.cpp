#include <iostream>   // Permite usar cout y cin
#include <iomanip>    // Permite usar setw para dar formato

using namespace std;

int main() {
    int tabla[10][10]; // Declaramos una matriz de 10x10

    // Cargamos la matriz con las multiplicaciones
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabla[i][j] = (i + 1) * (j + 1); // multiplicamos del 1 al 10
        }
    }

    // Mostramos la tabla en forma de matriz
    cout << "Tabla de multiplicar del 1 al 10:\n\n";

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(4) << tabla[i][j]; // imprimimos el número con espacio fijo (4 caracteres)
        }
        cout << endl; // salto de línea después de cada fila
    }

    return 0; // Fin del programa
}
