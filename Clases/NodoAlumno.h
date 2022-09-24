
#include "Alumno.h"

using namespace std;

class NodoAlumno {
   private:
    Alumno* alumno;
    NodoAlumno* siguiente;

   public:
    NodoAlumno(Alumno*);
    Alumno* getAlumno();
    void setAlumno(Alumno*);
    NodoAlumno* getSiguiente();
    void setSiguiente(NodoAlumno*);
};

