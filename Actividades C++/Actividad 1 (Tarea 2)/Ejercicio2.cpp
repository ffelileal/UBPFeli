#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    int H = 0, M = 0; 
    int edad, maxEdad, minEdad;
    string genero;

    cout << "Que edad tiene usted? ";
    cin >> edad;

    if (edad >= 18) {
        maxEdad = edad;
        minEdad = edad;

        while (edad >= 18) {
            cout << "Que genero es usted? (Hombre/Mujer): ";
            cin >> genero;

            if (genero == "Hombre" || genero == "hombre" || genero == "H" || genero == "h") {
                H++;
                cout << "Felicidades, puede pasar" << endl;
            } else if (genero == "Mujer" || genero == "mujer" || genero == "M" || genero == "m") {
                M++;
                cout << "Felicidades, puede pasar" << endl;
            }

            if (edad > maxEdad) {
                maxEdad = edad;
            }
            if (edad < minEdad) {
                minEdad = edad;
            }

            system("cls");
            cout << "Que edad tiene usted? ";
            cin >> edad;
        }

        cout << "La persona de mayor edad tiene: " << maxEdad << " años." << endl;
        cout << "La persona de menor edad tiene: " << minEdad << " años." << endl;
        cout << "Cantidad de hombres: " << H << endl;
        cout << "Cantidad de mujeres: " << M << endl;
    } else {
        cout << "Lo sentimos, debe ser mayor de edad para participar." << endl;
    }

    return 0;
}