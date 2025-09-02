#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Persona {
    char nombre[50];
    int edad;
};

int main() {
    // ===================== EJERCICIO 1 =====================
    {
        cout << "=== EJERCICIO 1: Escribir y leer un entero ===" << endl;
        int numero = 12345;
        ofstream out("entero.bin", ios::binary);
        out.write(reinterpret_cast<char*>(&numero), sizeof(numero));
        out.close();

        int leido;
        ifstream in("entero.bin", ios::binary);
        in.read(reinterpret_cast<char*>(&leido), sizeof(leido));
        in.close();

        cout << "Numero leido: " << leido << endl << endl;
    }

    // ===================== EJERCICIO 2 =====================
    {
        cout << "=== EJERCICIO 2: Escribir y leer un vector de enteros ===" << endl;
        int vec[5] = {10, 20, 30, 40, 50};
        ofstream out("vector.bin", ios::binary);
        out.write(reinterpret_cast<char*>(vec), sizeof(vec));
        out.close();

        int vecLeido[5];
        ifstream in("vector.bin", ios::binary);
        in.read(reinterpret_cast<char*>(vecLeido), sizeof(vecLeido));
        in.close();

        cout << "Vector leido: ";
        for (int i = 0; i < 5; i++) {
            cout << vecLeido[i] << " ";
        }
        cout << endl << endl;
    }

    // ===================== EJERCICIO 3 =====================
    {
        cout << "=== EJERCICIO 3: Escribir y leer una estructura ===" << endl;
        Persona p = {"Juan Perez", 25};
        ofstream out("persona.bin", ios::binary);
        out.write(reinterpret_cast<char*>(&p), sizeof(p));
        out.close();

        Persona pLeido;
        ifstream in("persona.bin", ios::binary);
        in.read(reinterpret_cast<char*>(&pLeido), sizeof(pLeido));
        in.close();

        cout << "Persona leida: " << pLeido.nombre << ", " << pLeido.edad << " anios" << endl << endl;
    }

    // ===================== EJERCICIO 4 =====================
    {
        cout << "=== EJERCICIO 4: Escribir y leer un entero en posicion dada ===" << endl;
        fstream archivo("posicion.bin", ios::in | ios::out | ios::binary | ios::trunc);
        int numero = 999;
        archivo.seekp(4); // posicionar el puntero de escritura en byte 4
        archivo.write(reinterpret_cast<char*>(&numero), sizeof(numero));
        archivo.flush();

        int leido;
        archivo.seekg(4); // posicionar el puntero de lectura en byte 4
        archivo.read(reinterpret_cast<char*>(&leido), sizeof(leido));
        archivo.close();

        cout << "Numero leido en byte 4: " << leido << endl << endl;
    }

    // ===================== EJERCICIO 5 =====================
    {
        cout << "=== EJERCICIO 5: Ejemplo propio ===" << endl;
        // Ejemplo: Escribir 3 enteros en distintas posiciones del archivo
        fstream archivo("ejemplo.bin", ios::in | ios::out | ios::binary | ios::trunc);
        int a = 111, b = 222, c = 333;

        // Escribir en posiciones no consecutivas
        archivo.seekp(0);
        archivo.write(reinterpret_cast<char*>(&a), sizeof(a));
        archivo.seekp(20);
        archivo.write(reinterpret_cast<char*>(&b), sizeof(b));
        archivo.seekp(40);
        archivo.write(reinterpret_cast<char*>(&c), sizeof(c));
        archivo.flush();

        // Leerlos
        int x, y, z;
        archivo.seekg(0);
        archivo.read(reinterpret_cast<char*>(&x), sizeof(x));
        archivo.seekg(20);
        archivo.read(reinterpret_cast<char*>(&y), sizeof(y));
        archivo.seekg(40);
        archivo.read(reinterpret_cast<char*>(&z), sizeof(z));
        archivo.close();

        cout << "Enteros leidos: " << x << ", " << y << ", " << z << endl;
    }

    return 0;
}
