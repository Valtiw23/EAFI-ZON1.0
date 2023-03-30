#include <iostream>
#include "Nodo.h"
#include "ArticuloDeporte.h"
#include "ArticuloTecnologia.h"
#include "ArticuloExtranjero.h"
#ifndef lista_h
#define lista_h
using namespace std;

class Lista{
  protected:
    Nodo* inicio;
  public:
    Lista();
    Nodo* getInicio();
    void setInicio(Nodo*);
    Nodo* getFinal();
    void agregarNodo(Nodo*);
    Nodo* buscarNodo(int);
    void eliminarNodo(int);
    void mostrarLista();
    void imprimirLista();
};

Lista::Lista(){
  inicio = NULL;
}

Nodo* Lista::getInicio(){
  return inicio;
}

void Lista::setInicio(Nodo* i){
  inicio = i;
}

Nodo* Lista::getFinal(){
  Nodo* f = getInicio();
  if(f != NULL){
    while(f->getSiguiente() != NULL){
      f = f->getSiguiente();
    }
  }
  return f;
}

void Lista::agregarNodo(Nodo* n){
  if(getInicio() == NULL){
    setInicio(n);
  }else{
    getFinal()->setSiguiente(n);
  }
}

Nodo* Lista::buscarNodo(int i){
  Nodo* buscar = getInicio();
  
  while((buscar != NULL) and (buscar->getArticulo().getIdentificador() != i)){
    buscar = buscar->getSiguiente();
  }
  return buscar;
}

void Lista::eliminarNodo(int i){
  Nodo* eliminar = getInicio();
  Nodo* anterior = NULL;
  if(eliminar != NULL){
    if(eliminar->getArticulo().getIdentificador() == i){
      setInicio(getInicio()->getSiguiente());
    }else{
      while((eliminar != NULL) and (eliminar->getArticulo().getIdentificador() != i)){
        eliminar = eliminar->getSiguiente();
      }
    }
  }
  delete eliminar;
}

void Lista::mostrarLista(){
  Nodo* aux = NULL;
  aux = getInicio();
  
  while(aux != NULL){
    if(aux->getArticulo().getTipo() == "deporte"){
      cout<<"-----------------------------------"<<endl;
      cout<<"\t<ARTÍCULO DE DEPORTE>"<<endl;
      cout<<aux->getArticulo().toString()<<endl;
      cout<<"-----------------------------------"<<endl;
    }
    aux = aux->getSiguiente();
  }
  
  aux = getInicio();
  while(aux != NULL){
    if(aux->getArticulo().getTipo() == "tecnologia"){
      cout<<"-----------------------------------"<<endl;
      cout<<"\t<ARTÍCULO DE TECNOLOGÍA>"<<endl;
      cout<<aux->getArticulo().toString()<<endl;
      cout<<"-----------------------------------"<<endl;
    }
    aux = aux->getSiguiente();
  }

  aux = getInicio();
  while(aux != NULL){
    if(aux->getArticulo().getTipo() == "extranjero"){
      cout<<"-----------------------------------"<<endl;
      cout<<"\t<ARTÍCULO EXTRANJERO>"<<endl;
      cout<<aux->getArticulo().toString()<<endl;
      cout<<"-----------------------------------"<<endl;
    }
    aux = aux->getSiguiente();
  }
}

void Lista::imprimirLista(){
  Nodo* aux = NULL;
  aux = getInicio();
  cout<<"\t<CARRITO DE COMPRAS>"<<endl;
  while(aux != NULL){
    cout<<"-----------------------------------"<<endl;
    cout<<aux->getArticulo().toCantidad()<<endl;
    cout<<"-----------------------------------"<<endl;
    aux = aux->getSiguiente();
  }
}

#endif