#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int main (){
    cout << "Oprima una tecla" << endl;
    getch(); 
    for (int num = 5; num >= 0; num--) {
        Sleep(1800);
        cout << num << endl;
    }
    cout << "Despegue exitoso" << endl;

    return 0;

}
