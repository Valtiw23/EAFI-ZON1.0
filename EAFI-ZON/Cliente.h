#include <iostream>
#include "Usuario.h"
#include "Carrito.h"
#ifndef cliente_h
#define cliente_h
using namespace std;

class Cliente: public Usuario{
  private:
    Lista* carrito;
    
  public:
    Cliente();
    Lista* getCarrito();
    void comprarArticulo(Lista*);
    void pagarArticulo(Lista*);
};

Cliente::Cliente(){
  carrito = new Carrito();
}

Lista* Cliente::getCarrito(){
  return carrito;
}

void Cliente::comprarArticulo(Lista* lista){
  Nodo* aux1 = NULL;
  Nodo* aux2 = NULL;
  Articulo ar;
  int o = 0, cont = 0, i, c, d;
  
  do{
    if(cont > 0){
      cout<<"1. Comprar otro artículo."<<endl;
      cout<<"2. Pagar artículo."<<endl;
      cin>>o;
    }
    cont++;
              
    if(o < 2){
      cout<<"Identificador: "<<endl;
      cin>>i;
      cout<<"Cantidad: "<<endl;
      cin>>c;
      aux1 = lista->buscarNodo(i);
      aux1->modificarCantidad(c);
      ar = aux1->getArticulo();
      aux2 = new Nodo(ar);
      carrito->agregarNodo(aux2);
    }
  }while(o != 2);
}

void Cliente::pagarArticulo(Lista* lista){
  Nodo* aux1 = NULL;
  Nodo* aux2 = NULL;
  Nodo* aux3 = NULL;
  int o, pagar, i, d, descuento = 0, cont = 0, total = 0;
  string s1, s2, s3;
  cout<<"1. Pagar compra."<<endl;
  cout<<"2. Cancelar compra."<<endl;
  cin>>o;
  if(o == 1){
    pagar = 0;
    aux1 = carrito->getInicio();
    while(aux1 != NULL){
      pagar = pagar + (aux1->getArticulo().getPrecio() * aux1->getArticulo().getCantidad());
      /*
      if(aux1->getArticulo().getTipo() == "extranjero"){
        pagar = pagar + (aux1->getArticulo().getPrecio() * aux1->getArticulo().getCantidad()) + aux1->getArticulo().getImpuesto();
      }
      */
      
      aux3 = aux1->getSiguiente();
      if(aux3 != NULL){
        if(aux1->getArticulo().getTipo() == aux3->getArticulo().getTipo()){
          cont = cont + 1;
        }
      }
    
      i = aux1->getArticulo().getIdentificador();
      aux2 = lista->buscarNodo(i);
      aux2->modificarDisponibilidad();
      d = aux2->getArticulo().getDisponibilidad();
      if(d == 0){
        lista->eliminarNodo(i);
      }
      aux1 = aux1->getSiguiente();
    }

    if(cont > 0){
      descuento = (10 * pagar) / 100;
      total = pagar - descuento;
    }else{
      total = pagar;
    }

    cout<<"Total: "<<pagar<<endl;
    cout<<"Descuento: "<<descuento<<endl;
    cout<<"Total a pagar: "<<total<<endl;
    cout<<"<PAGO EXITOSO>"<<endl;
                  
  }else{
    cout<<"<COMPRA CANCELADA>"<<endl;
  }
  carrito->setInicio(NULL);
}

#endif