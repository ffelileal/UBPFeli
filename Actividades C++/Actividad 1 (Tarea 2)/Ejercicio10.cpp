#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main() {
    float monto, total = 0;
    int clientesE = 0, clientesO = 0;
    string tipoPago;

    cout << "Ingrese el monto de la venta: ";
    cin >> monto;

    while (monto != 0) {
        cout << "Elija su tipo de pago: Efectivo, Obra Social: ";
        cin >> tipoPago;

        if (tipoPago == "e" || tipoPago == "E" || tipoPago == "Efectivo" || tipoPago == "efectivo") {
            clientesE++;
        } else if (tipoPago == "o" || tipoPago == "O" || tipoPago == "Obra social" || tipoPago == "obra social") {
            clientesO++;
        } else {
            cout << "Esta opción no se permite" << endl;
        }

        total += monto;

        system("cls"); 
        cout << "Ingrese el monto de la venta: ";
        cin >> monto;
    }

    cout << "Total recaudado: $" << total << endl;
    cout << "Clientes en efectivo: " << clientesE << endl;
    cout << "Clientes con obra social: " << clientesO << endl;

    return 0;
    
}
