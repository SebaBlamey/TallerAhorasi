#pragma once
#include <iostream>
#include "ListaRamos.h"
#include "Usuario.h"
#include "Ramo.h"
class ListaRamos;
class Ramo;
class Profesor : public Usuario {
   private:
        ListaRamos* listaRamos;
   public:
    Profesor(); // Constructor default
    Profesor(string, string,ListaRamos*);
    bool agregarRamo(Ramo*);
    void eliminarRamo(Ramo*);
    void getRamos();
    void setRamos(ListaRamos*);
};