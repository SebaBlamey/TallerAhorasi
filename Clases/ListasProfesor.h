#include "NodoProfesor.h"

using namespace std;

class ListasProfesor {
   private:
    NodoProfesor* primero;
    int largo;

   public:
    ListasProfesor();
    void agregarProfesor(Profesor*);
    void eliminarProfesor(Profesor*);
    void imprimirLista();
    int getLargo();
    Profesor* getProfesor(string);
};
