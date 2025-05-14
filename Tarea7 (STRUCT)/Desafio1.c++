#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct DiaClima {
    int dia;
    float Tmax;
    float Tmin;
};

int main() {
    DiaClima clima[7];
    float sumaTmax = 0, sumaTmin = 0;

    for (int i = 0; i < 7; i++) {
        cout << "Ingrese el dia: ";
        cin >> clima[i].dia;
        cout << "Ingrese la temperatura maxima: ";
        cin >> clima[i].Tmax;
        cout << "Ingrese la temperatura minima: ";
        cin >> clima[i].Tmin;
        sumaTmax += clima[i].Tmax;
        sumaTmin += clima[i].Tmin;
    }

    float promedioTmax = sumaTmax / 7;

    cout << "Promedio de temperaturas maximas: " << promedioTmax << endl;

    return 0;
   
}
