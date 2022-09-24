#include "Clases\Alumno.h"
#include "Clases\ListasAlumno.h"
#include <iostream>
#include <string>


using namespace std;

void desplegarMenuPrinicipal();
bool check_number(string);

string opcion,nombre,apellido,ramo1,ramo2,ramo3,sala,carrera;
int edad,semestre,ram;
int main(int argc, char const *argsv[]) {
    Alumno* al = new Alumno("","",0,0);
    ListasAlumno* nuevalistaAlumno = new ListasAlumno();
    desplegarMenuPrinicipal();
    cout << "Ingrese una opcion-> ";
    cin >> opcion;
    if (check_number(opcion)) {
        int opcion_num = stoi(opcion);
        while (stoi(opcion) < 1 || stoi(opcion) > 7) {
            cout << "Ingrese una opcion valida-> ";
            cin >> opcion;
        }
        switch (opcion_num) {
            case 1:
                cout << "Ingrese el nombre del estudiante-> ";
                cin >> nombre;
                cout << "Ingrese el apellido del estudiante-> ";
                cin >> apellido;
                cout << "Ingrese la edad del estudiante-> ";
                cin >> edad;
                cout << "Ingrese el semestre del estudiante-> ";
                cin >> semestre;
                nuevalistaAlumno->agregarAlumno(new Alumno(nombre, apellido, edad, semestre));
                break;
            case 2:
                cout << "Ingrese el nombre del profesor-> ";
                cin >> nombre;
                cout << "Ingrese el apellido del profesor-> ";
                cin >> apellido;
                cout << "Ingrese la cantidad de ramos que el profesor va a realizar (Maximo 3): ";
                cin>> ram;
                while (ram < 0 || ram > 3) {
                    cout << "Ingrese una opcion valida-> ";
                    cin >> ram;
                }
                for(int i = 0; i< ram ; i++){
                    //cout << "Ingrese el ramo "<<;
                    //xd
                }
                if(ram >= 1){
                    cout<<"Ingrese el ramo 1: ";
                    cin >> ramo1;
                }else if(ram >=2){
                    cout<<"Ingrese el ramo 2: ";
                    cin >> ramo2;
                }else if(ram == 3){
                    cout<<"Ingrese el ramo 3: ";
                    cin >> ramo3;
                }
            default:
                break;
        }
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
