#include <iostream>
using namespace std;

// --- 1. Caso base y recursivo (ejemplo simple) ---
void cuentaAtras(int n) {
    if (n == 0) { // Caso base
        cout << "¡Despegue!" << endl;
    } else {      // Caso recursivo
        cout << n << endl;
        cuentaAtras(n - 1);
    }
}

// --- 2. Suma de n primeros números enteros ---
int sumaEnteros(int n) {
    if (n == 1) return 1;                    // Caso base
    return n + sumaEnteros(n - 1);           // Caso recursivo
}

// --- 3. Potencia de un número ---
int potencia(int base, int exponente) {
    if (exponente == 0) return 1;            // Caso base
    return base * potencia(base, exponente-1); // Caso recursivo
}

// --- 4. Invertir número de 3 dígitos ---
int invertirNumero(int n, int invertido = 0) {
    if (n == 0) return invertido;            // Caso base
    return invertirNumero(n/10, invertido*10 + n%10); // Caso recursivo
}

// --- 5. Cuenta regresiva entre dos números ---
void cuentaRegresiva(int a, int b) {
    if (a < b) return;                       // Caso base
    cout << a << " ";
    cuentaRegresiva(a-1, b);                 // Caso recursivo
}

// --- 6. Suma de n primeros números pares ---
int sumaPares(int n) {
    if (n == 1) return 2;                    // Primer par
    return 2*n + sumaPares(n-1);             // Caso recursivo
}

int main() {
    int opcion;
    do {
        cout << "\n--- MENU DE FUNCIONES RECURSIVAS ---\n";
        cout << "1. Ver ejemplo de caso base y recursivo (cuenta atras)\n";
        cout << "2. Calcular suma de los n primeros enteros\n";
        cout << "3. Calcular potencia de un numero\n";
        cout << "4. Invertir un numero de 3 digitos\n";
        cout << "5. Cuenta regresiva entre dos numeros\n";
        cout << "6. Sumar los primeros n numeros pares\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                int n;
                cout << "Ingrese un numero: ";
                cin >> n;
                cuentaAtras(n);
                break;
            }
            case 2: {
                int n;
                cout << "Ingrese n: ";
                cin >> n;
                cout << "La suma es: " << sumaEnteros(n) << endl;
                break;
            }
            case 3: {
                int base, exp;
                cout << "Ingrese la base: ";
                cin >> base;
                cout << "Ingrese el exponente: ";
                cin >> exp;
                cout << "La potencia es: " << potencia(base, exp) << endl;
                break;
            }
            case 4: {
                int num;
                cout << "Ingrese un numero de 3 digitos: ";
                cin >> num;
                cout << "El numero invertido es: " << invertirNumero(num) << endl;
                break;
            }
            case 5: {
                int a, b;
                cout << "Ingrese el numero inicial: ";
                cin >> a;
                cout << "Ingrese el numero final: ";
                cin >> b;
                cout << "Cuenta regresiva: ";
                cuentaRegresiva(a, b);
                cout << endl;
                break;
            }
            case 6: {
                int n;
                cout << "Ingrese n: ";
                cin >> n;
                cout << "La suma de los primeros " << n << " pares es: " << sumaPares(n) << endl;
                break;
            }
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while(opcion != 0);

    return 0;
}
