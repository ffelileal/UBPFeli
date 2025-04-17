#include <iostream>
using namespace std;

int main() {
    int rating1, rating2, rating3;
    float horas1, horas2, horas3;
    float ingreso1, ingreso2, ingreso3, gasto1, gasto2, gasto3;
    float totalIngresos, totalGastos, resultado;

    cout << "Ingrese rating y horas del programa 1:" << endl;
    cin >> rating1 >> horas1;

    cout << "Ingrese rating y horas del programa 2:" << endl;
    cin >> rating2 >> horas2;

    cout << "Ingrese rating y horas del programa 3:" << endl;
    cin >> rating3 >> horas3;

    if (rating1 < 5) {
        cout << "El programa 1 no cumple con el rating mínimo." << endl;
    }
    if (rating2 < 5) {
        cout << "El programa 2 no cumple con el rating mínimo." << endl;
    }
    if (rating3 < 5) {
        cout << "El programa 3 no cumple con el rating mínimo." << endl;
    }

    ingreso1 = rating1 * 1.4 * horas1;
    ingreso2 = rating2 * 1.4 * horas2;
    ingreso3 = rating3 * 1.4 * horas3;

    gasto1 = horas1 * 0.75;
    gasto2 = horas2 * 0.75;
    gasto3 = horas3 * 0.75;

    totalIngresos = ingreso1 + ingreso2 + ingreso3;
    totalGastos = gasto1 + gasto2 + gasto3;
    resultado = totalIngresos - totalGastos;

    cout << "Ingresos totales: $" << totalIngresos << endl;
    cout << "Gastos totales: $" << totalGastos << endl;
    cout << "Resultado final: $" << resultado << endl;

    if (resultado > 0) {
        cout << "La empresa tiene ganancias." << endl;
    } else {
        cout << "La empresa tiene pérdidas." << endl;
    }

    return 0;
}