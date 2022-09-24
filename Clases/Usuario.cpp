#include "Usuario.h"

Usuario::Usuario(string nombre, string apellido) {
    Nombre = nombre;
    Apellido = apellido;
}

string Usuario::getNombre() {
    return Nombre;
}

void Usuario::setNombre(string nombre) {
    Nombre = nombre;
}

string Usuario::getApellido() {
    return Apellido;
}

void Usuario::setApellido(string apellido) {
    Apellido = apellido;;
}

string Usuario::mostrarUsuario(){
    return Nombre + " " + Apellido;
}