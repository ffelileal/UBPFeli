#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    float a, b, c, Resolvente;
    cout << "Ingrese el coeficiente a: ";
    cin >> a;
    cout << "Ingrese el coeficiente b: ";
    cin >> b;
    cout << "Ingrese el coeficiente c: ";
    cin >> c;
    
    Resolvente = b * b - 4 * a * c;
    
    if (Resolvente >= 0) {
        cout << "Las raíces son reales." << endl;
    } else {
        cout << "Las raíces no son reales." << endl;
    }
    
    return 0;
    
}
