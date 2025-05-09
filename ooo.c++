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

// Funcion no parametrizada: Registrar jugadores
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

// Funcion no parametrizada: Mostrar jugadores
void mostrarJugadores() {
    cout << "\n=== Jugadores ===\n";
    for (int i = 0; i < cantidadJugadores; i++) {
        cout << jugadores[i].nombre << " | Saldo: $" << jugadores[i].saldo << endl;
    }
}

// Funcion no parametrizada: Registrar apuestas
void registrarApuestas() {
    cout << "\n=== Apuestas ===\n";
    for (int i = 0; i < cantidadJugadores; i++) {
        cout << jugadores[i].nombre << ", elige un numero del 0 al 9: ";
        cin >> jugadores[i].apuestaNumero;

        do {
            cout << "Monto a apostar ($): ";
            cin >> jugadores[i].apuestaMonto;
            if (jugadores[i].apuestaMonto <= 0) {
                cout << "El monto debe ser mayor que cero.\n";
            } else if (jugadores[i].apuestaMonto > jugadores[i].saldo) {
                cout << "No tienes saldo suficiente. Apostaras todo lo que tienes ($" << jugadores[i].saldo << ")\n";
                jugadores[i].apuestaMonto = jugadores[i].saldo;
            }
        } while (jugadores[i].apuestaMonto <= 0);
    }
}

// Funcion parametrizada: Realizar sorteo
int realizarSorteo() {
    int numeroGanador = rand() % 10;
    historialSorteos[sorteosRealizados++] = numeroGanador;
    cout << "\n El numero ganador es: " << numeroGanador << "\n";

    for (int i = 0; i < cantidadJugadores; i++) {
        if (jugadores[i].apuestaNumero == numeroGanador) {
            int premio = jugadores[i].apuestaMonto * 5;
            jugadores[i].saldo += premio;
            cout << " " << jugadores[i].nombre << " gano $" << premio << "!\n";
        } else {
            jugadores[i].saldo -= jugadores[i].apuestaMonto;
        }
    }

    return numeroGanador;
}

// Funcion parametrizada: Mostrar historial
void mostrarHistorial() {
    cout << "\n=== Historial de sorteos ===\n";
    for (int i = 0; i < sorteosRealizados; i++)
        cout << "Sorteo #" << (i + 1) << ": " << historialSorteos[i] << endl;
}

// Funcion no parametrizada: Verificar jugadores con saldo
bool jugadoresConSaldo() {
    for (int i = 0; i < cantidadJugadores; i++)
        if (jugadores[i].saldo > 0) return true;
    return false;
}

// Funcion de ordenamiento: Ordenar jugadores por saldo
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

// Funcion de busqueda: Buscar un jugador por nombre
int buscarJugadorPorNombre(const string &nombre) {
    for (int i = 0; i < cantidadJugadores; i++) {
        if (jugadores[i].nombre == nombre) {
            return i; // Retorna el indice del jugador
        }
    }
    return -1; // Si no se encuentra el jugador
}

// Funcion para reiniciar el juego
void reiniciarJuego() {
    cantidadJugadores = 0;
    sorteosRealizados = 0;
    for (int i = 0; i < MAX_JUGADORES; i++) {
        jugadores[i].saldo = 0;
    }
    for (int i = 0; i < MAX_SORTEOS; i++) {
        historialSorteos[i] = 0;
    }
    cout << "Juego reiniciado con exito!\n";
}

// Funcion para mostrar resumen final
void resumenFinal() {
    cout << "\n=== Resumen Final ===\n";
    Jugador ganador;
    ganador.saldo = -1;
    for (int i = 0; i < cantidadJugadores; i++) {
        if (jugadores[i].saldo > ganador.saldo) {
            ganador = jugadores[i];
        }
    }
    cout << "Jugador con mas saldo: " << ganador.nombre << " con $" << ganador.saldo << endl;
}

void menu() {
    cout << "\n=== Menu ===\n";
    cout << "1. Registrar jugadores\n";
    cout << "2. Mostrar jugadores\n";
    cout << "3. Registrar apuestas\n";
    cout << "4. Realizar sorteo\n";
    cout << "5. Mostrar historial\n";
    cout << "6. Buscar jugador por nombre\n";
    cout << "7. Reiniciar juego\n";
    cout << "8. Salir\n";
    cout << "Elige una opcion: ";
}

int main() {
    srand(time(0));
    int opcion;

    do {
        menu();
        cin >> opcion;

        switch(opcion) {
            case 1:
                registrarJugadores();
                break;
            case 2:
                mostrarJugadores();
                break;
            case 3:
                registrarApuestas();
                break;
            case 4:
                if (jugadoresConSaldo()) {
                    registrarApuestas();
                    realizarSorteo();
                    mostrarHistorial();
                } else {
                    cout << "No hay jugadores con saldo suficiente para continuar.\n";
                }
                break;
            case 5:
                mostrarHistorial();
                break;
            case 6:
                {
                    string nombreBuscar;
                    cout << "Ingresa el nombre de un jugador para buscar: ";
                    cin >> nombreBuscar;
                    int jugadorIndex = buscarJugadorPorNombre(nombreBuscar);
                    if (jugadorIndex != -1) {
                        cout << "Jugador " << nombreBuscar << " encontrado. Saldo: $" << jugadores[jugadorIndex].saldo << endl;
                    } else {
                        cout << "Jugador no encontrado." << endl;
                    }
                }
                break;
            case 7:
                reiniciarJuego();
                break;
            case 8:
                resumenFinal();
                cout << "Gracias por jugar! Fin del programa.\n";
                break;
            default:
                cout << "Opcion no valida. Intenta nuevamente.\n";
        }

    } while (opcion != 8);

    return 0;
}

