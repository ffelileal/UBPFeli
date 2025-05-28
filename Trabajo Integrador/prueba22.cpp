#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

// ===================== CONSTANTES Y ESTRUCTURAS =====================

const int MAX_ESTUDIANTES = 40; // Máximo número de estudiantes permitidos

// Estructura que representa a un estudiante
struct Estudiante {
    string nombre;
    int legajo;
    float nota1, nota2, nota3;
    float asistencia;
    float promedio;
};

// ===================== VARIABLES GLOBALES =====================

Estudiante estudiantes[MAX_ESTUDIANTES]; // Arreglo de estudiantes
int cantidadEstudiantes = 0;             // Cantidad actual de estudiantes

// ===================== UTILIDADES =====================

/**
 * Pausa la ejecución hasta que el usuario presione ENTER.
 * Limpia el buffer de entrada para evitar problemas con cin.
 */
void pausar() {
    cout << "\nPresiona ENTER para continuar...";
    cin.ignore();
    cin.get();
}

/**
 * Limpia la pantalla de la consola.
 * Solo funciona en Windows.
 */
void limpiarPantalla() {
    system("cls");
}

/**
 * Imprime los datos de un estudiante en formato legible.
 * @param e Referencia constante al estudiante a imprimir.
 */
void imprimirEstudiante(const Estudiante& e) {
    cout << e.nombre << " | Legajo: " << e.legajo
         << " | Promedio: " << fixed << setprecision(2) << e.promedio
         << " | Asistencia: " << e.asistencia << "%\n";
}

/**
 * Pide una opción al usuario mostrando un mensaje.
 * @param mensaje Mensaje a mostrar.
 * @return La opción ingresada por el usuario.
 */
int pedirOpcion(const string& mensaje) {
    int opcion;
    cout << mensaje;
    cin >> opcion;
    return opcion;
}

/**
 * Verifica si hay alumnos registrados.
 * Si no hay, muestra un mensaje y pausa.
 * @return true si hay alumnos, false si no.
 */
bool hayAlumnos() {
    if (cantidadEstudiantes == 0) {
        cout << "\n>>> No hay alumnos registrados. Por favor, registre al menos uno. <<<\n";
        system("pause");
        return false;
    }
    return true;
}

/**
 * Carga las notas y la asistencia de un estudiante desde la entrada estándar.
 * Calcula el promedio automáticamente.
 * @param e Referencia al estudiante a cargar.
 */
void cargarNotasYAsistencia(Estudiante &e) {
    cout << "Nota 1: "; cin >> e.nota1;
    cout << "Nota 2: "; cin >> e.nota2;
    cout << "Nota 3: "; cin >> e.nota3;

    do {
        cout << "% Asistencia: ";
        cin >> e.asistencia;
        if (cin.fail() || e.asistencia < 0 || e.asistencia > 100) {
            cout << "Asistencia invalida. Debe estar entre 0 y 100.\n";
            cin.clear(); cin.ignore(10000, '\n');
        }
    } while (e.asistencia < 0 || e.asistencia > 100);

    e.promedio = (e.nota1 + e.nota2 + e.nota3) / 3.0;
}

// ===================== ARCHIVOS =====================

/**
 * Guarda todos los estudiantes en un archivo de texto.
 * @param archivo Nombre del archivo donde guardar.
 */
void guardarEnArchivo(const string& archivo) {
    ofstream fout(archivo);
    fout << cantidadEstudiantes << '\n';
    for (int i = 0; i < cantidadEstudiantes; i++) {
        fout << estudiantes[i].nombre << ';'
             << estudiantes[i].legajo << ';'
             << estudiantes[i].nota1 << ';'
             << estudiantes[i].nota2 << ';'
             << estudiantes[i].nota3 << ';'
             << estudiantes[i].asistencia << ';'
             << estudiantes[i].promedio << '\n';
    }
}

/**
 * Carga los estudiantes desde un archivo de texto.
 * @param archivo Nombre del archivo desde donde cargar.
 */
void cargarDesdeArchivo(const string& archivo) {
    ifstream fin(archivo);
    if (!fin) return;
    fin >> cantidadEstudiantes;
    fin.ignore();
    for (int i = 0; i < cantidadEstudiantes; i++) {
        string linea; getline(fin, linea);
        if (linea.empty()) { i--; continue; }
        stringstream ss(linea);
        getline(ss, estudiantes[i].nombre, ';');
        string temp;
        getline(ss, temp, ';'); estudiantes[i].legajo = stoi(temp);
        getline(ss, temp, ';'); estudiantes[i].nota1 = stof(temp);
        getline(ss, temp, ';'); estudiantes[i].nota2 = stof(temp);
        getline(ss, temp, ';'); estudiantes[i].nota3 = stof(temp);
        getline(ss, temp, ';'); estudiantes[i].asistencia = stof(temp);
        getline(ss, temp, ';'); estudiantes[i].promedio = stof(temp);
    }
}

// ===================== FUNCIONES PRINCIPALES =====================

/**
 * Permite registrar uno o varios estudiantes nuevos.
 * Valida la cantidad y los datos ingresados.
 */
