#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int N = 9;
int tablero[N][N];

// Declaracion de funciones
void inicializarTablero();
void imprimirTablero();
bool esSeguro(int fila, int col, int num);
bool resolverSudoku();
void vaciarCasillas(int dificultad);
bool esTableroCompleto();

// Funcion principal
int main() {
    srand(time(0));

    inicializarTablero();
    resolverSudoku();        // Genera Sudoku valido
    vaciarCasillas(40);      // Borra 40 casillas

    cout << "\n\t=== Sudoku Generado ===\n\n";
    imprimirTablero();

    // Iniciar timer
    auto inicio = high_resolution_clock::now();

    while (!esTableroCompleto()) {
        int fila, col, num;

        // Mostrar tiempo actual
        auto ahora = high_resolution_clock::now();
        auto duracion = duration_cast<seconds>(ahora - inicio);
        cout << "\nTiempo transcurrido: " << duracion.count() << " segundos.\n";

        cout << "\nIngresa fila (0-8), columna (0-8) y numero (1-9): ";
        cin >> fila >> col >> num;

        // Validar entrada
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nEntrada invalida. Debes ingresar numeros.\n";
            continue;
        }

        if (fila >= 0 && fila < N && col >= 0 && col < N && num >= 1 && num <= 9) {
            if (tablero[fila][col] == 0 && esSeguro(fila, col, num)) {
                tablero[fila][col] = num;
                cout << "\nTablero actualizado:\n";
                imprimirTablero();
            } else {
                cout << "\nMovimiento invalido. O ya hay un numero, o no es valido ahi.\n";
            }
        } else {
            cout << "\nFila, columna o numero fuera de rango. Intenta otra vez.\n";
        }
    }

    // Finalizar timer
    auto fin = high_resolution_clock::now();
    auto duracion_total = duration_cast<seconds>(fin - inicio);

    cout << "\nFelicidades, resolviste el Sudoku.\n";
    cout << "Tiempo total: " << duracion_total.count() << " segundos.\n";

    return 0;
}

// Inicializa el tablero en ceros
void inicializarTablero() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tablero[i][j] = 0;
        }
    }
}

// Imprime el tablero en consola
void imprimirTablero() {
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "---------------------\n";
        }
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            if (tablero[i][j] == 0)
                cout << ". ";
            else
                cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

// Verifica si un numero puede colocarse en fila/columna
bool esSeguro(int fila, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (tablero[fila][i] == num || tablero[i][col] == num)
            return false;
    }

    int inicioFila = fila - fila % 3;
    int inicioCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i + inicioFila][j + inicioCol] == num)
                return false;
        }
    }
    return true;
}

// Algoritmo para completar Sudoku
bool resolverSudoku() {
    for (int fila = 0; fila < N; fila++) {
        for (int col = 0; col < N; col++) {
            if (tablero[fila][col] == 0) {
                int numeros[N] = {1,2,3,4,5,6,7,8,9};

                // Mezclar los numeros
                for (int i = 0; i < N; i++) {
                    int j = rand() % N;
                    swap(numeros[i], numeros[j]);
                }

                for (int i = 0; i < N; i++) {
                    int num = numeros[i];
                    if (esSeguro(fila, col, num)) {
                        tablero[fila][col] = num;
                        if (resolverSudoku())
                            return true;
                        tablero[fila][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Vaciar casillas segun dificultad
void vaciarCasillas(int dificultad) {
    int vacias = dificultad;
    while (vacias > 0) {
        int fila = rand() % N;
        int col = rand() % N;
        if (tablero[fila][col] != 0) {
            tablero[fila][col] = 0;
            vacias--;
        }
    }
}

// Verificar si tablero esta completo
bool esTableroCompleto() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i][j] == 0)
                return false;
        }
    }
    return true;
}
