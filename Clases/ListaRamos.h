#include "NodoRamo.h"

using namespace std;

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