void registrarEstudiantes() {
    cout << "=== Registro de estudiantes ===\n";
    int agregar = 0;
    int disponibles = MAX_ESTUDIANTES - cantidadEstudiantes;
    if (disponibles <= 0) {
        cout << "No hay espacio para mas estudiantes.\n";
        system("pause");
        return;
    }
    do {
        cout << "Cuantos estudiantes desea agregar? (max " << disponibles << "): ";
        cin >> agregar;
        if (cin.fail() || agregar < 1 || agregar > disponibles) {
            cout << "Numero invalido.\n";
            cin.clear(); cin.ignore(10000, '\n');
            agregar = 0;
        }
    } while (agregar < 1 || agregar > disponibles);

    cin.ignore();
    for (int i = 0; i < agregar; i++) {
        cout << "\nEstudiante #" << (cantidadEstudiantes + 1) << endl;
        cout << "Nombre: ";
        getline(cin, estudiantes[cantidadEstudiantes].nombre);
        cout << "Legajo: ";
        cin >> estudiantes[cantidadEstudiantes].legajo;
        cargarNotasYAsistencia(estudiantes[cantidadEstudiantes]);
        cantidadEstudiantes++;
        cin.ignore();
    }
}

/**
 * Muestra la lista de todos los estudiantes registrados.
 */
void mostrarEstudiantes() {
    if (!hayAlumnos()) return;
    cout << "\n=== Lista de Estudiantes ===\n";
    for (int i = 0; i < cantidadEstudiantes; i++) imprimirEstudiante(estudiantes[i]);
}

/**
 * Muestra solo los estudiantes aprobados (promedio >= 6 y asistencia >= 75).
 */
void mostrarAprobados() {
    if (!hayAlumnos()) return;
    cout << "\n=== Estudiantes Aprobados ===\n";
    int contador = 0;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (estudiantes[i].promedio >= 6 && estudiantes[i].asistencia >= 75) {
            imprimirEstudiante(estudiantes[i]);
            contador++;
        }
    }
    if (contador == 0) {
        cout << "No hay alumnos aprobados.\n";
    }
}

/**
 * Muestra solo los estudiantes reprobados (promedio < 6 o asistencia < 75).
 */
void mostrarDesaprobados() {
    if (!hayAlumnos()) return;
    cout << "\n=== Estudiantes Reprobados ===\n";
    int contador = 0;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (estudiantes[i].promedio < 6 || estudiantes[i].asistencia < 75) {
            imprimirEstudiante(estudiantes[i]);
            contador++;
        }
    }
    if (contador == 0) {
        cout << "No hay alumnos desaprobados.\n";
    }
}

/**
 * Busca un estudiante por su legajo.
 * @param legajo Legajo a buscar.
 * @return Posición en el arreglo o -1 si no se encuentra.
 */
int buscarEstudiantePorLegajo(int legajo) {
    for (int i = 0; i < cantidadEstudiantes; i++)
        if (estudiantes[i].legajo == legajo) return i;
    return -1;
}

/**
 * Permite modificar las notas y asistencia de un estudiante existente.
 * Busca por legajo.
 */
void modificarEstudiante() {
    if (!hayAlumnos()) return;
    int legajo;
    cout << "Ingrese legajo del estudiante a modificar: ";
    cin >> legajo;
    int pos = buscarEstudiantePorLegajo(legajo);
    if (pos != -1) {
        cout << "Modificando a: " << estudiantes[pos].nombre << " (Legajo " << estudiantes[pos].legajo << ")\n";
        cargarNotasYAsistencia(estudiantes[pos]);
        cout << "\n*** Estudiante actualizado. ***\n";
    } else {
        cout << ">>> ERROR: Estudiante no encontrado. <<<\n";
    }
}

/**
 * Elimina un estudiante por su legajo.
 * Si el legajo existe, elimina el estudiante y ajusta el arreglo.
 */
void eliminarEstudiante() {
    if (!hayAlumnos()) return;
    int legajo;
    cout << "Ingrese legajo del estudiante a eliminar: ";
    cin >> legajo;
    int pos = buscarEstudiantePorLegajo(legajo);
    if (pos != -1) {
        // Mover todos los estudiantes siguientes una posición hacia atrás
        for (int i = pos; i < cantidadEstudiantes - 1; i++) {
            estudiantes[i] = estudiantes[i + 1];
        }
        cantidadEstudiantes--;
        cout << "\n*** Estudiante eliminado correctamente. ***\n";
    } else {
        cout << ">>> ERROR: Estudiante no encontrado. <<<\n";
    }
}

// ===================== MENU PRINCIPAL =====================

/**
 * Muestra el menú principal y gestiona la interacción con el usuario.
 */
void menuPrincipal() {
        system("color 0A");
    int opcion;
    do {
        limpiarPantalla();
        cout << "===== SISTEMA DE GESTION DE ESTUDIANTES =====\n";
        cout << "1 - Registrar Estudiantes\n";
        cout << "2 - Mostrar Todos\n";
        cout << "3 - Mostrar Aprobados\n";
        cout << "4 - Mostrar desprobados\n";
        cout << "5 - Modificar Notas/Asistencia\n";
        cout << "6 - Eliminar Estudiante\n";
        cout << "0 - Guardar\n";
        cout << "9 - Salir\n";
        opcion = pedirOpcion("Opcion: ");

        switch (opcion) {
            case 1: registrarEstudiantes(); break;
            case 2: mostrarEstudiantes(); break;
            case 3: mostrarAprobados(); break;
            case 4: mostrarDesaprobados(); break;
            case 5: modificarEstudiante(); break;
            case 6: eliminarEstudiante(); break;
            case 0: guardarEnArchivo("estudiantes.txt"); cout << "Datos guardados.\n"; break;
            case 9: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }
        if (opcion != 0)system("pause");
    } while (opcion != 9);
}

// ===================== PROGRAMA PRINCIPAL =====================

/**
 * Punto de entrada del programa.
 * Carga los datos, muestra el menú y guarda los registros echos.
 */
int main() {
    cargarDesdeArchivo("estudiantes.txt");
    menuPrincipal();
    return 0;
}
