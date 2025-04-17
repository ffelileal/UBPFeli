#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int main (){
    int num1, num2, aux;
    cout << "Ingrese dos números: " << endl;
    cin >> num1 >> num2;
    
    if (num1 > num2) {
        aux = num1;
        num1 = num2;
        num2 = aux;
    }
    
    for (int i = num1; i <= num2; i++) {
        if (i % 2 != 0) {
            cout << i << endl;
            Sleep(1900);
        }
    }
    
    return 0;

}


