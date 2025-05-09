#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int FAMILIARES = 4;  // Número de personas en la familia
const int APUESTAS = 3;    // Número de apuestas por persona

// Estructura para representar a cada miembro de la familia
struct Familiar {
    string nombre;
    int dinero;
    int apuestas[APUESTAS];  // Apuestas realizadas
};

Familiar familia[FAMILIARES];

// Función para inicializar la familia con nombres y dinero
void inicializarFamilia() {
    familia[0] = {"Tía Rosa", 1000};
    familia[1] = {"Primo Pedro", 500};
    familia[2] = {"Abuelo Juan", 2000};
    familia[3] = {"Tú (Felipe)", 3000};
}

// Función para mostrar el estado actual de cada familiar
void mostrarEstadoFamilia() {
    cout << "\n=== Estado de la Familia Apostadora ===\n";
    for (int i = 0; i < FAMILIARES; i++) {
        cout << familia[i].nombre << " tiene $" << familia[i].dinero << " en su cuenta.\n";
    }
}

// Función para realizar apuestas aleatorias y modificar el dinero
void realizarApuestas() {
    srand(time(0));

    for (int i = 0; i < FAMILIARES; i++) {
        for (int j = 0; j < APUESTAS; j++) {
            int apuesta = rand() % 500 + 100;  // Apuesta entre $100 y $600
            familia[i].apuestas[j] = apuesta;
            familia[i].dinero -= apuesta;  // Descontamos la apuesta

            cout << familia[i].nombre << " apostó $" << apuesta << " en la apuesta " << (j + 1) << ".\n";
        }
    }
}

// Función para resolver las apuestas (aleatoriamente si ganan o pierden)
void resolverApuestas() {
    srand(time(0));

    for (int i = 0; i < FAMILIARES; i++) {
        for (int j = 0; j < APUESTAS; j++) {
            int resultado = rand() % 2;  // 0 = pierde, 1 = gana
            if (resultado == 1) {
                int ganancia = familia[i].apuestas[j] * 2;  // Doble de lo apostado
                familia[i].dinero += ganancia;
                cout << familia[i].nombre << " ganó $" << ganancia << " en la apuesta " << (j + 1) << "!\n";
            } else {
                cout << familia[i].nombre << " perdió la apuesta " << (j + 1) << ".\n";
            }
        }
    }
}

// Función para mostrar el resultado final de las apuestas
void mostrarResultadoFinal() {
    cout << "\n=== Resultado Final de la Familia ===\n";
    for (int i = 0; i < FAMILIARES; i++) {
        cout << familia[i].nombre << " tiene ahora $" << familia[i].dinero << ".\n";
    }

    // Evaluar quién es el más rico
    int maxDinero = 0;
    string ganador = "";
    for (int i = 0; i < FAMILIARES; i++) {
        if (familia[i].dinero > maxDinero) {
            maxDinero = familia[i].dinero;
            ganador = familia[i].nombre;
        }
    }

    cout << "\n¡El miembro de la familia más rico es " << ganador << " con $" << maxDinero << "!\n";
}

int main() {
    inicializarFamilia();
    
    cout << "🎰 Bienvenido al Simulador de Familia Apostadora 🎰\n";
    mostrarEstadoFamilia();

    // Realizar apuestas
    realizarApuestas();

    // Resolver las apuestas
    resolverApuestas();

    // Mostrar el resultado final
    mostrarResultadoFinal();

    return 0;
}
