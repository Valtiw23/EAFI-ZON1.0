#include <iostream>
#include "Usuario.h"
#include "Inventario.h"
#include "ArticuloDeporte.h"
#include "ArticuloTecnologia.h"
#include "ArticuloExtranjero.h"
#ifndef coordinador_h
#define coordinador_h
using namespace std;

class Coordinador: public Usuario{
  private:
    Lista* inventario;
  public:
    Coordinador();
    Lista* getInventario();
    void agregarArticulo();
    void modificarArticulo(int);
    void eliminarArticulo();
};

Coordinador::Coordinador(){
  inventario = new Inventario();
}

Lista* Coordinador::getInventario(){
  return inventario;
}

void Coordinador::agregarArticulo(){
  Nodo* auxd = NULL;
  Nodo* auxt = NULL;
  Nodo* auxe = NULL;
  int t, i, p, d = 0, im;
  string n;
  cin>>t;
  cout<<"Nombre: "<<endl;
  cin>>n;
  cout<<"Identificador: "<<endl;
  cin>>i;
  cout<<"Precio: "<<endl;
  cin>>p;
  while(d < 1){
    cout<<"Disponibilidad: "<<endl;
    cin>>d;
  }
  if(t == 3){
    cout<<"Impuesto: "<<endl;
    cin>>im;
  }

  if(t == 1){
    ArticuloDeporte ad(n, i, p, d);
    auxd = new Nodo(ad);
    inventario->agregarNodo(auxd);
  }else if(t == 2){
    ArticuloTecnologia at(n, i, p, d);
    auxt = new Nodo(at);
    inventario->agregarNodo(auxt);
  }else{
    ArticuloExtranjero ae(n, i, p, d, im);
    auxe = new Nodo(ae);
    inventario->agregarNodo(auxe);
  }
  cout<<"Artículo agregado."<<endl;
}

void Coordinador::modificarArticulo(int i){
  Nodo* aux = NULL;
  int o = 1, c = 0;
  aux = inventario->buscarNodo(i);
  do{
    if(c > 0){
      cout<<"1. Modificar otro atributo."<<endl;
      cout<<"2. Salir."<<endl;
      cin>>o;
    }
    c++;
    if(o == 1){
      aux->modificarNodo();
      if(aux->getArticulo().getDisponibilidad() < 1){
        inventario->eliminarNodo(i);
      }
    }
  }while(o != 2);
}

void Coordinador::eliminarArticulo(){
  int i;
  cout<<"Identificador: "<<endl;
  cin>>i;
  inventario->eliminarNodo(i);
  cout<<"<ARTÍCULO ELIMINADO>"<<endl;
}

#endif