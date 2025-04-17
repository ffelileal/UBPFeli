#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int main (){
    float i, j, k, l;
    cout << "Ingrese 4 valores: ";
    cin >> i >> j >> k >> l;
    if (j == 0 || l == 0) {
        cout << "No se puede dividir por cero." << endl;
    } else {
        if (i / j == k / l) {
            cout << "Los cocientes son iguales." << endl;
        }
    }
    return 0;
    
}
