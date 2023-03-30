#include <iostream>
#include "Cliente.h"
#include "Coordinador.h"
#include "Sistema.h"
#ifndef main_h
#define main_h
using namespace std;

int main() {
  Cliente c1;
  Coordinador c2;
  int x1, x2, i;
  
  do{
    mp();
    cin>>x1;
    switch(x1){
      case 1:
        {
          //Coordinador.
          mco();
          cin>>x2;
          switch(x2){
            case 1:
              {
                //Agregar artículo.
                mta();
                c2.agregarArticulo();
              }
            break;
            case 2:
              {
                //Modificar artículo.
                cout<<"Identificador: "<<endl;
                cin>>i;
                c2.modificarArticulo(i);
              }
            break;
            case 3:
              {
                //Eliminar artículo.
                c2.eliminarArticulo();
              }
            break;
          }
        }
      break;
      case 2:
        {
          //Cliente.
          if(c2.getInventario()->getInicio() != NULL){
            mcl();
            c2.getInventario()->mostrarLista();
            c1.comprarArticulo(c2.getInventario());
            c1.getCarrito()->imprimirLista();
            c1.pagarArticulo(c2.getInventario());
          }
        }
      break;
    }
  }while(x1 != 3);
}

#endif