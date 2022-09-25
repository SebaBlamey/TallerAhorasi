#include <iostream>
#include <string>

#include "Clases\Alumno.h"
#include "Clases\ListaRamos.h"
#include "Clases\ListasAlumno.h"
#include "Clases\ListasProfesor.h"

using namespace std;

int menu_secundario();
void desplegar_menu_prinicipal();
bool check_number(string);
void ingresar_estudiante(ListasAlumno*);
void consultar_estudiante(ListasAlumno*);
void ingresar_profesor(ListasProfesor*);
void consultar_profesor(ListasProfesor*);
void ingresar_ramo(ListaRamos*);
void consultar_ramo(ListaRamos*);

string opcion, nombre, apellido, ramo1, ramo2, ramo3, sala, carrera;
int edad, semestre, ram, op;
int main(int argc, char const* argsv[]) {
    ListasAlumno* nuevalistaAlumno = new ListasAlumno();
    ListasProfesor* nuevalistaProfesor = new ListasProfesor();
    ListaRamos* nuevalistaRamo = new ListaRamos();
    desplegar_menu_prinicipal();
    cout << "Ingrese una opcion-> ";
    cin >> opcion;
    while (stoi(opcion) != 7) {
        switch (stoi(opcion)) {
            case 1:
                ingresar_estudiante(nuevalistaAlumno);
                break;
            case 2:
                ingresar_profesor(nuevalistaProfesor);
                break;
            case 3:
                ingresar_ramo(nuevalistaRamo);
                break;
            case 4:
                consultar_estudiante(nuevalistaAlumno);
            case 5:
                consultar_profesor(nuevalistaProfesor);
            default:
                cout << "Opcion ingresada no valida." << endl;
                break;
        }
        desplegar_menu_prinicipal();
        cout << "Ingrese una opcion-> ";
        cin >> opcion;
    }

    if (stoi(opcion) == 7) {
        cout << "Saliendo del programa..." << endl;
    }

    return 0;
}

int menu_secundario() {
    cout << "-----------------------------" << endl;
    cout << "Menu Secundario" << endl;
    cout << "-----------------------------" << endl;
    cout << "1. Modificar ." << endl;
    cout << "2. Eliminar." << endl;
    cout << "-----------------------------" << endl;
    cout << "Ingrese una opcion-> ";
    cin >> op;
    while ((op > 2) || (op < 1)) {
        cout << "Ingrese una opcion correcta: ";
        cin >> op;
    }
    return op;
}

void desplegar_menu_prinicipal() {
    cout << "-----------------------------" << endl;
    cout << "Menu Principal" << endl;
    cout << "-----------------------------" << endl;
    cout << "1. Ingresar estudiante." << endl;
    cout << "2. Ingresar profesor." << endl;
    cout << "3. Ingresar ramo." << endl;
    cout << "4. Consultar por alumno." << endl;
    cout << "5. Consultar por profesor." << endl;
    cout << "6. Consultar por ramo." << endl;
    cout << "7. Salir." << endl;
    cout << "-----------------------------" << endl;
}

