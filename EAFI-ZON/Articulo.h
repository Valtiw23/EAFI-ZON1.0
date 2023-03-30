#include <iostream>
#include <string>
#include <sstream>
#ifndef articulo_h
#define articulo_h
using namespace std;

class Articulo{
  protected:
    string nombre;
    int identificador;
    int precio;
    int disponibilidad;
    //No me funcionó el dynamic_cast.
    string tipo;
    //Para que el cliente ingrese cuantas unidades quiere de ese artículo.
    int cantidad;
    //int impuesto;
  public:
    Articulo();
    Articulo(string, int, int, int);
    //Articulo(string, int, int, int, int);
    string getNombre();
    int getIdentificador();
    int getPrecio();
    int getDisponibilidad();
    string getTipo();
    int getCantidad();
    //virtual int getImpuesto();
    void setNombre(string);
    void setIdentificador(int);
    void setPrecio(int);
    void setDisponibilidad(int);
    void setCantidad(int);
    //virtual void setImpuesto(int);
    string toString();
    string toCantidad();
};

Articulo::Articulo(){
}

Articulo::Articulo(string n, int i, int p, int d){
  nombre = n;
  identificador = i;
  precio = p;
  disponibilidad = d;
}


string Articulo::getNombre(){
  return nombre;
}

int Articulo::getIdentificador(){
  return identificador;
}

int Articulo::getPrecio(){
  return precio;
}

int Articulo::getDisponibilidad(){
  return disponibilidad;
}

string Articulo::getTipo(){
  return tipo;
}


int Articulo::getCantidad(){
  return cantidad;
}

void Articulo::setNombre(string n){
  nombre = n;
}

void Articulo::setIdentificador(int i){
  identificador = i;
}

void Articulo::setPrecio(int p){
  precio = p;
}

void Articulo::setDisponibilidad(int d){
  disponibilidad = d;
}

void Articulo::setCantidad(int c){
  cantidad = c;
}

string Articulo::toString(){
  stringstream s;
  s<<"Nombre: "<<nombre<<endl;
  s<<"Identificador: "<<identificador<<endl;
  s<<"Precio: "<<precio<<endl;
  s<<"Disponiblidad: "<<disponibilidad<<endl;
  return s.str();
}

string Articulo::toCantidad(){
  stringstream s;
  s<<"Nombre: "<<nombre<<endl;
  s<<"Identificador: "<<identificador<<endl;
  s<<"Precio: "<<precio<<endl;
  s<<"Cantidad: "<<cantidad<<endl;
  return s.str();
}

#endif
