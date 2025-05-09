#include <iostream>
#include <string>
using namespace std;

const int TAM = 5;

// Función para cargar los laboratorios y sus cantidades
void cargarDatos(string laboratorios[TAM], int cantidades[TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        cout << "Ingrese el nombre del laboratorio " << i + 1 << ": ";
        cin >> laboratorios[i];
        cout << "Ingrese la cantidad de remedios que provee: ";
        cin >> cantidades[i];
    }
}

// Función para calcular el total de remedios
int totalRemedios(int cantidades[TAM])
{
    int total = 0;
    for (int i = 0; i < TAM; i++)
    {
        total += cantidades[i];
    }
    return total;
}

// Función para ordenar de mayor a menor cantidades y nombres
void ordenarDatos(string laboratorios[TAM], int cantidades[TAM])
{
    for (int i = 0; i < TAM - 1; i++)
    {
        for (int j = i + 1; j < TAM; j++)
        {
            if (cantidades[i] < cantidades[j])
            {
                // Intercambiar cantidades
                int auxCant = cantidades[i];
                cantidades[i] = cantidades[j];
                cantidades[j] = auxCant;

                // Intercambiar nombres
                string auxLab = laboratorios[i];
                laboratorios[i] = laboratorios[j];
                laboratorios[j] = auxLab;
            }
        }
    }
}

// Función para mostrar los laboratorios y cantidades
void mostrarDatos(string laboratorios[TAM], int cantidades[TAM])
{
    cout << "\nLaboratorios y cantidad de remedios ordenados de mayor a menor:\n";
    for (int i = 0; i < TAM; i++)
    {
        cout << laboratorios[i] << ": " << cantidades[i] << " remedios" << endl;
    }
}

// Función para buscar un laboratorio
void buscarLaboratorio(string laboratorios[TAM], int cantidades[TAM])
{
    string nombreBuscado;
    cout << "\nIngrese el nombre del laboratorio a buscar: ";
    cin >> nombreBuscado;

    bool encontrado = false;
    for (int i = 0; i < TAM; i++)
    {
        if (laboratorios[i] == nombreBuscado)
        {
            encontrado = true;
            cout << "La farmacia trabaja con el laboratorio " << laboratorios[i] 
                 << " que provee " << cantidades[i] << " remedios." << endl;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "La farmacia NO trabaja con ese laboratorio." << endl;
    }
}

// Función principal
int main()
{
    string laboratorios[TAM];
    int cantidades[TAM];

    cargarDatos(laboratorios, cantidades);

    cout << "\nLa cantidad total de remedios en la farmacia es: " 
         << totalRemedios(cantidades) << endl;

    ordenarDatos(laboratorios, cantidades);

    mostrarDatos(laboratorios, cantidades);

    buscarLaboratorio(laboratorios, cantidades);

    return 0;
}