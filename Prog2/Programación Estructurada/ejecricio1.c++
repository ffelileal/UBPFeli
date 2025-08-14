#include <iostream>
using namespace std;

void pausar() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

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
    cin.ignore();
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

// 6. Ejemplo de continue y break con enunciado y justificacion
void ejemploContinueBreak() {
    cout << "\nEjemplo de continue y break:\n";
    cout << "Recorrer los numeros del 1 al 20. Si el numero es multiplo de 3, mostrar 'Salteado' y continuar. Si es 15, detener el ciclo.\n";
    for (int i = 1; i <= 20; i++) {
        if (i % 3 == 0) {
            cout << "Salteado ";
            continue;
        }
        if (i == 15) {
            cout << "\nSe llego al 15, se detiene el ciclo.\n";
            break;
        }
        cout << i << " ";
    }
    cout << endl;
}

// 7. Funcion con parametros por valor y por referencia
void sumaYdoble(int a, int b, int& resultado, int& dobleA) {
    resultado = a + b;
    dobleA = a * 2;
}

void ejemploValorReferencia() {
    int x = 5, y = 7, suma, doble;
    sumaYdoble(x, y, suma, doble);
    cout << "\nSuma: " << suma << ", Doble de x: " << doble << endl;
}

// 8. Multiple choice de 5 preguntas
void multipleChoice() {
    int score = 0;
    char respuesta;

    cout << "\nMULTIPLE CHOICE:\n";

    cout << "1) Que imprime este codigo?\n";
    cout << "int x = 10;\nvoid f(int y) { y = y + 5; }\nf(x);\ncout << x << endl;\n";
    cout << "a) 10  b) 15  c) Error  d) 5\n";
    cout << "Tu respuesta: ";
    cin >> respuesta;
    if (respuesta == 'a' || respuesta == 'A') {
        cout << "Correcto!\n\n";
        score++;
    } else {
        cout << "Incorrecto. La respuesta correcta es a) 10\n\n";
    }

    cout << "2) Cual es la diferencia entre pasar por valor y por referencia?\n";
    cout << "a) Por valor se copia, por referencia se modifica el original\n";
    cout << "b) Por valor se modifica el original, por referencia se copia\n";
    cout << "c) No hay diferencia\n";
    cout << "d) Por valor solo para enteros\n";
    cout << "Tu respuesta: ";
    cin >> respuesta;
    if (respuesta == 'a' || respuesta == 'A') {
        cout << "Correcto!\n\n";
        score++;
    } else {
        cout << "Incorrecto. La respuesta correcta es a)\n\n";
    }

    cout << "3) Que hace este codigo?\n";
    cout << "void f(int& n) { n = n * 2; }\nint x = 3;\nf(x);\ncout << x << endl;\n";
    cout << "a) 3  b) 6  c) Error  d) 0\n";
    cout << "Tu respuesta: ";
    cin >> respuesta;
    if (respuesta == 'b' || respuesta == 'B') {
        cout << "Correcto!\n\n";
        score++;
    } else {
        cout << "Incorrecto. La respuesta correcta es b) 6\n\n";
    }

    cout << "4) Cual es la salida?\n";
    cout << "for (int i = 0; i < 5; i++) { if (i == 2) continue; cout << i << ' '; }\n";
    cout << "a) 0 1 2 3 4  b) 0 1 3 4  c) 0 1 3 4 5  d) 1 2 3 4\n";
    cout << "Tu respuesta: ";
    cin >> respuesta;
    if (respuesta == 'b' || respuesta == 'B') {
        cout << "Correcto!\n\n";
        score++;
    } else {
        cout << "Incorrecto. La respuesta correcta es b)\n\n";
    }

    cout << "5) Cual es el resultado?\n";
    cout << "void f(int a, int& b) { a++; b++; }\nint x = 1, y = 2;\nf(x, y);\ncout << x << ' ' << y << endl;\n";
    cout << "a) 2 3  b) 1 2  c) 1 3  d) 2 2\n";
    cout << "Tu respuesta: ";
    cin >> respuesta;
    if (respuesta == 'c' || respuesta == 'C') {
        cout << "Correcto!\n\n";
        score++;
    } else {
        cout << "Incorrecto. La respuesta correcta es c) 1 3\n\n";
    }

    cout << "Tu puntaje final es: " << score << " de 5\n";
    cin.ignore();
}

// 9. Código con errores y malas prácticas para corregir
void codigoConErrores() {
    cout << "\nCodigo con errores (corrige 10 cosas):\n";
    cout << "void suma(int a, int b, int& resultado)\n";
    cout << "    resultado = a + b\n";
    cout << "int main() {\n";
    cout << "    int x = 5, y = 10, res;\n";
    cout << "    suma(x, y, res)\n";
    cout << "    cout << \"La suma es: \" << res << endl\n";
    cout << "    return 0\n";
    cout << "}\n";
    cout << "Justificacion: Faltan llaves, punto y coma, prototipo, etc.\n";
    cout << "Codigo corregido:\n";
    cout << "void suma(int a, int b, int& resultado) { resultado = a + b; }\n";
    cout << "int main() { int x = 5, y = 10, res; suma(x, y, res); cout << \"La suma es: \" << res << endl; return 0; }\n";
}

int main() {
    patronAsteriscos();
    pausar();
    busquedaLineal();
    pausar();
    piramideNumeros();
    pausar();
    contarConBreak();
    pausar();
    forPorRango();
    pausar();
    ejemploContinueBreak();
    pausar();
    ejemploValorReferencia();
    pausar();
    multipleChoice();
    pausar();
    codigoConErrores();
    pausar();
    return 0;
}