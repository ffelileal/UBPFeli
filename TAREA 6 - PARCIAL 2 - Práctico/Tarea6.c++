#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int MAX_JUGADORES = 5;
const int MAX_SORTEOS = 10;

struct Jugador {
    string nombre;
    int saldo;
    int apuestaNumero;
    int apuestaMonto;
};

Jugador jugadores[MAX_JUGADORES];
int historialSorteos[MAX_SORTEOS];
int cantidadJugadores = 0;
int sorteosRealizados = 0;

// Función no parametrizada: Registrar jugadores
void registrarJugadores() {
    cout << "=== Registro de jugadores ===\n";
    cout << "Cuantos jugadores van a apostar? (max " << MAX_JUGADORES << "): ";
    cin >> cantidadJugadores;
    if (cantidadJugadores > MAX_JUGADORES) cantidadJugadores = MAX_JUGADORES;

    for (int i = 0; i < cantidadJugadores; i++) {
        cout << "Nombre del jugador #" << (i + 1) << ": ";
        cin >> jugadores[i].nombre;
        jugadores[i].saldo = 1500; // saldo inicial
    }
}

// Función no parametrizada: Mostrar jugadores
void mostrarJugadores() {
    cout << "\n=== Jugadores ===\n";
    for (int i = 0; i < cantidadJugadores; i++) {
        cout << jugadores[i].nombre << " | Saldo: $" << jugadores[i].saldo << endl;
    }
}

// Función no parametrizada: Registrar apuestas
void registrarApuestas() {
    cout << "\n=== Apuestas ===\n";
    for (int i = 0; i < cantidadJugadores; i++) {
        cout << jugadores[i].nombre << ", elige un numero del 0 al 9: ";
        cin >> jugadores[i].apuestaNumero;
        cout << "Monto a apostar ($): ";
        cin >> jugadores[i].apuestaMonto;

        if (jugadores[i].apuestaMonto > jugadores[i].saldo) {
            cout << "No tenés saldo suficiente. Apostás todo lo que tenés ($" << jugadores[i].saldo << ")\n";
            jugadores[i].apuestaMonto = jugadores[i].saldo;
        }
    }
}

// Función parametrizada: Realizar sorteo
int realizarSorteo() {
    int numeroGanador = rand() % 10;
    historialSorteos[sorteosRealizados++] = numeroGanador;
    cout << "\n El numero ganador es: " << numeroGanador << " 🎲\n";

    for (int i = 0; i < cantidadJugadores; i++) {
        if (jugadores[i].apuestaNumero == numeroGanador) {
            int premio = jugadores[i].apuestaMonto * 5;
            jugadores[i].saldo += premio;
            cout << " " << jugadores[i].nombre << " ganó $" << premio << "!\n";
        } else {
            jugadores[i].saldo -= jugadores[i].apuestaMonto;
        }
    }

    return numeroGanador;
}

// Función parametrizada: Mostrar historial
void mostrarHistorial() {
    cout << "\n=== Historial de sorteos ===\n";
    for (int i = 0; i < sorteosRealizados; i++)
        cout << "Sorteo #" << (i + 1) << ": " << historialSorteos[i] << endl;
}

// Función no parametrizada: Verificar jugadores con saldo
bool jugadoresConSaldo() {
    for (int i = 0; i < cantidadJugadores; i++)
        if (jugadores[i].saldo > 0) return true;
    return false;
}

// Función de ordenamiento: Ordenar jugadores por saldo
void ordenarJugadoresPorSaldo() {
    for (int i = 0; i < cantidadJugadores - 1; i++) {
        for (int j = 0; j < cantidadJugadores - 1 - i; j++) {
            if (jugadores[j].saldo < jugadores[j + 1].saldo) {
                Jugador temp = jugadores[j];
                jugadores[j] = jugadores[j + 1];
                jugadores[j + 1] = temp;
            }
        }
    }
}

// Función de búsqueda: Buscar un jugador por nombre
int buscarJugadorPorNombre(const string &nombre) {
    for (int i = 0; i < cantidadJugadores; i++) {
        if (jugadores[i].nombre == nombre) {
            return i; // Retorna el índice del jugador
        }
    }
    return -1; // Si no se encuentra el jugador
}

int main() {
    srand(time(0));
    registrarJugadores();

    // Ordenar jugadores por saldo al inicio
    ordenarJugadoresPorSaldo();
    mostrarJugadores();

    // Simular sorteos hasta que no haya jugadores con saldo o se llegue al máximo de sorteos
    while (jugadoresConSaldo() && sorteosRealizados < MAX_SORTEOS) {
        mostrarJugadores();
        registrarApuestas();
        realizarSorteo();
        mostrarHistorial();
        system("pause"); // esperar entre rondas
    }

    cout << "\nFin del sistema de apuestas\n";
    mostrarJugadores();
    mostrarHistorial();

    // Buscar un jugador por nombre (ejemplo de búsqueda)
    string nombreBuscar;
    cout << "Ingresa el nombre de un jugador para buscar: ";
    cin >> nombreBuscar;
    int jugadorIndex = buscarJugadorPorNombre(nombreBuscar);
    if (jugadorIndex != -1) {
        cout << "Jugador " << nombreBuscar << " encontrado. Saldo: $" << jugadores[jugadorIndex].saldo << endl;
    } else {
        cout << "Jugador no encontrado." << endl;
    }

    return 0;
}