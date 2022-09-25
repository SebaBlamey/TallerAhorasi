#pragma once
#include "NodoRamo.h"
#include "Ramo.h"
using namespace std;
class NodoRamo;
class Ramo;

class ListaRamos{
private:
    NodoRamo* primero;
    int largo;
public:
    ListaRamos();
    void agregarRamo(Ramo*);
    void eliminarRamo(Ramo*);
    void imprimirLista();
    int getLargo();
    Ramo* buscarRamo(string);
    
};