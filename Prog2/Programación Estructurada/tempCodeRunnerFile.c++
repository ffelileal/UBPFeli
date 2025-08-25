// Funcion Recursiva para calcular los 5 primeros terminos de la serie de fibonacci.

#include <iostream>
using namespace std;

int fibonacci(int n) {
    // Caso Base:
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    // Caso Recursivo: Fibonacci de n es la suma de los 2 numeros previos de la serie.
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "---Este programa calcula el fibonacci de un nro ingresado---" << endl;
    cout << "Ingrese el numero de termino/posicion cuyo valor quiere conocer de la serie: " << endl;
    cin >> n;

    // Llama a la funcion recursiva
    int fib_num = fibonacci(n);

    cout << "El numero: " << fib_num << " se corresponde con el termino/posicion: " 
         << n << " de la serie" << endl;
    cout << "En la posicion: " << n << " de la serie, se encuentra el numero: " 
         << fib_num << endl;

    return 0;
}
