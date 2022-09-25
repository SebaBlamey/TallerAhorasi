#include "NodoRamo.h"

using namespace std;

NodoRamo::NodoRamo(Ramo* _ramo){
    ramo = _ramo;
    siguente = NULL;
}

Ramo* NodoRamo::getRamo(){
    return ramo;
}

//void setRamo(Ramo* _ramo){
    //ramo = _ramo;
//}

NodoRamo* NodoRamo::getSiguente(){
    return siguente;
}

void NodoRamo::setSiguente(NodoRamo* _siguente){
    siguente = _siguente;
}