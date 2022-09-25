#pragma once
#include <iostream>
#include "ListaRamos.h"
#include "Usuario.h"
using namespace std;

class Alumno : public Usuario {
   private:
    int Edad;
    int Semestre;
    ListaRamos* listaRamos;

   public:
    Alumno(string, string, int, int);
    int getEdad();
    int getSemestre();
    void setEdad(int);
    void setSemestre(int);
    bool agregarRamo(Ramo*);
    void eliminarRamo(Ramo*);
};