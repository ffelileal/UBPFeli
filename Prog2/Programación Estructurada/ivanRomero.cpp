#include <iostream>

using namespace std;

// ej 1

void patronAsteriscos() {

	int x = 0;

	int y = 0;

	while (x < 5) {

		while (y < 4) {

			cout << "*";

			y++;

		};

		cout << "*" << endl;

		y = 0;

		x++;

	}

}



// ej 2

void busquedaLineal() {

	int matriz[5] = {34, 22, 17, 3, 5};

	int objetoBusqueda;

	bool encontroValor = false;

	cout << "Ingrese un numero para buscarlo en la matriz" << endl;

	cin >> objetoBusqueda;



	for (int i = 0; i < 5; i++)

	{

		if (matriz[i] == objetoBusqueda) {

			encontroValor = true;

		}

	}

	if (encontroValor) {

		cout << "El valor ";

		cout << objetoBusqueda;

		cout << " Se encuentra en la matriz";

	}

	else {

		cout << "El valor ";

		cout << objetoBusqueda;

		cout << " No se encuentra en la matriz";

	}

}

// ej 4

void contadorBreak() {



	for (int i = 1; i >= 1; i++)

	{

		cout << i << endl;

		if (i == 50) {

			break;

		}



	}



}

// ej 5

void forPorRango() {



	int matriz[5] = { 34, 22, 17, 3, 5 };



	cout << "Valores de la Matriz" << endl;

	for (int i : matriz) {

		cout << i << endl;

	}

}

// ej 6



void continueBreak() {

//Realizar un código en el cual sea un contador del uno al 10, cuando el valor del iterador sea 2 no lo tiene que imprimir y cuando sea 7 tiene que cortar el bucle

	for (int i = 0; i <= 10; i++)

	{

		if (i == 2) {

			continue;

		}

		else if (i == 7) {

			break;

		}



		cout << i << endl;

	}



}


//ejercicio 8
void enunciadoMultipleChoice() {



	string preguntas[5] = {

		"Que es una variable en C++?",

		"Para que sirve 'cout' en C++?",

		"que hace la instruccion break dentro de un bucle en C++?",

		"Que efecto tiene la instruccion continue dentro de un bucle en C++?",

		"Cual de estas es una manera correcta de declarar una variable entera llamada 'edad'?"

	};



	string respuestas[5][4] = {

		{	"A) Una funcion.",

			"B) Un valor fijo.",

			"C) Un espacio para guardar un valor.",

			"D) Un operador matematico."
		},



		{	"A) Para recibir datos del usuario.",

			"B) Para imprimir texto o valores en la pantalla.",

			"C) Para declarar variables.",

			"D) Para realizar operaciones matematicas."
		},

		{	"A) Pausa el programa por un momento.",

			"B) Salta a la siguiente iteracion del bucle.",

			"C) Finaliza inmediatamente el bucle actual.",

			"D) Reinicia el bucle desde el principio."
		},

		{	"A) Termina completamente el programa.",

			"B) Salta el resto del codigo en la iteracion actual y continC:a con la siguiente.",

			"C) Repite la iteracion actual.",

			"D) Sale del bucle inmediatamente."
		},

		{	"A) int edad;",

			"B) edad int;",

			"C) variable edad;",

			"D) int:edad;"
		}

	};

	string respuestasCorrectas[5] = { "C","B","C","B","A" };

	string respuestaActual;

	for (int i = 0; i < 5; i++)

	{

		cout << preguntas[i] << endl;

		for (int x = 0; x <= 3; x++)

		{

			cout << respuestas[i][x] << endl;

		}

		cin >> respuestaActual;

		if (respuestaActual == respuestasCorrectas[i]) {

			cout << "La respuesta es correcta." << endl;

		} else {

			cout << "La respuesta es incorrecta." << endl;



		}



	}







}






//ejercicio 7


/*
Desarrolle un programa el cual sume dos numeros por medio de una funcion*/


void sumar(int primerValor, int segundoValor, int& respuesta) {
    respuesta = primerValor + segundoValor;
}

int ejercicio7() {
    int num1, num2, resultado;

    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    
    sumar(num1, num2, resultado);

    cout << "La suma es: " << resultado << endl;

    return 0;
}






/*ejercicio 9*/

//Corregir el codigo de este programa, el cual sirve para comparar dos enteros y mostrar cual es el mayor

void comparar(int a int b) {
    if a > b
        cout << "a es mayor que b" << endl;
    else 
    cout << "b es mayor que a" << endl
}

int llamarFuncionComparar() {
    int x = 10, y = 20

    comparar(x y)

    return 0
}
    

// Codigo corregido para comparar dos enteros y mostrar cual es el mayor
void comparar(int a, int b) {
    if (a > b) {
        cout << "a es mayor que b" << endl;
    } else {
        cout << "b es mayor que a" << endl;
    }
}

int llamarFuncionComparar() {
    int x = 10, y = 20;
    comparar(x, y);
    return 0;
}


int main() {

	cout << "Menu de opciones" << std::endl;

	llamarFuncionComparar();

	return 0;



}