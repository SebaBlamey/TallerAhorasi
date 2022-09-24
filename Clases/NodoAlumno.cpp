
#include "NodoAlumno.h"

using namespace std;

NodoAlumno::NodoAlumno(Alumno* _alumno) {
    alumno = _alumno;
    siguiente = NULL;
}

Alumno* NodoAlumno::getAlumno() {
    return alumno;
}
/*void setAlumno(Alumno* _alumno) {
    alumno = _alumno;
}*/
NodoAlumno* NodoAlumno::getSiguiente() {
    return siguiente;
}
void NodoAlumno::setSiguiente(NodoAlumno* _siguiente) {
    siguiente = _siguiente;
}