bool check_number(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

void ingresar_estudiante(ListasAlumno* lista) {
    string ramito;
    cout << "Ingrese el nombre del estudiante-> ";
    cin >> nombre;
    Alumno* al = lista->getAlumno(nombre);
    if(al != NULL) {
        cout << "El estudiante ya existe." << endl;
        return;
    }
    cout << "Ingrese el apellido del estudiante-> ";
    cin >> apellido;
    cout << "Ingrese la edad del estudiante-> ";
    cin >> edad;
    cout << "Ingrese el semestre del estudiante-> ";
    cin >> semestre;
    ListaRamos* listilla = new ListaRamos();
    cout << "Ingrese la cantidad de ramos que el profesor va a realizar (Maximo 5): ";
    cin >> ram;
    while (ram <= 0 || ram > 5) {
        cout << "Ingrese una opcion valida-> ";
        cin >> ram;
    }
    for (int i = 0; i < ram; i++) {
        cout << "Ingrese el ramo " << to_string(ram) << "-> ";
        cin >> ramito;
        listilla->agregarRamo(new Ramo(ramito, "ICCI", "28"));
    }
    lista->agregarAlumno(new Alumno(nombre, apellido, edad, semestre, listilla));
}
void ingresar_profesor(ListasProfesor* lista) {
    string ramito;
    cout << "Ingrese el nombre del profesor-> ";
    cin >> nombre;
    Profesor* pro = lista->getProfesor(nombre);
    if(pro != NULL) {
        cout << "El profesor ya existe." << endl;
        return;
    }
    cout << "Ingrese el apellido del profesor-> ";
    cin >> apellido;
    ListaRamos* listilla = new ListaRamos();
    cout << "Ingrese la cantidad de ramos que el profesor va a realizar (Maximo 3): ";
    cin >> ram;
    while (ram <= 0 || ram > 5) {
        cout << "Ingrese una opcion valida-> ";
        cin >> ram;
    }
    for (int i = 0; i < ram; i++) {
        cout << "Ingrese el ramo " << to_string(i + 1) << "-> ";
        cin >> ramito;
        listilla->agregarRamo(new Ramo(ramito, "ICCI", "28"));
    }
    lista->agregarProfesor(new Profesor(nombre, apellido, listilla));
}
void consultar_estudiante(ListasAlumno* lista) {
    cout << "Ingrese el nombre del estudiante-> ";
    cin >> nombre;
    Alumno* alumno = lista->getAlumno(nombre);
    while (alumno == NULL) {
        cout << "Ingrese un nombre valido-> ";
        cin >> nombre;
        alumno = lista->getAlumno(nombre);
    }
    cout << "-----------------------------" << endl;
    cout << "Los datos del alumno" << endl;
    cout << "-----------------------------" << endl;
    cout << "Nombre: " << alumno->getNombre() << endl;
    cout << "Apellido: " << alumno->getApellido() << endl;
    cout << "Edad: " << alumno->getEdad() << endl;
    cout << "Semestre: " << alumno->getSemestre() << endl;
    cout << "Ramos: " << endl;
    alumno->getRamos();
    cout << "-----------------------------" << endl;
    int op = menu_secundario();
    if (op == 1) {
        string ramito;
        cout << "Ingrese el nombre nuevo del estudiante-> ";
        cin >> nombre;
        alumno->setNombre(nombre);
        cout << "Ingrese el apellido del estudiante-> ";
        cin >> apellido;
        alumno->setApellido(apellido);
        cout << "Ingrese la edad del estudiante-> ";
        cin >> edad;
        alumno->setEdad(edad);
        cout << "Ingrese el semestre del estudiante-> ";
        cin >> semestre;
        alumno->setSemestre(semestre);
        ListaRamos* listilla = new ListaRamos();
        cout << "Ingrese la cantidad de ramos que el profesor va a realizar (Maximo 5): ";
        cin >> ram;
        while (ram <= 0 || ram > 5) {
            cout << "Ingrese una opcion valida-> ";
            cin >> ram;
        }
        for (int i = 0; i < ram; i++) {
            cout << "Ingrese el ramo " << to_string(ram) << "-> ";
            cin >> ramito;
            listilla->agregarRamo(new Ramo(ramito, "ICCI", "28"));
        }
        alumno->setRamos(listilla);
        cout << "Datos cambiados con exito..." << endl;

    } else {
        string op2;
        cout << "Esta seguro que desea eliminar el estudiante? (S/N)-> ";
        cin >> op2;
        while (op2 != "S" && op2 != "N") {
            cout << "Ingrese una opcion valida (S/N)-> ";
            cin >> op2;
        }
        if (op2 == "S") {
            lista->eliminarAlumno(alumno);
            cout << "Estudiante eliminado con exito..." << endl;
        } else {
            cout << "El alumno no ha sido eliminado..." << endl;
        }
    }
}

void consultar_profesor(ListasProfesor* lista) {
    int op = menu_secundario();
    cout << "Ingrese el nombre del profesor-> ";
    cin >> nombre;
    Profesor* profesor = lista->getProfesor(nombre);
    while (profesor == NULL) {
        cout << "Ingrese un nombre valido-> ";
        cin >> nombre;
        profesor = lista->getProfesor(nombre);
    }
    cout << "-----------------------------" << endl;
    cout << "Los datos del profesor" << endl;
    cout << "-----------------------------" << endl;
    cout << "Nombre: " << profesor->getNombre() << endl;
    cout << "Apellido: " << profesor->getApellido() << endl;
    cout << "Ramos:" << endl;
    profesor->getRamos();
    cout << "-----------------------------" << endl;
    if (op == 1) {
        string ramito;
        cout << "Ingrese el nombre nuevo del profesor-> ";
        cin >> nombre;
        profesor->setNombre(nombre);
        cout << "Ingrese el apellido nuevo del profesor-> ";
        cin >> apellido;
        profesor->setApellido(apellido);
        ListaRamos* listilla = new ListaRamos();
        cout << "Ingrese la cantidad nueva de ramos que el profesor va a realizar (Maximo 3): ";
        cin >> ram;
        while (ram <= 0 || ram > 5) {
            cout << "Ingrese una opcion valida-> ";
            cin >> ram;
        }
        for (int i = 0; i < ram; i++) {
            cout << "Ingrese el ramo " << to_string(i + 1) << "-> ";
            cin >> ramito;
            listilla->agregarRamo(new Ramo(ramito, "ICCI", "28"));
        }
        profesor->setRamos(listilla);
        cout << "Datos cambiados con exito..." << endl;
    } else {
        string op2;
        cout << "Esta seguro que desea eliminar el profesor? (S/N)-> ";
        cin >> op2;
        while (op2 != "S" && op2 != "N") {
            cout << "Ingrese una opcion valida (S/N)-> ";
            cin >> op2;
        }
        if (op2 == "S") {
            lista->eliminarProfesor(profesor);
            cout << "Profesor eliminado con exito..." << endl;
        } else {
            cout << "El profesor no ha sido eliminado..." << endl;
        }
    }
}
void ingresar_ramo(ListaRamos* lista) {
    cout << "Ingrese el nombre del ramo-> ";
    cin >> nombre;
    Ramo* ra = lista->buscarRamo(nombre);
    if(ra != NULL) {
        cout << "El Ramo ya existe." << endl;
        return;
    }
    cout << "Ingrese la carrera del ramo-> ";
    cin >> carrera;
    cout << "Ingrese la sala ramo-> ";
    cin >> sala;
    lista->agregarRamo(new Ramo(nombre, carrera, sala));
}
void consultar_ramo(ListaRamos* listaRamo) {
    cout << "Consultar Ramo" << endl;
    int op = menu_secundario();
    cout << "Ingrese el nombre del ramo que busca: ";
    string nombreAUX;
    cin >> nombreAUX;
    Ramo* r = listaRamo->buscarRamo(nombreAUX);
    while (r == NULL) {
        cout << "Ramo no encontrado, Ingrese un nombre valido" << endl;
        cin >> nombreAUX;
        r = listaRamo->buscarRamo(nombreAUX);
    }
    cout << "-----------------------------" << endl;
    cout << "Los datos del ramo" << endl;
    cout << "-----------------------------" << endl;
    cout << "Nombre: " << r->getNombre() << endl;
    cout << "Carrera: " << r->getCarrera() << endl;
    cout << "Ramos:" << r->getSala() << endl;
    cout << "-----------------------------" << endl;
    if (op == 1) {
        cout << "Ingrese el nombre del ramo-> ";
        cin >> nombre;
        r->setNombre(nombre);
        cout << "Ingrese la carrera del ramo-> ";
        cin >> carrera;
        r->setCarrera(carrera);
        cout << "Ingrese la sala ramo-> ";
        cin >> sala;
        r->setSala(sala);
    } else {
        string op2;
        cout << "Esta seguro que desea eliminar el ramo? (S/N)-> ";
        cin >> op2;
        while (op2 != "S" && op2 != "N") {
            cout << "Ingrese una opcion valida (S/N)-> ";
            cin >> op2;
        }
        if (op2 == "S") {
            listaRamo->eliminarRamo(r);
            cout << "Ramo eliminado con exito..." << endl;
        } else {
            cout << "El ramo no ha sido eliminado..." << endl;
        }
    }
};