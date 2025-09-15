#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Cancion {
    char titulo[50];
    char artista[50];
};

void agregarCancion(const char* archivo) {
    Cancion c;
    cout << "Ingrese el titulo de la cancion: ";
    cin.ignore();
    cin.getline(c.titulo, 50);
    cout << "Ingrese el artista: ";
    cin.getline(c.artista, 50);

    ofstream fout(archivo, ios::binary | ios::app);
    if (!fout) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    fout.write(reinterpret_cast<char*>(&c), sizeof(Cancion));
    fout.close();
    cout << "Cancion guardada!\n";
}

void mostrarCanciones(const char* archivo) {
    Cancion c;
    ifstream fin(archivo, ios::binary);
    if (!fin) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }
    cout << "\nLista de canciones favoritas:\n";
    while (fin.read(reinterpret_cast<char*>(&c), sizeof(Cancion))) {
        cout << "Titulo: " << c.titulo << " | Artista: " << c.artista << endl;
    }
    fin.close();
}

int main() {
    const char* archivo = "canciones.dat";
    int opcion;
    do {
        cout << "\n1. Agregar cancion\n2. Mostrar canciones\n0. Salir\nOpcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1: agregarCancion(archivo); break;
            case 2: mostrarCanciones(archivo); break;
            case 0: cout << "Adios!\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
    return 0;
}