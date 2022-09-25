#include <iostream>
#include <string>

#include "Clases\Alumno.h"
#include "Clases\ListasAlumno.h"
#include "Clases\ListasProfesor.h"
#include "Clases\ListaRamos.h"

using namespace std;

void desplegar_menu_prinicipal();
bool check_number(string);
void ingresar_estudiante(ListasAlumno*);
void consultar_estudiante(ListasAlumno*);
void ingresar_profesor(ListasProfesor*);
void consultar_profesor(ListasProfesor*);
void ingresar_ramo(ListaRamos*);
void consultar_ramo(ListaRamos*);
// void ingresar_ramos(ListasRamo*);

string opcion, nombre, apellido, ramo1, ramo2, ramo3, sala, carrera;
int edad, semestre, ram;
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
    cout << "Ingrese el nombre del estudiante-> ";
    cin >> nombre;
    cout << "Ingrese el apellido del estudiante-> ";
    cin >> apellido;
    cout << "Ingrese la edad del estudiante-> ";
    cin >> edad;
    cout << "Ingrese el semestre del estudiante-> ";
    cin >> semestre;
    lista->agregarAlumno(new Alumno(nombre, apellido, edad, semestre));
}
void ingresar_profesor(ListasProfesor* lista) {
    string ramito;
    cout << "Ingrese el nombre del profesor-> ";
    cin >> nombre;
    cout << "Ingrese el apellido del profesor-> ";
    cin >> apellido;
    cout << "Ingrese la cantidad de ramos que el profesor va a realizar (Maximo 3): ";
    cin >> ram;
    while (ram < 0 || ram > 3) {
        cout << "Ingrese una opcion valida-> ";
        cin >> ram;
    }
    for (int i = 0; i < ram; i++) {
        cout << "Ingrese el ramo " << to_string(ram) << "-> ";
        cin >> ramito;
        switch (i) {
            case 0:
                ramo1 = ramito;
                break;
            case 1:
                ramo2 = ramito;
                break;
            case 2:
                ramo3 = ramito;
                break;
        }
    }
    lista->agregarProfesor(new Profesor(nombre, apellido));
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
    cout << "Nombre: " << alumno->getNombre() << endl;
    cout << "Apellido: " << alumno->getApellido() << endl;
    cout << "Edad: " << alumno->getEdad() << endl;
    cout << "Semestre: " << alumno->getSemestre() << endl;
}

void consultar_profesor(ListasProfesor* lista) {
    cout << "Ingrese el nombre del profesor-> ";
    cin >> nombre;
    Profesor* profesor = lista->getProfesor(nombre);
    while (profesor == NULL) {
        cout << "Ingrese un nombre valido-> ";
        cin >> nombre;
        profesor = lista->getProfesor(nombre);
    }
    cout << "Nombre: " << profesor->getNombre() << endl;
    cout << "Apellido: " << profesor->getApellido() << endl;
    cout << "Ramos que dicta:";
    /*for(int i = 0; i < listaProfesor->getListaRamos->getSize; i++){
        Ramo* ramo = profesor->getRamoI;
        cout << ramo->getNombre;
    }*/
}
void ingresar_ramo(ListaRamos* lista) {
    cout << "Ingrese el nombre del ramo-> ";
    cin >> nombre;
    cout << "Ingrese la carrera del ramo-> ";
    cin >> carrera;
    cout << "Ingrese la sala ramo-> ";
    cin >> sala;
    lista->agregarRamo(new Ramo(nombre, carrera, sala));
}
void consultar_ramo(ListaRamos* listaRamo){
    cout << "Consultar Ramo" << endl;
    cout << "Ingrese el nombre del ramo que busca: ";
    string nombreAUX;
    cin >> nombreAUX;
    Ramo* r = listaRamo->buscarRamo(nombreAUX);
    while(r == NULL){
        cout << "Ramo no encontrado, Ingrese un nombre valido" << endl;
        cin >> nombreAUX;
        r = listaRamo->buscarRamo(nombreAUX);
    }
    cout << "Ramo nombre: "+r->getNombre() << " ,Carrera: "<< r->getCarrera() << ", Sala: " << r->getSala();
};