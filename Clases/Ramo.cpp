#include "Ramo.h"
#include "Profesor.h"

Ramo::Ramo(string nombre, string carrera, string sala) {
    this->Nombre = nombre;
    this->Carrera = carrera;
    this->Sala = sala;
    //this->CMprofesor;
}

string Ramo::getNombre() {
    return this->Nombre;
}
string Ramo::getCarrera() {
    return this->Carrera;
}
string Ramo::getSala() {
    return this->Sala;
}

void Ramo::setNombre(string nombre) {
    this->Nombre = nombre;
}
void Ramo::setCarrera(string carrera) {
    this->Carrera = carrera;
}
void Ramo::setSala(string sala) {
    this->Sala = sala;
}