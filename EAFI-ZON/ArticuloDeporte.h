#include <iostream>
#include "Articulo.h"
#ifndef articulodeporte_h
#define articulodeporte_h
using namespace std;

class ArticuloDeporte: public Articulo{
  public:
    ArticuloDeporte(string, int, int, int);
};

ArticuloDeporte::ArticuloDeporte(string n, int i, int p, int d): Articulo(n, i, p, d){
  tipo = "deporte";
}

#endif