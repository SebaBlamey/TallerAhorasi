#include "Alumno.h"
#include <string>

Alumno::Alumno(string nombre, string apellido, int edad, int Semestre) : Usuario(nombre, apellido) {
    this->Edad = edad;
    this->Semestre = Semestre;
}
int Alumno::getEdad() {
    return this->Edad;
}
int Alumno::getSemestre() {
    return this->Semestre;
}
void Alumno::setEdad(int edad) {
    this->Edad = edad;
}
void Alumno::setSemestre(int semestre) {
    this->Semestre = semestre;
}
