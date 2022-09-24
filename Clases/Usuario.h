#pragma once
#include <iostream>
using namespace std;

class Usuario {
   private:
    string Nombre;
    string Apellido;

   public:
    Usuario(string, string);
    string getNombre();
    void setNombre(string);
    string getApellido();
    void setApellido(string);
    string mostrarUsuario();
};
