
#include "NodoAlumno.h"
//#include "NodoAlumno.cpp"

using namespace std;

class ListasAlumno{
    private:
     NodoAlumno* primero;
     int largo;
    
    public:
     ListasAlumno();
     void agregarAlumno(Alumno*);
     void eliminarAlumno(Alumno*);
     void imprimirLista();
     int getLargo();
};
