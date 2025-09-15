#include <iostream>
using namespace std;

int main() {
    cout << "3. Recorrer array con puntero:" << endl;
    int array[5] = {1, 2, 3, 4, 5};
    int *ptr_array = array;  // Puntero apunta al primer elemento

    for(int i = 0; i < 5; i++) {
        cout << "Elemento " << i << ": " << *(ptr_array + i) << endl;
    }
    cout << endl;

    return 0;
}