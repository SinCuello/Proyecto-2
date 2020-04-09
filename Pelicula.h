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
    Pelicula();
    Pelicula(Actor, int, int, int, int, int, string, string);



};
