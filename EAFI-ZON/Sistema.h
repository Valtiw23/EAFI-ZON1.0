#include <iostream>
using namespace std;

class Sistema{
  public:
    void mp();
    void mco();
    void mcl();
    void mta();
    void mma();
};

//Menú principal.
void mp(){
  cout<<"\t<EAFI-ZON>\n";
  cout<<"Tipo de usuario: \n";
  cout<<"1. Coordinador.\n";
  cout<<"2. Cliente.\n";
  cout<<"3. Salir.\n";
  cout<<"Ingrese la opción:\n";
}

//Menú del coordinador.
void mco(){
  cout<<"\t<COORDINADOR>\n";
  cout<<"1. Agregar artículo.\n";
  cout<<"2. Modificar artículo.\n";
  cout<<"3. Eliminar artículo.\n";
  cout<<"Ingrese la opción:\n";
}

//Menú del cliente.
void mcl(){
  cout<<"\t<CLIENTE>\n";
  cout<<"Comprar artículo.\n";
}

//Menú tipo de artículo.
void mta(){
  cout<<"\t<TIPO DE ARTÍCULO>"<<endl;
  cout<<"1. Artículo de deporte."<<endl;
  cout<<"2. Artículo de tecnología."<<endl;
  cout<<"3. Artículo extranjero."<<endl;
}



