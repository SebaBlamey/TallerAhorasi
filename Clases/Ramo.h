#pragma once
#include <iostream>

#include "Alumno.h"
#include "Profesor.h"
using namespace std;

class Ramo {
   private:
    string Nombre;
    string Carrera;
    string Sala;

   public:
    Ramo(string, string, string);
    string getNombre();
    void setNombre(string nombre);
    string getCarrera();
    void setCarrera(string carrera);
    string getSala();
    void setSala(string sala);
};