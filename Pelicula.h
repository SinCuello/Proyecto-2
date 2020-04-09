#include <iostream>
#include <string>
#include "Actor.h"

using namespace std;

class Pelicula
{
private:
    Actor listaActores[cantActores];
    int numPeli, anio, duracion, cantActores=10;
    string titulo, genero;
public:

    void setnumPeli(int a){numPeli=a;};//Modificacion numPeli
    int getnumPeli(){return numPeli;};
    void setanio(int b){anio=b;};//Modificacion anio
    int getanio(){return anio;};
    void setduracion(int c){duracion=c;};//Modificacion duracion
    int getanio(){return duracion;};
    void settitulo(string d){titulo=d;};//Modificacion titulo
    string gettitulo(){return titulo;};
    void setgenero(string e){genero=e;};//Modificacioin genero
    string get(){return genero;};

};

