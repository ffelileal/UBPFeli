#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <limits>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring> // para strcpy y strcmp

using namespace std;

struct Card {
    char* face;     // puntero dinamico a la cara de la carta
    bool revealed;  // si actualmente esta revelada
    bool matched;   // si ya fue emparejada
    Card() : face(nullptr), revealed(false), matched(false) {}
};

// Genera nombres de cartas
vector<string> generarNombresCartas(int cantidad) {
    vector<string> nombres;
    char letra = 'A';
    for (int i = 0; i < cantidad; ++i) {
        string nombre = "";
        nombre += letra;
        if (cantidad > 26) {
            nombre += letra; // usa dos letras si hay mas de 26 pares
        }
        nombres.push_back(nombre);
        letra++;
        if (letra > 'Z') letra = 'A';
    }
    return nombres;
}

// Crea mazo dinamico
Card** createDeck(int filas, int columnas) {
    int N = filas * columnas;
    int pairs = N / 2;
    Card** deck = new Card*[N];

    vector<string> nombres = generarNombresCartas(pairs);
    int idx = 0;

    for (int p = 0; p < pairs; ++p) {
        for (int k = 0; k < 2; ++k) {
            deck[idx] = new Card();
            deck[idx]->face = new char[nombres[p].size() + 1];
            strcpy(deck[idx]->face, nombres[p].c_str());
            idx++;
        }
    }

    // Si el tablero es impar, agrega un comodin
    if (N % 2 != 0 && idx < N) {
        deck[idx] = new Card();
        deck[idx]->face = new char[3];
        strcpy(deck[idx]->face, "??");
        idx++;
    }

    // Mezclar (Fisher-Yates)
    for (int i = N - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Card* tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }

    return deck;
}

// Libera memoria
void deleteDeck(Card** deck, int N) {
    for (int i = 0; i < N; ++i) {
        if (deck[i]) {
            delete[] deck[i]->face;
            delete deck[i];
        }
    }
    delete[] deck;
}

// Muestra tablero
void printBoard(Card** deck, int filas, int columnas) {
    cout << "\n    ";
    for (int c = 0; c < columnas; ++c)
        cout << setw(4) << c;
    cout << "\n   " << string(4 * columnas, '-') << "\n";
    for (int f = 0; f < filas; ++f) {
        cout << setw(2) << f << " |";
        for (int c = 0; c < columnas; ++c) {
            int idx = f * columnas + c;
            if (deck[idx]->matched) {
                cout << "    ";
            } else if (deck[idx]->revealed) {
                cout << setw(3) << deck[idx]->face << " ";
            } else {
                cout << setw(3) << "*" << " ";
            }
        }
        cout << endl;
    }
}

// Devuelve true si todas estan emparejadas
bool todasEmparejadas(Card** deck, int N) {
    for (int i = 0; i < N; ++i)
        if (!deck[i]->matched)
            return false;
    return true;
}

// Menu dificultad
void elegirDificultad(int& filas, int& columnas) {
    int op;
    cout << "Elige dificultad:\n";
    cout << "1. Facil (2x2)\n";
    cout << "2. Media (4x4)\n";
    cout << "3. Dificil (6x6)\n";
    cout << "4. Personalizada\n";
    cout << "Opcion: ";
    cin >> op;
    switch (op) {
        case 1: filas = 2; columnas = 2; break;
        case 2: filas = 4; columnas = 4; break;
        case 3: filas = 6; columnas = 6; break;
        case 4:
            cout << "Filas: "; cin >> filas;
            cout << "Columnas: "; cin >> columnas;
            if (filas * columnas > 52) {
                cout << "Demasiadas cartas, se ajusta a 52.\n";
                filas = 4; columnas = 13;
            }
            break;
        default: filas = 4; columnas = 4; break;
    }
}

int main() {
    srand((unsigned)time(nullptr));
    cout << "===Juego de Memoria===\n\n";

    int filas, columnas;
    elegirDificultad(filas, columnas);
    int N = filas * columnas;

    Card** deck = createDeck(filas, columnas);
    int moves = 0;
    int matchesFound = 0;
    int totalPairs = N / 2;

    while (!todasEmparejadas(deck, N)) {
        printBoard(deck, filas, columnas);

        int f1, c1, f2, c2;
        int idx1, idx2;

        // Primera carta
        while (true) {
            cout << "\nElige la primera carta (fila columna): ";
            cin >> f1 >> c1;
            idx1 = f1 * columnas + c1;
            if (f1 < 0 || f1 >= filas || c1 < 0 || c1 >= columnas) {
                cout << "Fuera de rango.\n";
                continue;
            }
            if (deck[idx1]->matched || deck[idx1]->revealed) {
                cout << "Esa carta no esta disponible.\n";
                continue;
            }
            break;
        }
        deck[idx1]->revealed = true;
        printBoard(deck, filas, columnas);

        // Segunda carta
        while (true) {
            cout << "\nElige la segunda carta (fila columna): ";
            cin >> f2 >> c2;
            idx2 = f2 * columnas + c2;
            if (f2 < 0 || f2 >= filas || c2 < 0 || c2 >= columnas) {
                cout << "Fuera de rango.\n";
                continue;
            }
            if (idx2 == idx1) {
                cout << "No puedes elegir la misma carta.\n";
                continue;
            }
            if (deck[idx2]->matched || deck[idx2]->revealed) {
                cout << "Esa carta no esta disponible.\n";
                continue;
            }
            break;
        }
        deck[idx2]->revealed = true;
        printBoard(deck, filas, columnas);

        // Comparar
        if (strcmp(deck[idx1]->face, deck[idx2]->face) == 0) {
            cout << "\nEmparejaste! (" << deck[idx1]->face << ")\n";
            deck[idx1]->matched = true;
            deck[idx2]->matched = true;
            matchesFound++;
        } else {
            cout << "\nNo coinciden. Presiona Enter...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            deck[idx1]->revealed = false;
            deck[idx2]->revealed = false;
        }
        moves++;
    }

    cout << "\nGanaste! Encontraste todas las parejas.\n";
    cout << "Movimientos realizados: " << moves << "\n";

    deleteDeck(deck, N);
    return 0;
}
