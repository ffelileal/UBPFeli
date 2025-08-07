#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

struct PalabraInfo {
    string texto;
    int longitud;
    bool contieneNumero;
};

int contarVocales(const string& str) {
    int count = 0;
    for (char c : str) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
    }
    return count;
}

bool contieneNumero(const string& palabra) {
    for (char c : palabra) {
        if (isdigit(c)) return true;
    }
    return false;
}

void ContadorLet() {
    string frase;
    cout << "\nIngrese una frase: ";
    getline(cin, frase);

    ofstream archivo("frase.txt");
    archivo << frase;
    archivo.close();

    int palabras = 0, vocales = 0, alfab = 0;
    string palabra, masLarga = "";
    PalabraInfo arreglo[100];
    int idx = 0;

    for (int i = 0; i <= frase.length(); i++) {
        char c = frase[i];
        if (isalpha(c)) alfab++;
        if (c != ' ' && c != '\0') {
            palabra += c;
        } else if (!palabra.empty()) {
            arreglo[idx].texto = palabra;
            arreglo[idx].longitud = palabra.length();
            arreglo[idx].contieneNumero = contieneNumero(palabra);
            if (palabra.length() > masLarga.length()) masLarga = palabra;
            idx++;
            palabras++;
            palabra = "";
        }
    }

    vocales = contarVocales(frase);

    cout << "\n--- Resultado del analisis ---\n";
    cout << "Palabras: " << palabras << endl;
    cout << "Vocales: " << vocales << endl;
    cout << "Caracteres alfabeticos: " << alfab << endl;
    cout << "Palabra mas larga: " << masLarga << endl;

    cout << "\nLista de palabras y detalles:\n";
    for (int i = 0; i < idx; i++) {
        cout << "- " << arreglo[i].texto
             << " (longitud: " << arreglo[i].longitud
             << ", contiene numeros: " << (arreglo[i].contieneNumero ? "Si" : "No") << ")\n";
    }
}

int main() {
    ContadorLet();
    return 0;
}
