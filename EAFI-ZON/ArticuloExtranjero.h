#include <iostream>
#include "Articulo.h"
#ifndef articuloextranjero_h
#define articuloextranjero_h
using namespace std;

class ArticuloExtranjero: public Articulo{
  private:
    int impuesto;
  public:
    ArticuloExtranjero(string, int, int, int, int);
};

ArticuloExtranjero::ArticuloExtranjero(string n, int i, int p, int d, int im): Articulo(n, i, p, d){
  tipo = "extranjero";
  precio = im + p;
}

#endif