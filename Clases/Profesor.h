#pragma once
#include <iostream>

#include "Usuario.h"

class Profesor : public Usuario {
   private:

   public:
    Profesor(); // Constructor default
    Profesor(string, string);
    string getRamos();
};