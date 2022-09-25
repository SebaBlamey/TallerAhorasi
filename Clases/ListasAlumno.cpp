#include "ListasAlumno.h"

#include <string>

using namespace std;

ListasAlumno::ListasAlumno() {
    primero = NULL;
    largo = 0;
}
void ListasAlumno::agregarAlumno(Alumno* _alumno) {
    NodoAlumno* nuevo = new NodoAlumno(_alumno);
    if (primero == NULL) {
        primero = nuevo;
    } else {
        NodoAlumno* aux = primero;
        while (aux->getSiguiente() != NULL) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
    largo++;
}
void ListasAlumno::eliminarAlumno(Alumno* _alumno) {
    NodoAlumno* aux = primero;
    NodoAlumno* anterior = NULL;
    while (aux != NULL) {
        if (aux->getAlumno()->getNombre() == _alumno->getNombre()) {
            if (anterior == NULL) {
                primero = aux->getSiguiente();
            } else {
                anterior->setSiguiente(aux->getSiguiente());
            }
            delete aux;
            largo--;
            break;
        }
        anterior = aux;
        aux = aux->getSiguiente();
    }
}
void ListasAlumno::imprimirLista() {
    NodoAlumno* aux = primero;

    while (aux != NULL) {
        string nombre = "Nombre: " + aux->getAlumno()->getNombre() + " Apelldio:" + aux->getAlumno()->getApellido() + " Edad:" + to_string(aux->getAlumno()->getEdad()) +
                        " Semestre:" + to_string(aux->getAlumno()->getSemestre());
        cout << nombre << endl;
        aux = aux->getSiguiente();
    }
}
int ListasAlumno::getLargo() {
    return largo;
}

Alumno* ListasAlumno::getAlumno(string _nombre) {
    NodoAlumno* aux = primero;
    while (aux != NULL) {
        if (aux->getAlumno()->getNombre() == _nombre) {
            return aux->getAlumno();
        }
        aux = aux->getSiguiente();
    }
    return NULL;
}