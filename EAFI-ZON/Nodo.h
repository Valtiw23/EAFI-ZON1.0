#include <iostream>
#include "Articulo.h"
#ifndef nodo_h
#define nodo_h
using namespace std;

class Nodo{
  private:
    Articulo ar;
    Nodo* siguiente;
  public:
    Nodo(Articulo);
    Articulo getArticulo();
    Nodo* getSiguiente();
    void setArticulo(Articulo);
    void setSiguiente(Nodo*);
    void modificarNodo();
    void modificarDisponibilidad();
    void modificarCantidad(int);
};

Nodo::Nodo(Articulo a){
  ar = a;
  siguiente = NULL;
}

Articulo Nodo::getArticulo(){
  return ar;
}

Nodo* Nodo::getSiguiente(){
  return siguiente;
}

void Nodo::setArticulo(Articulo a){
  ar = a;
}

void Nodo::setSiguiente(Nodo* s){
  siguiente = s;
}

void Nodo::modificarNodo(){
  int o, c, i, p, d = 0;
  string n;
  do{
    cout<<"\t<MODIFICAR ARTÍCULO>\n";
    cout<<"1. Nombre.\n";
    cout<<"2. Identificador.\n";
    cout<<"3. Precio.\n";
    cout<<"4. Disponibilidad.\n";
    cout<<"Ingrese la opción:\n";
    cin>>o;
    c = 0;
    switch(o){
      case 1:
        cout<<"Ingrese el nombre: ";
        cin>>n;
        ar.setNombre(n);
      break;
      case 2:
        cout<<"Ingrese el identificador: ";
        cin>>i;
        ar.setIdentificador(i);
      break;
      case 3:
        cout<<"Ingrese el precio: ";
        cin>>p;
        ar.setPrecio(p);
      break;
      case 4:
        while(d < 1){
          cout<<"Ingrese la disponibilidad: "<<endl;
          cin>>d;
        }
        ar.setDisponibilidad(d);
      break;
      default: 
        cout<<"<OPCIÓN INVÁLIDA>";
        c++;
      break;
    }
  }while(c == 1);
  cout<<"<ARTÍCULO ACTUALIZADO>\n";
  cout<<ar.toString()<<endl;
}

void Nodo::modificarDisponibilidad(){
  ar.setDisponibilidad(ar.getDisponibilidad() - 1);
}

void Nodo::modificarCantidad(int c){
  ar.setCantidad(c);
}

#endif