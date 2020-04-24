#include <string>
#include <iostream>
using namespace std;

class Actor
{
private:
    int id;
    string nombre;
public:
    Actor();
    Actor(int, string);

    //METODOS
    void setid(int x){id=x;};
    int getid(){return id;};

    void setnombre(string y){nombre=y;};
    string getnombre(){return nombre;};

    void muestraActor();
};
//Constructor DEFAULT
Actor::Actor()
{
    id=0;
    nombre="prueba";
}
//CONSTRUCTOR PARAMETROS
Actor::Actor(int x, string y)
{
    id=x;
    nombre=y;
}

void Actor::muestraActor()
{
    cout<<"El id es "<<id<<" y el nombre es "<<nombre<<endl;
}
