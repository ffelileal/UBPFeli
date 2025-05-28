#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <map>

using namespace std;

const int MAX_ESTUDIANTES = 40;

// ===================== COLORES PARA CONSOLA =====================
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_CYAN    "\033[36m"

// ===================== ESTRUCTURAS =====================
struct Estudiante {
    string nombre;
    int legajo;
    float nota1;
    float nota2;
    float nota3;
    float asistencia;
    float promedio;
};

struct Usuario {
    string nombre;
    string contrasena;
    string rol; // "admin", "profesor", "alumno"
};

Estudiante estudiantes[MAX_ESTUDIANTES];
int cantidadEstudiantes = 0;

Usuario usuarios[] = {
    {"admin", "admin123", "admin"},
    {"profesor1", "prof123", "profesor"},
    {"alumno1", "alu123", "alumno"}
};
int cantidadUsuarios = 3;

map<string, string> mensajes;

// ===================== FUNCIONES AUXILIARES =====================

void pausar() {
    cout << COLOR_YELLOW << "Presione ENTER para continuar..." << COLOR_RESET;
    cin.ignore();
    cin.get();
}

void limpiarPantalla() {
    system("cls"); // En Linux/Mac usa "clear"
}

void imprimirEstudiante(const Estudiante& e) {
    cout << COLOR_CYAN << e.nombre << COLOR_RESET << " | Legajo: " << e.legajo
         << " | Promedio: " << fixed << setprecision(2) << e.promedio
         << " | Asistencia: " << e.asistencia << "%\n";
}

void mostrarErrorNoEncontrado() {
    cout << COLOR_RED << "\n>>> ERROR: Estudiante no encontrado. <<<\n" << COLOR_RESET;
}

int pedirOpcion(const string& mensaje) {
    int opcion;
    cout << mensaje;
    while (!(cin >> opcion)) {
        cout << COLOR_RED << "Entrada inválida. Intente de nuevo: " << COLOR_RESET;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return opcion;
}

bool hayAlumnos() {
    if (cantidadEstudiantes == 0) {
        cout << COLOR_YELLOW << "\n>>> No hay alumnos registrados. Por favor, registre al menos uno. <<<\n" << COLOR_RESET;
        pausar();
        return false;
    }
    return true;
}

// ===================== GUARDAR Y CARGAR ARCHIVO =====================

void guardarEnArchivo(const string& archivo) {
    ofstream fout(archivo);
    if (!fout) {
        cout << COLOR_RED << "Error al abrir archivo para guardar.\n" << COLOR_RESET;
        return;
    }
    fout << cantidadEstudiantes << endl;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        fout << "=== Estudiante ===" << endl;
        fout << estudiantes[i].nombre << ';'
             << estudiantes[i].legajo << ';'
             << estudiantes[i].nota1 << ';'
             << estudiantes[i].nota2 << ';'
             << estudiantes[i].nota3 << ';'
             << estudiantes[i].asistencia << ';'
             << estudiantes[i].promedio << '\n';
        fout << endl;
    }
    fout.close();
}

void cargarDesdeArchivo(const string& archivo) {
    ifstream fin(archivo);
    if (!fin) return;
    fin >> cantidadEstudiantes;
    fin.ignore();
    for (int i = 0; i < cantidadEstudiantes; i++) {
        string linea;
        getline(fin, linea); // Lee "=== Estudiante ==="
        getline(fin, linea); // Lee la línea con los datos
        if (linea.empty()) {
            i--;
            continue;
        }
        stringstream ss(linea);
        getline(ss, estudiantes[i].nombre, ';');
        string temp;
        getline(ss, temp, ';'); estudiantes[i].legajo = stoi(temp);
        getline(ss, temp, ';'); estudiantes[i].nota1 = stof(temp);
        getline(ss, temp, ';'); estudiantes[i].nota2 = stof(temp);
        getline(ss, temp, ';'); estudiantes[i].nota3 = stof(temp);
        getline(ss, temp, ';'); estudiantes[i].asistencia = stof(temp);
        getline(ss, temp, ';'); estudiantes[i].promedio = stof(temp);
        getline(fin, linea); // Lee línea en blanco
    }
    fin.close();
}

