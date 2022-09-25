#include "Profesor.h"

Profesor::Profesor(string nombre, string apellido) : Usuario(nombre,apellido){
    
}

bool Profesor::agregarRamo(Ramo* r){
    if(listaRamos->getLargo() < 3){
        listaRamos->agregarRamo(r);
        return true;
    }else{
        return false;
    }
}

void Profesor::eliminarRamo(Ramo* r){
    listaRamos->eliminarRamo(r);
}

