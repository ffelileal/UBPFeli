#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


using namespace std;

int main() {
    cout << "Ingrese un numero aleatorio: ";
    int num;
    cin >> num;

    int sum;
    for (int nro = 1; nro <= 10; nro++)
    {
       
    Sleep(1500);

    cout << num << " x " << nro << " = " << num * nro << endl;
    }
    
}