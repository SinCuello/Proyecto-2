#include <iostream>
#include <string>
#include "Actor.h"

using namespace std;

class Pelicula
{
private:
    int numPeli, anio, duracion, cantActores=0;
    Actor listaActores[10];

    int _listaActores[20];
    string titulo, genero;
public:

    Pelicula();

    void setnumPeli(int a){numPeli=a;};//Modificacion numPeli
    int getnumPeli(){return numPeli;};
    void setanio(int b){anio=b;};//Modificacion anio
    int getanio(){return anio;};
    void setduracion(int c){duracion=c;};//Modificacion duracion
    int getduracion(){return duracion;};
    void settitulo(string d){titulo=d;};//Modificacion titulo
    string gettitulo(){return titulo;};

    void setgenero(string e){genero=e;};//Modificacioin genero
    string getgenero(){return genero;};

    void setlistaActores(int f){cantActores=f;};//Unico metodo de acceso a la cantidad de actores
    int getlistActores(){return cantActores;};

    Actor getActor(int m){return listaActores[m];};//Me regresa el actor en ese subindice


    bool agregarActor(Actor e);//Funcion para cambiar la cant de obj
};

Pelicula::Pelicula()
{
    cantActores=0;
    listaActores[10]={};
    numPeli=0;
    anio=0;
    duracion=0;
    titulo="prueba";
    genero="prueba";
}

bool Pelicula::agregarActor(Actor e)
{
    bool seguridad = true;
    if(cantActores>=10)
    {
        seguridad=false;
        cout<<"Su lista de actores ya es mayor o igual a 10"<<endl;
        return seguridad;
    }
    else{
        cantActores+1;
        listaActores[cantActores]=e;
        cout<<"Se ha relizado su aditamiento"<<endl;
        return seguridad;
    }
}
