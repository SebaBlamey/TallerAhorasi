#include "ListasProfesor.h"

using namespace std;

ListasProfesor::ListasProfesor() {
    primero = NULL;
    largo = 0;
}

void ListasProfesor::agregarProfesor(Profesor* _profesor) {
    NodoProfesor* nuevo = new NodoProfesor(_profesor);
    if (primero == NULL) {
        primero = nuevo;
    } else {
        NodoProfesor* aux = primero;
        while (aux->getSiguente() != NULL) {
            aux = aux->getSiguente();
        }
        aux->setSiguente(nuevo);
    }
    largo++;
}
void ListasProfesor::eliminarProfesor(Profesor* _profesor) {
    NodoProfesor* aux = primero;
    NodoProfesor* anterior = NULL;
    while (aux != NULL) {
        if (aux->getProfesor()->getNombre() == _profesor->getNombre()) {
            if (anterior == NULL) {
                primero = aux->getSiguente();
            } else {
                anterior->setSiguente(aux->getSiguente());
            }
            delete aux;
            largo--;
            break;
        }
        anterior = aux;
        aux = aux->getSiguente();
    }
}
void ListasProfesor::imprimirLista() {
    NodoProfesor* aux = primero;
    while (aux != NULL) {
        cout << aux->getProfesor()->getNombre() << endl;
        aux = aux->getSiguente();
    }
}

int ListasProfesor::getLargo() {
    return largo;
}

Profesor* ListasProfesor::getProfesor(string _nombre) {
    NodoProfesor* aux = primero;
    while (aux != NULL) {
        if (aux->getProfesor()->getNombre() == _nombre) {
            return aux->getProfesor();
        }
        aux = aux->getSiguente();
    }
    return NULL;
}
