#include "Profesor.h"

#include "ListaRamos.h"

Profesor::Profesor(string nombre, string apellido, ListaRamos* ListaRamos) : Usuario(nombre, apellido) {
    this->listaRamos = ListaRamos;
}

bool Profesor::agregarRamo(Ramo* r) {
    if (listaRamos->getLargo() < 3) {
        listaRamos->agregarRamo(r);
        return true;
    } else {
        return false;
    }
}

void Profesor::eliminarRamo(Ramo* r) {
    listaRamos->eliminarRamo(r);
}

void Profesor::getRamos() {
    listaRamos->imprimirLista();
}

void Profesor::setRamos(ListaRamos* _listaRamos) {
    listaRamos = _listaRamos;
}
