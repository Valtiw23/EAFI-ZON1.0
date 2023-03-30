#include <iostream>
#include "Lista.h"
#ifndef carrito_h
#define carrito_h
using namespace std;

class Carrito: public Lista{
  public:
    Carrito();
};

Carrito::Carrito(): Lista(){
}

#endif
