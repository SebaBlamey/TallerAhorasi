#pragma once
#include <iostream>

#include "Usuario.h"
using namespace std;

class Alumno : public Usuario {
   private:
    int Edad;
    int Semestre;

   public:
    Alumno(string, string, int, int);
    int getEdad();
    int getSemestre();
    void setEdad(int);
    void setSemestre(int);
};