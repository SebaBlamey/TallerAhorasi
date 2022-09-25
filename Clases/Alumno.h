#pragma once
#include <iostream>
#include "ListaRamos.h"
#include "Usuario.h"
using namespace std;
class ListaRamos;
class Ramo;

class Alumno : public Usuario {
   private:
    int Edad;
    int Semestre;
    ListaRamos* listaRamos;

   public:
    Alumno(string, string, int, int,ListaRamos*);
    int getEdad();
    int getSemestre();
    void setEdad(int);
    void setSemestre(int);
    bool agregarRamo(Ramo*);
    void eliminarRamo(Ramo*);
    void getRamos();
    void setRamos(ListaRamos*);
};