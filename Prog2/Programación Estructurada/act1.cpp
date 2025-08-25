#include <iostream>
using namespace std;

// 1. Imprimir un patrón de 5x5 de asteriscos usando bucles anidados
void patronAsteriscos() {
    cout << "Patron 5x5 de asteriscos:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// 2. Busqueda lineal en un arreglo
void busquedaLineal() {
    int arr[] = {3, 8, 12, 5, 9};
    int n = 5, x;
    cout << "\nBusqueda lineal. Arreglo: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\nIngrese el elemento a buscar: ";
    cin >> x;
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << "Elemento encontrado en la posicion " << i << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) cout << "Elemento no encontrado.\n";
}

// 3. Piramide de numeros hasta 5 niveles
void piramideNumeros() {
    cout << "\nPiramide de numeros:\n";
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// 4. Contar del 1 al 100, pero detenerse en 50 usando break
void contarConBreak() {
    cout << "\nContar del 1 al 100, detenerse en 50:\n";
    for (int i = 1; i <= 100; i++) {
        if (i == 51) break;
        cout << i << " ";
    }
    cout << endl;
}

// 5. Mostrar funcionamiento de for por rango (C++11 en adelante)
void forPorRango() {
    cout << "\nFuncionamiento de for por rango:\n";
    int arreglo[] = {10, 20, 30, 40, 50};
    for (int valor : arreglo) {
        cout << valor << " ";
    }
    cout << endl;
}

int main() {
    patronAsteriscos();
    busquedaLineal();
    piramideNumeros();
    contarConBreak();
    forPorRango();
    return 0;
}
