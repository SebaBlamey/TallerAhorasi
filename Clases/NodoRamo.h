#include "Ramo.h"

using namespace std;

class NodoRamo{
private:
    Ramo* ramo;
    NodoRamo* siguente;
public:
    NodoRamo(Ramo*);
    Ramo* getRamo();
    void setRamo(Ramo*);
    NodoRamo* getSiguente();
    void setSiguente(NodoRamo*);

};