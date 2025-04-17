#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main() {
    cout << "Ingrese un numero aleatorio: ";
    int num;
    cin >> num;

    int sum;
    for (int  n = 1; n <= 10; n++)
    {
        sum = num + n;
        cout << "La suma de " << num << " + " << n << " es: " << sum << endl;
    }
    

}


