#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

const int MAX_ESTUDIANTES = 40;

struct Estudiante {
    string nombre;
    int legajo;
    float nota1, nota2, nota3;
    float asistencia;
    float promedio;
};

Estudiante estudiantes[MAX_ESTUDIANTES];
int cantidadEstudiantes = 0;

void pausar() {
    cout << "\nPresiona ENTER para continuar...";
    cin.ignore();
    cin.get();
}

void limpiarPantalla() {
    system("cls");
}

void imprimirEstudiante(const Estudiante& e) {
    cout << e.nombre << " | Legajo: " << e.legajo
         << " | Promedio: " << fixed << setprecision(2) << e.promedio
         << " | Asistencia: " << e.asistencia << "%\n";
}

int pedirOpcion(const string& mensaje) {
    int opcion;
    cout << mensaje;
    cin >> opcion;
    return opcion;
}

bool hayAlumnos() {
    if (cantidadEstudiantes == 0) {
        cout << "\n>>> No hay alumnos registrados. Por favor, registre al menos uno. <<<\n";
        system("pause");
        return false;
    }
    return true;
}

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

void guardarEnArchivo(const string& archivo) {
    ofstream fout(archivo); 
    if (!fout) {
        cerr << "Error al abrir el archivo para guardar.\n";
        return;
    }
    fout << left << setw(20) << "Nombre"
         << setw(10) << "Legajo"
         << setw(8) << "Nota1"
         << setw(8) << "Nota2"
         << setw(8) << "Nota3"
         << setw(12) << "Asistencia"
         << setw(10) << "Promedio" << '\n';
    fout << string(76, '-') << '\n';  
    for (int i = 0; i < cantidadEstudiantes; i++) {
        fout << left << setw(20) << estudiantes[i].nombre
             << setw(10) << estudiantes[i].legajo
             << setw(8) << estudiantes[i].nota1
             << setw(8) << estudiantes[i].nota2
             << setw(8) << estudiantes[i].nota3
             << setw(12) << estudiantes[i].asistencia
             << setw(10) << estudiantes[i].promedio << '\n';
    }
    fout.close(); 
    cout << "\nArchivo guardado correctamente en '" << archivo << "'.\n";
}

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

void mostrarEstudiantes() {
    if (!hayAlumnos()) return;
    cout << "\n=== Lista de Estudiantes ===\n";
    for (int i = 0; i < cantidadEstudiantes; i++) imprimirEstudiante(estudiantes[i]);
}

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

int buscarEstudiantePorLegajo(int legajo) {
    for (int i = 0; i < cantidadEstudiantes; i++)
        if (estudiantes[i].legajo == legajo) return i;
    return -1;
}

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

void eliminarEstudiante() {
    if (!hayAlumnos()) return;
    int legajo;
    cout << "Ingrese legajo del estudiante a eliminar: ";
    cin >> legajo;
    int pos = buscarEstudiantePorLegajo(legajo);
    if (pos != -1) {
        for (int i = pos; i < cantidadEstudiantes - 1; i++) {
            estudiantes[i] = estudiantes[i + 1];
        }
        cantidadEstudiantes--;
        cout << "\n*** Estudiante eliminado correctamente. ***\n";
    } else {
        cout << ">>> ERROR: Estudiante no encontrado. <<<\n";
    }
}

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
        cout << "0 - Guardar en archivo\n";
        cout << "9 - Salir del programa\n";
        opcion = pedirOpcion("Opcion: ");

        switch (opcion) {
            case 1: registrarEstudiantes(); break;
            case 2: mostrarEstudiantes(); break;
            case 3: mostrarAprobados(); break;
            case 4: mostrarDesaprobados(); break;
            case 5: modificarEstudiante(); break;
            case 6: eliminarEstudiante(); break;
            case 0:guardarEnArchivo("estudiantes.txt");
                cout << "Datos guardados correctamente.\n";
                pausar();
                break;
            case 9: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }
        if (opcion != 0)system("pause");
    } while (opcion != 9);
}

int main() {
    cargarDesdeArchivo("estudiantes.txt");
    menuPrincipal();
    return 0;
}