#pragma once
#include <iostream>
#include "ListaRamos.h"
#include "Usuario.h"
#include "Ramo.h"
class Profesor : public Usuario {
   private:
        ListaRamos* listaRamos;
   public:
    Profesor(); // Constructor default
    Profesor(string, string);
    string getRamos();
    bool agregarRamo(Ramo*);
    void eliminarRamo(Ramo*);
};