// ===================== GESTION ACADEMICA =====================

void registrarEstudiantes() {
    limpiarPantalla();
    cout << COLOR_CYAN << "=== Registro de estudiantes ===\n" << COLOR_RESET;
    int agregar = 0;
    int disponibles = MAX_ESTUDIANTES - cantidadEstudiantes;
    if (disponibles <= 0) {
        cout << COLOR_YELLOW << "No hay espacio para más estudiantes.\n" << COLOR_RESET;
        pausar();
        return;
    }
    do {
        cout << "Cuantos estudiantes desea agregar? (disponibles: " << disponibles << "): ";
        cin >> agregar;
        if (cin.fail() || agregar < 1 || agregar > disponibles) {
            cout << COLOR_RED << "Por favor, ingrese un número válido.\n" << COLOR_RESET;
            cin.clear();
            cin.ignore(10000, '\n');
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
        cout << "Nota 1: ";
        cin >> estudiantes[cantidadEstudiantes].nota1;
        cout << "Nota 2: ";
        cin >> estudiantes[cantidadEstudiantes].nota2;
        cout << "Nota 3: ";
        cin >> estudiantes[cantidadEstudiantes].nota3;
        do {
            cout << "% Asistencia: ";
            cin >> estudiantes[cantidadEstudiantes].asistencia;
            if (cin.fail() || estudiantes[cantidadEstudiantes].asistencia < 0 || estudiantes[cantidadEstudiantes].asistencia > 100) {
                cout << COLOR_RED << "Asistencia inválida. Debe estar entre 0 y 100.\n" << COLOR_RESET;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while (estudiantes[cantidadEstudiantes].asistencia < 0 || estudiantes[cantidadEstudiantes].asistencia > 100);

        estudiantes[cantidadEstudiantes].promedio =
            (estudiantes[cantidadEstudiantes].nota1 +
             estudiantes[cantidadEstudiantes].nota2 +
             estudiantes[cantidadEstudiantes].nota3) / 3.0;
        cantidadEstudiantes++;
        cin.ignore();
    }
    cout << COLOR_GREEN << "Estudiantes registrados correctamente.\n" << COLOR_RESET;
    pausar();
}

void mostrarEstudiantes() {
    limpiarPantalla();
    if (!hayAlumnos()) return;
    cout << COLOR_CYAN << "\n=== Lista de Estudiantes ===\n" << COLOR_RESET;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        imprimirEstudiante(estudiantes[i]);
    }
    pausar();
}

void mostrarAprobados() {
    limpiarPantalla();
    if (!hayAlumnos()) return;
    cout << COLOR_CYAN << "\n=== Estudiantes Aprobados ===\n" << COLOR_RESET;
    int contador = 0;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (estudiantes[i].promedio >= 6 && estudiantes[i].asistencia >= 75) {
            imprimirEstudiante(estudiantes[i]);
            contador++;
        }
    }
    if (contador == 0) cout << COLOR_YELLOW << "No hay alumnos aprobados.\n" << COLOR_RESET;
    pausar();
}

void mostrarReprobados() {
    limpiarPantalla();
    if (!hayAlumnos()) return;
    cout << COLOR_CYAN << "\n=== Estudiantes Reprobados ===\n" << COLOR_RESET;
    int contador = 0;
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (estudiantes[i].promedio < 6 || estudiantes[i].asistencia < 75) {
            imprimirEstudiante(estudiantes[i]);
            contador++;
        }
    }
    if (contador == 0) cout << COLOR_YELLOW << "No hay alumnos desaprobados.\n" << COLOR_RESET;
    pausar();
}

