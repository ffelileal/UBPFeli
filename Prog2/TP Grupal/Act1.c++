#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

/*
  Battleship simple (un jugador vs IA).
  - Tablero cuadrado (8x8)
  - Barcos: tamanos {4,3,3,2,2}
  - Colocacion aleatoria y disparos secuenciales
  - Uso de punteros y new/delete
*/

const int BOARD_SIZE = 8;

struct Pos {
    int r, c;
};

struct Ship {
    int size;
    Pos* positions;    // arreglo dinamico de posiciones
    bool* hits;        // arreglo dinamico de impactos por segmento
    Ship(int s) : size(s) {
        positions = new Pos[s];
        hits = new bool[s];
        for (int i = 0; i < s; ++i) hits[i] = false;
    }
    ~Ship() {
        delete[] positions;
        delete[] hits;
    }
    bool isSunk() const {
        for (int i = 0; i < size; ++i) if (!hits[i]) return false;
        return true;
    }
};

char** createBoard(int n) {
    char** b = new char*[n];
    for (int i = 0; i < n; ++i) {
        b[i] = new char[n];
        for (int j = 0; j < n; ++j) b[i][j] = '~'; // agua
    }
    return b;
}

void deleteBoard(char** b, int n) {
    for (int i = 0; i < n; ++i) delete[] b[i];
    delete[] b;
}

void printBoard(char** b, int n, bool hideShips) {
    cout << "  ";
    for (int j = 0; j < n; ++j) cout << j << " ";
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << i << " ";
        for (int j = 0; j < n; ++j) {
            char ch = b[i][j];
            if (hideShips && ch == 'S') cout << "~ ";
            else cout << ch << " ";
        }
        cout << "\n";
    }
}

bool canPlace(char** board, int n, int r, int c, int len, bool horiz) {
    if (horiz) {
        if (c + len > n) return false;
        for (int j = c; j < c + len; ++j) if (board[r][j] != '~') return false;
    } else {
        if (r + len > n) return false;
        for (int i = r; i < r + len; ++i) if (board[i][c] != '~') return false;
    }
    return true;
}

void placeShipOnBoard(char** board, Ship* ship, int r, int c, bool horiz) {
    for (int i = 0; i < ship->size; ++i) {
        int rr = horiz ? r : r + i;
        int cc = horiz ? c + i : c;
        ship->positions[i].r = rr;
        ship->positions[i].c = cc;
        board[rr][cc] = 'S'; // marca de barco
    }
}

void randomPlaceShips(char** board, int n, Ship** ships, int shipCount) {
    for (int s = 0; s < shipCount; ++s) {
        bool placed = false;
        while (!placed) {
            int r = rand() % n;
            int c = rand() % n;
            bool horiz = (rand() % 2 == 0);
            if (canPlace(board, n, r, c, ships[s]->size, horiz)) {
                placeShipOnBoard(board, ships[s], r, c, horiz);
                placed = true;
            }
        }
    }
}

Ship** createFleet(const int sizes[], int count) {
    Ship** fleet = new Ship*[count]; // arreglo dinamico de punteros a Ship
    for (int i = 0; i < count; ++i) fleet[i] = new Ship(sizes[i]);
    return fleet;
}

void deleteFleet(Ship** fleet, int count) {
    for (int i = 0; i < count; ++i) delete fleet[i];
    delete[] fleet;
}

bool checkHitAndMark(Ship** fleet, int count, int r, int c) {
    for (int i = 0; i < count; ++i) {
        Ship* sh = fleet[i];
        for (int k = 0; k < sh->size; ++k) {
            if (sh->positions[k].r == r && sh->positions[k].c == c) {
                sh->hits[k] = true;
                return true;
            }
        }
    }
    return false;
}

bool allSunk(Ship** fleet, int count) {
    for (int i = 0; i < count; ++i) if (!fleet[i]->isSunk()) return false;
    return true;
}

int main() {
    srand((unsigned)time(nullptr));
    cout << "=== Battleship simple (C++ dinamico) ===\n\n";
    const int shipSizes[] = {4, 3, 3, 2, 2};
    const int shipCount = sizeof(shipSizes) / sizeof(shipSizes[0]);

    // Crear tableros
    char** playerBoard = createBoard(BOARD_SIZE);
    char** aiBoard = createBoard(BOARD_SIZE);
    char** playerViewOfAI = createBoard(BOARD_SIZE);

    // Crear flotas
    Ship** playerFleet = createFleet(shipSizes, shipCount);
    Ship** aiFleet = createFleet(shipSizes, shipCount);

    // Colocar barcos
    randomPlaceShips(playerBoard, BOARD_SIZE, playerFleet, shipCount);
    randomPlaceShips(aiBoard, BOARD_SIZE, aiFleet, shipCount);

    cout << "Se colocaron los barcos (aleatorio).\n";
    cout << "Tu tablero:\n";
    printBoard(playerBoard, BOARD_SIZE, false);

    // Bucle principal
    bool playerTurn = true;
    while (true) {
        if (playerTurn) {
            cout << "\nTu turno. Tablero enemigo (lo que sabes):\n";
            printBoard(playerViewOfAI, BOARD_SIZE, false);
            int r, c;
            cout << "Ingresa fila y columna (ej: 3 4): ";
            if (!(cin >> r >> c)) {
                cout << "Entrada invalida. Saliendo.\n";
                break;
            }
            if (r < 0 || r >= BOARD_SIZE || c < 0 || c >= BOARD_SIZE) {
                cout << "Fuera de rango.\n";
                continue;
            }
            if (playerViewOfAI[r][c] != '~') {
                cout << "Ya disparaste ahi.\n";
                continue;
            }
            if (aiBoard[r][c] == 'S') {
                cout << "Tocado!\n";
                playerViewOfAI[r][c] = 'X';
                aiBoard[r][c] = 'X';
                checkHitAndMark(aiFleet, shipCount, r, c);
                if (allSunk(aiFleet, shipCount)) {
                    cout << "Ganaste! Hundiste toda la flota enemiga.\n";
                    break;
                }
            } else {
                cout << "Agua.\n";
                playerViewOfAI[r][c] = 'o';
                aiBoard[r][c] = 'o';
                playerTurn = false;
            }
        } else {
            // Turno IA
            int r, c;
            do {
                r = rand() % BOARD_SIZE;
                c = rand() % BOARD_SIZE;
            } while (playerBoard[r][c] == 'o' || playerBoard[r][c] == 'X');

            cout << "\nTurno IA: dispara en (" << r << ", " << c << ")\n";
            if (playerBoard[r][c] == 'S') {
                cout << "La IA te toco!\n";
                playerBoard[r][c] = 'X';
                checkHitAndMark(playerFleet, shipCount, r, c);
                if (allSunk(playerFleet, shipCount)) {
                    cout << "Perdiste. La IA hundio toda tu flota.\n";
                    break;
                }
            } else {
                cout << "IA fallo.\n";
                playerBoard[r][c] = 'o';
                playerTurn = true;
            }
            cout << "Tu tablero ahora:\n";
            printBoard(playerBoard, BOARD_SIZE, false);
        }
    }

    // Liberar memoria
    deleteBoard(playerBoard, BOARD_SIZE);
    deleteBoard(aiBoard, BOARD_SIZE);
    deleteBoard(playerViewOfAI, BOARD_SIZE);

    deleteFleet(playerFleet, shipCount);
    deleteFleet(aiFleet, shipCount);

    cout << "Memoria liberada. Gracias por jugar.\n";
    return 0;
}
