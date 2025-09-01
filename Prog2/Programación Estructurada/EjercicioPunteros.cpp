#include <iostream>
using namespace std;

// Función para intercambiar valores usando punteros
void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    cout << "=== PARTE 1 ===" << endl;
    cout << endl;
    
    // Punto 1 del ejercicio
    cout << "1. Ejemplo con puntero:" << endl;
    float x = 55.4;
    int *p;  // Declaramos un puntero a entero
    // p = &x;  // ERROR: Esto daría error porque p es int* y x es float
    // Corrección:
    int y = 55;
    p = &y;  // Ahora p apunta a y (ambos son int)
    
    cout << "El valor de y es: " << y << endl;
    cout << "La direccion de y es: " << &y << endl;
    cout << "El valor apuntado por p es: " << *p << endl;
    cout << "La direccion almacenada en p es: " << p << endl;
    cout << endl;
    
    // Punto 3 del ejercicio
    cout << "3. Fragmento de codigo:" << endl;
    int a = 1, b = 3, *p1, *p2;
    p1 = &a;  // p1 apunta a a
    p2 = &b;  // p2 apunta a b
    *p1 = ++(*p2);  // Incrementa b en 1 y luego asigna ese valor a a
    
    cout << "Valor de a: " << a << endl;  // Ahora vale 4
    cout << "Valor de b: " << b << endl;  // Ahora vale 4
    cout << "Valor de p1: " << p1 << " (apunta a la direccion de a)" << endl;
    cout << "Valor de p2: " << p2 << " (apunta a la direccion de b)" << endl;
    cout << endl;
    
    cout << "=== PARTE 2 ===" << endl;
    cout << endl;
    
    // Punto 1
    cout << "1. Variable entera y puntero:" << endl;
    int numero = 10;
    int *ptr_numero = &numero;
    cout << "Valor de numero: " << *ptr_numero << endl;
    cout << "Direccion de numero: " << &numero << endl;
    cout << endl;
    
    // Punto 2
    cout << "2. Cambiar valor con puntero:" << endl;
    cout << "Valor original: " << numero << endl;
    *ptr_numero = 20;  // Cambiamos el valor usando el puntero
    cout << "Nuevo valor: " << numero << endl;
    cout << endl;
    
    // Punto 3
    cout << "3. Recorrer array con puntero:" << endl;
    int array[5] = {1, 2, 3, 4, 5};
    int *ptr_array = array;  // Puntero apunta al primer elemento
    
    for(int i = 0; i < 5; i++) {
        cout << "Elemento " << i << ": " << *(ptr_array + i) << endl;
    }
    cout << endl;
    
    // Punto 4
    cout << "4. Intercambiar valores con punteros:" << endl;
    int num1 = 5, num2 = 10;
    cout << "Antes del intercambio: num1 = " << num1 << ", num2 = " << num2 << endl;
    intercambiar(&num1, &num2);
    cout << "Despues del intercambio: num1 = " << num1 << ", num2 = " << num2 << endl;
    cout << endl;
    
    // Punto 5
    cout << "5. Puntero a char:" << endl;
    char letra = 'A';
    char *ptr_letra = &letra;
    cout << "Caracter: " << *ptr_letra << endl;
    cout << "Direccion: " << (void*)ptr_letra << endl;  // Cast para ver la direccion
    cout << endl;
    
    // Punto 6
    cout << "6. Recorrer array sumando al puntero:" << endl;
    int array2[5] = {10, 20, 30, 40, 50};
    int *ptr_array2 = array2;
    
    for(int i = 0; i < 5; i++) {
        cout << "Elemento " << i << ": " << *ptr_array2 << endl;
        ptr_array2++;  // Movemos el puntero al siguiente elemento
    }
    cout << endl;
    
    // Punto 7
    cout << "7. Distancia entre punteros:" << endl;
    int array3[10] = {0,1,2,3,4,5,6,7,8,9};
    int *ptr_inicio = &array3[2];  // Apunta al tercer elemento
    int *ptr_fin = &array3[7];     // Apunta al octavo elemento
    
    int distancia = ptr_fin - ptr_inicio;
    cout << "Distancia entre punteros: " << distancia << " elementos" << endl;
    cout << endl;
    
    // Punto 8
    cout << "8. Modificar cuarto elemento:" << endl;
    int array4[5] = {1, 2, 3, 4, 5};
    int *ptr_array4 = array4;  // Apunta al primer elemento
    
    cout << "Array original: ";
    for(int i = 0; i < 5; i++) {
        cout << array4[i] << " ";
    }
    cout << endl;
    
    *(ptr_array4 + 3) = 100;  // Modificamos el cuarto elemento (indice 3)
    
    cout << "Array modificado: ";
    for(int i = 0; i < 5; i++) {
        cout << array4[i] << " ";
    }
    cout << endl;
    
    return 0;
}