int buscarEstudiantePorLegajo(int legajo) {
    for (int i = 0; i < cantidadEstudiantes; i++) {
        if (estudiantes[i].legajo == legajo) return i;
    }
    return -1;
}

void eliminarEstudiante() {
    limpiarPantalla();
    if (!hayAlumnos()) return;
    int legajo;
    cout << "Ingrese legajo del estudiante a eliminar: ";
    cin >> legajo;
    int pos = buscarEstudiantePorLegajo(legajo);
    if (pos != -1) {
        char conf;
        cout << COLOR_YELLOW << "¿Está seguro que desea eliminar este estudiante? (s/n): " << COLOR_RESET;
        cin >> conf;
        if (conf != 's' && conf != 'S') {
            cout << "Operación cancelada.\n";
            pausar();
            return;
        }
        for (int i = pos; i < cantidadEstudiantes - 1; i++) {
            estudiantes[i] = estudiantes[i + 1];
        }
        cantidadEstudiantes--;
        cout << COLOR_GREEN << "\n*** Estudiante eliminado correctamente. ***\n" << COLOR_RESET;
    } else {
        mostrarErrorNoEncontrado();
    }
    pausar();
}

void modificarEstudiante() {
    limpiarPantalla();
    if (!hayAlumnos()) return;
    int legajo;
    cout << "Ingrese legajo del estudiante a modificar: ";
    cin >> legajo;
    int pos = buscarEstudiantePorLegajo(legajo);
    if (pos != -1) {
        cout << "Modificando estudiante: " << estudiantes[pos].nombre << endl;
        cin.ignore();
        cout << "Nuevo Nombre: ";
        getline(cin, estudiantes[pos].nombre);
        cout << "Nueva Nota 1: ";
        cin >> estudiantes[pos].nota1;
        cout << "Nueva Nota 2: ";
        cin >> estudiantes[pos].nota2;
        cout << "Nueva Nota 3: ";
        cin >> estudiantes[pos].nota3;
        do {
            cout << "Nueva Asistencia: ";
            cin >> estudiantes[pos].asistencia;
            if (cin.fail() || estudiantes[pos].asistencia < 0 || estudiantes[pos].asistencia > 100) {
                cout << COLOR_RED << "Asistencia inválida. Debe estar entre 0 y 100.\n" << COLOR_RESET;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while (estudiantes[pos].asistencia < 0 || estudiantes[pos].asistencia > 100);
        estudiantes[pos].promedio = (estudiantes[pos].nota1 + estudiantes[pos].nota2 + estudiantes[pos].nota3) / 3.0;
        cout << COLOR_GREEN << "\n*** Estudiante actualizado. ***\n" << COLOR_RESET;
    } else {
        mostrarErrorNoEncontrado();
    }
    pausar();
}

// ===================== DASHBOARD =====================

struct DashboardStats {
    int total;
    float promedioGeneral;
    float asistenciaGeneral;
    int aprobados;
    int desaprobados;
    float mejorPromedio;
    float peorPromedio;
    string mejorNombre;
    string peorNombre;
};

DashboardStats calcularDashboard() {
    DashboardStats stats;
    stats.total = cantidadEstudiantes;
    stats.promedioGeneral = 0;
    stats.asistenciaGeneral = 0;
    stats.aprobados = 0;
    stats.desaprobados = 0;
    stats.mejorPromedio = -1;
    stats.peorPromedio = 11;
    stats.mejorNombre = "-";
    stats.peorNombre = "-";

    float sumaPromedios = 0, sumaAsistencia = 0;

    for (int i = 0; i < cantidadEstudiantes; i++) {
        float prom = estudiantes[i].promedio;
        sumaPromedios += prom;
        sumaAsistencia += estudiantes[i].asistencia;

        if (prom >= 6.0 && estudiantes[i].asistencia >= 75) stats.aprobados++;
        else stats.desaprobados++;

        if (prom > stats.mejorPromedio) {
            stats.mejorPromedio = prom;
            stats.mejorNombre = estudiantes[i].nombre;
        }
        if (prom < stats.peorPromedio) {
            stats.peorPromedio = prom;
            stats.peorNombre = estudiantes[i].nombre;
        }
    }

    stats.promedioGeneral = stats.total > 0 ? sumaPromedios / stats.total : 0;
    stats.asistenciaGeneral = stats.total > 0 ? sumaAsistencia / stats.total : 0;

    return stats;
}

void mostrarDashboard() {
    limpiarPantalla();
    if (!hayAlumnos()) return;
    DashboardStats stats = calcularDashboard();
    cout << "\n=======================================\n";
    cout <<   "|         DASHBOARD ESTADISTICO        |\n";
    cout <<   "========================================\n";
    cout <<   "|Total de estudiantes:    " << setw(8) << stats.total << " |\n";
    cout <<   "| Promedio general:        " << setw(8) << fixed << setprecision(2) << stats.promedioGeneral << " |\n";
    cout <<   "| Asistencia promedio:     " << setw(7) << stats.asistenciaGeneral << "%" << " |\n";
    cout <<   "| Aprobados:               " << setw(8) << stats.aprobados << " |\n";
    cout <<   "| Desaprobados:            " << setw(8) << stats.desaprobados << " |\n";
    cout <<   "| Mejor promedio: " << stats.mejorNombre << " (" << stats.mejorPromedio << ") |\n";
    cout <<   "| Peor promedio:  " << stats.peorNombre << " (" << stats.peorPromedio << ") |\n";
    cout <<   "========================================\n";
    pausar();
}

// ===================== USUARIOS Y LOGIN =====================

Usuario* login() {
    string nombre, pass;
    cout << COLOR_CYAN << "===== LOGIN =====" << COLOR_RESET << endl;
    cout << "Usuario: "; cin >> nombre;
    cout << "Contraseña: "; cin >> pass;
    for (int i = 0; i < cantidadUsuarios; i++) {
        if (usuarios[i].nombre == nombre && usuarios[i].contrasena == pass)
            return &usuarios[i];
    }
    cout << COLOR_RED << "Login incorrecto.\n" << COLOR_RESET;
    return nullptr;
}

// ===================== MENUS =====================

void mostrarMenuPrincipal(const Usuario* usuarioActual) {
    limpiarPantalla();
    cout << COLOR_CYAN << "\n========================================\n";
    cout << "|    SISTEMA DE GESTION DE ESTUDIANTES   |\n";
    cout << "=========================================\n";
    cout << "| Usuario: " << usuarioActual->nombre << " | Rol: " << usuarioActual->rol << " |\n";
    cout << "=========================================\n" << COLOR_RESET;
    cout << "  1 - Gestion de estudiantes\n";
    cout << "  2 - Gestion de Notas\n";
    cout << "  3 - Reportes\n";
    if (usuarioActual->rol == "admin")
        cout << "  9 - Restablecer archivo de alumnos\n";
    cout << "  0 - Guardar y Salir\n";
    cout << "========================================\n";
}

void mostrarMenuestudiantes() {
    cout << "\n========================================\n";
    cout << "            GESTION DE ESTUDIANTES        \n";
    cout << "========================================\n";
    cout << "  1 - Registrar Estudiante\n";
    cout << "  2 - Buscar por Legajo\n";
    cout << "  3 - Modificar Estudiante\n";
    cout << "  4 - Eliminar Estudiante\n";
    cout << "  0 - Volver\n";
}

void mostrarMenuNotas() {
    cout << "====GESTION DE NOTAS====\n";
    cout << "  1 - Mostrar Notas\n";
    cout << "  0 - Volver\n";
}

void mostrarMenuReportes() {
    cout <<  "====GESTION DE NOTAS DE ALUMNOS====\n";
    cout << "  1 - Lista de Estudiantes\n";
    cout << "  2 - Aprobados\n";
    cout << "  3 - Reprobados\n";
    cout << "  4 - Dashboard Estadistico\n";
    cout << "  5 - Histograma de Promedios\n";
    cout << "  0 - Volver\n";
}

void mostrarHistogramaPromedios() {
    limpiarPantalla();
    if (!hayAlumnos()) return;
    cout << COLOR_CYAN << "\n=== Histograma de Promedios ===\n" << COLOR_RESET;
    int rangos[11] = {0}; // 0-1, 1-2, ..., 9-10, 10

    for (int i = 0; i < cantidadEstudiantes; i++) {
        int idx = int(estudiantes[i].promedio);
        if (idx < 0) idx = 0;
        if (idx > 10) idx = 10;
        rangos[idx]++;
    }

    for (int i = 0; i <= 10; i++) {
        cout << setw(2) << i << ": ";
        for (int j = 0; j < rangos[i]; j++) cout << "#";
        cout << " (" << rangos[i] << ")\n";
    }
    pausar();
}

// ===================== CARGA DE MENSAJES =====================

void cargarMensajes(const string& idioma) {
    mensajes.clear();
    if (idioma == "es") {
        mensajes["login"] = "===== LOGIN =====";
        mensajes["usuario"] = "Usuario: ";
        mensajes["contrasena"] = "Contraseña: ";
        mensajes["incorrecto"] = "Login incorrecto.";
        mensajes["salir"] = "Saliendo...";
        mensajes["presione"] = "Presione ENTER para continuar...";
        mensajes["menu_principal"] = "SISTEMA DE GESTION DE ESTUDIANTES";
        mensajes["gestion_estudiantes"] = "Gestion de estudiantes";
        mensajes["gestion_notas"] = "Gestion de Notas";
        mensajes["reportes"] = "Reportes";
        mensajes["restablecer"] = "Restablecer archivo de alumnos";
        mensajes["guardar_salir"] = "Guardar y Salir";
        mensajes["opcion"] = "Ingrese su opcion: ";
        mensajes["opcion_invalida"] = "Opcion invalida.";
        mensajes["gracias"] = "¡Gracias por usar el sistema! Hasta luego, ";
        // Agrega más mensajes según necesites
    } else {
        mensajes["login"] = "===== LOGIN =====";
        mensajes["usuario"] = "User: ";
        mensajes["contrasena"] = "Password: ";
        mensajes["incorrecto"] = "Login failed.";
        mensajes["salir"] = "Exiting...";
        mensajes["presione"] = "Press ENTER to continue...";
        mensajes["menu_principal"] = "STUDENT MANAGEMENT SYSTEM";
        mensajes["gestion_estudiantes"] = "Student Management";
        mensajes["gestion_notas"] = "Grades Management";
        mensajes["reportes"] = "Reports";
        mensajes["restablecer"] = "Reset student file";
        mensajes["guardar_salir"] = "Save and Exit";
        mensajes["opcion"] = "Enter your option: ";
        mensajes["opcion_invalida"] = "Invalid option.";
        mensajes["gracias"] = "Thank you for using the system! Goodbye, ";
        // Add more messages as needed
    }
}

// ===================== MAIN =====================

int main() {
    system("color 0A");
    string idioma;
    cout << "Seleccione idioma / Select language (es/en): ";
    cin >> idioma;
    cargarMensajes(idioma);

    cargarDesdeArchivo("estudiantes.txt");

    Usuario* usuarioActual = nullptr;
    do {
        usuarioActual = login();
    } while (!usuarioActual);

    int opcionPrincipal;
    do {
        mostrarMenuPrincipal(usuarioActual);
        opcionPrincipal = pedirOpcion("Ingrese su opcion: ");

        // Menú según rol
        if (usuarioActual->rol == "admin") {
            switch (opcionPrincipal) {
                case 1: { // estudiantes
                    int opcion;
                    do {
                        mostrarMenuestudiantes();
                        opcion = pedirOpcion("Opcion: ");
                        switch (opcion) {
                            case 1: registrarEstudiantes(); break;
                            case 2: {
                                limpiarPantalla();
                                if (!hayAlumnos()) break;
                                int legajo;
                                cout << "Ingrese legajo: ";
                                cin >> legajo;
                                int pos = buscarEstudiantePorLegajo(legajo);
                                if (pos != -1)
                                    imprimirEstudiante(estudiantes[pos]);
                                else
                                    mostrarErrorNoEncontrado();
                                pausar();
                                break;
                            }
                            case 3: modificarEstudiante(); break;
                            case 4: eliminarEstudiante(); break;
                        }
                    } while (opcion != 0);
                    break;
                }
                case 2: { // Notas
                    int opcion;
                    do {
                        mostrarMenuNotas();
                        opcion = pedirOpcion("Opcion: ");
                        switch (opcion) {
                            case 1: mostrarEstudiantes(); break;
                        }
                    } while (opcion != 0);
                    break;
                }
                case 3: { // Reportes
                    int opcion;
                    do {
                        mostrarMenuReportes();
                        opcion = pedirOpcion("Opcion: ");
                        switch (opcion) {
                            case 1: mostrarEstudiantes(); break;
                            case 2: mostrarAprobados(); break;
                            case 3: mostrarReprobados(); break;
                            case 4: mostrarDashboard(); break;
                            case 5: mostrarHistogramaPromedios(); break;
                        }
                    } while (opcion != 0);
                    break;
                }
                case 9: { // Restablecer archivo de alumnos
                    string codigo;
                    cout << "Ingrese el codigo de seguridad para restablecer: ";
                    cin >> codigo;
                    if (codigo != "UBP2025") {
                        cout << COLOR_RED << "Código incorrecto. Operación cancelada.\n" << COLOR_RESET;
                        pausar();
                        break;
                    }
                    cout << "Restableciendo archivo de alumnos...\n";
                    ofstream fout("estudiantes.txt");
                    if (!fout) {
                        cout << COLOR_RED << "Error al abrir el archivo para restablecer.\n" << COLOR_RESET;
                        pausar();
                        break;
                    }
                    fout.close();
                    cout << COLOR_GREEN << "Archivo restablecido.\n" << COLOR_RESET;
                    cantidadEstudiantes = 0;
                    pausar();
                    break;
                }
                case 0:
                    guardarEnArchivo("estudiantes.txt");
                    cout << COLOR_GREEN << "Datos guardados. Saliendo del programa...\n" << COLOR_RESET;
                    break;
                default:
                    cout << COLOR_RED << "Opcion invalida.\n" << COLOR_RESET;
                    pausar();
                    break;
            }
        } else if (usuarioActual->rol == "profesor") {
            switch (opcionPrincipal) {
                case 1: registrarEstudiantes(); break;
                case 2: mostrarEstudiantes(); break;
                case 3: mostrarAprobados(); break;
                case 4: mostrarReprobados(); break;
                case 0:
                    guardarEnArchivo("estudiantes.txt");
                    cout << COLOR_GREEN << "Datos guardados. Saliendo del programa...\n" << COLOR_RESET;
                    break;
                default:
                    cout << COLOR_RED << "Opcion invalida.\n" << COLOR_RESET;
                    pausar();
                    break;
            }
        } else if (usuarioActual->rol == "alumno") {
            switch (opcionPrincipal) {
                case 2: mostrarEstudiantes(); break;
                case 3: mostrarAprobados(); break;
                case 4: mostrarReprobados(); break;
                case 0:
                    cout << COLOR_CYAN << "Saliendo...\n" << COLOR_RESET;
                    break;
                default:
                    cout << COLOR_RED << "Opcion invalida.\n" << COLOR_RESET;
                    pausar();
                    break;
            }
        }
    } while (opcionPrincipal != 0);

    cout << COLOR_CYAN << "¡Gracias por usar el sistema! Hasta luego, " << usuarioActual->nombre << ".\n" << COLOR_RESET;
    return 0;
}