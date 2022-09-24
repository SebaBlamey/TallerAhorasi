#include "NodoProfesor.h"

using namespace std;

NodoProfesor :: NodoProfesor (Profesor* _profesor){
    profesor = _profesor;
    siguente = NULL;
}

Profesor* NodoProfesor::getProfesor(){
    return profesor;
}

//void setProfesor(Profesor* _profesor){
    //profesor = _profesor;
//}

NodoProfesor* NodoProfesor::getSiguente(){
    return siguente;
}

void NodoProfesor::setSiguente(NodoProfesor* _siguente){
    siguente = _siguente;
}