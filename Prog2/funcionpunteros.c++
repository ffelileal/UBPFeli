#include <iostream>
using namespace std;

int main() {
    int a = 10;   // Variable normal
    int *p;       // Se declara un puntero a int

    p = &a;       // Se almacena la dirección de 'a' en el puntero 'p'

    cout << "La variable a contiene el valor: " << a << endl;
    cout << "La direccion de memoria de la variable a (&a) es: " << &a << endl << endl;
    cout << "El valor de la variable puntero es: " << p << endl;
    cout << "Contenido de la direccion a la que apunta el puntero p (*p) es: " << *p << endl;

    return 0;
}
