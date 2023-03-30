#include <iostream>
#include "Lista.h"
#ifndef inventario_h
#define inventario_h
using namespace std;

class Inventario: public Lista{
  public: 
    Inventario();
};

Inventario::Inventario(): Lista(){
}

#endif