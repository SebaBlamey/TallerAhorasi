#include "ListaRamos.h"

using namespace std;

ListaRamos::ListaRamos(){
    primero = NULL;
    largo = 0;
}
void ListaRamos::agregarRamo(Ramo* _ramo){
    NodoRamo* nuevo = new NodoRamo(_ramo);
    if(primero == NULL){
        primero = nuevo;
    }else{
        NodoRamo* aux = primero;
        while(aux ->getSiguente() != NULL){
            aux= aux ->getSiguente();
        }
        aux ->setSiguente(nuevo);
    }
    largo++;
}
void ListaRamos::eliminarRamo(Ramo* _ramo){
    NodoRamo* aux = primero;
    NodoRamo* anterior = NULL;
    while(aux != NULL){
        if(aux ->getRamo() ->getNombre() == _ramo ->getNombre()){
            if(anterior == NULL){
                primero = aux ->getSiguente();
            }else{
                anterior ->setSiguente(aux ->getSiguente());
            }
            delete aux;
            largo--;
            break;
        }
        anterior = aux;
        aux = aux->getSiguente();
    }
}
void ListaRamos::imprimirLista(){
    NodoRamo* aux = primero;
    while (aux != NULL){
        cout << aux->getRamo()->getNombre()<<endl;
        aux = aux->getSiguente();
    }
}
int ListaRamos::getLargo(){
    return largo;
}