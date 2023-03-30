#include <iostream>
#include "Articulo.h"
#ifndef articulotecnologia_h
#define articulotecnologia_h
using namespace std;

class ArticuloTecnologia: public Articulo{
  public:
    ArticuloTecnologia(string, int, int, int);
};

ArticuloTecnologia::ArticuloTecnologia(string n, int i, int p, int d): Articulo(n, i, p, d){
  tipo = "tecnologia";
}

#endif