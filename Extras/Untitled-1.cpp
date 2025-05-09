#include <iostream>
using namespace std;

// Función para ordenar el vector
void ordenar(int v[50], int n)
{
    for (int i = 0; i < n - 1; i++) // Recorremos desde el primer elemento hasta el anteúltimo
    {
        for (int j = i + 1; j < n; j++) // Comparamos el elemento actual con los siguientes
        {
            if (v[i] > v[j]) // Si el actual es mayor que el siguiente, los intercambiamos
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

// Función para mostrar el vector
void mostrar(int v[50], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Función principal
int main()
{
    int v[50], n;

    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    cout << "Ingrese los elementos del vector:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ordenar(v, n); // Llamamos a la función para ordenar el vector

    cout << "Vector ordenado:" << endl;
    mostrar(v, n); // Mostramos el vector ordenado

    return 0;
}
