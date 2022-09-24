#include "Profesor.h"

using namespace std;

class NodoProfesor
{
private:
    Profesor* profesor;
    NodoProfesor* siguente;
public:
    NodoProfesor(Profesor*);
    Profesor* getProfesor();
    void setProfesor(Profesor*);
    NodoProfesor* getSiguente();
    void setSiguente(NodoProfesor*);
};


