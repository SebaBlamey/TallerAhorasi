#include <iostream>
#include <string>

#include "Clases\Alumno.h"
#include "Clases\ListasAlumno.h"
#include "Clases\ListasProfesor.h"

using namespace std;

void desplegarMenuPrinicipal();
bool check_number(string);
void ingresar_estudiante(ListasAlumno*);
void ingresar_profesor(ListasProfesor*);

string opcion, nombre, apellido, ramo1, ramo2, ramo3, sala, carrera;
int edad, semestre, ram;
int main(int argc, char const* argsv[]) {
    ListasAlumno* nuevalistaAlumno = new ListasAlumno();
    ListasProfesor* nuevalistaProfesor = new ListasProfesor();
    desplegarMenuPrinicipal();
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
            default:
                cout << "Opcion ingresada no valida." << endl;
                break;
        }
        desplegarMenuPrinicipal();
        cout << "Ingrese una opcion-> ";
        cin >> opcion;
    }

    if(stoi(opcion) == 7){
        cout << "Saliendo del programa..." << endl;
    }

    return 0;
}

void desplegarMenuPrinicipal() {
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

void ingresar_estudiante(ListasAlumno* lista){
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
void ingresar_profesor(ListasProfesor* lista){
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
        switch(i){
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
