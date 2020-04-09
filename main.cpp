#include <iostream>
#include <fstream>
#include <string>
#include "Pelicula.h"
#include "Funcion.h"

using namespace std;

int main()
{
    Actor actores[20];
    Funcion funciones[20];
    Pelicula peliculas[20];

    //Variables para leer el archivo actores
    //------------------
    int id, contador;//|
    string nombre;   //|
    //------------------
    ifstream archEntrada;

    contador=0;

    archEntrada.open("actores.txt");

    while(archEntrada>>id>>getline(archEntrada, nombre))
    {
        Actor[contador].setid(id);
        Actor[contador].setnombre(nombre);
        contador++;
    }
    //-----------------------
    contador=0;
    int numpeli, anio, duracion, cantActores, cantActoresEx, idx;
    string genero, titulo;
    archEntrada.open("peliculas.txt");

    while(archEntrada>>numpeli>>anio>>duracion>>genero>>cantActores>>cantActoresEx>>idx>>getline(archEntrada,titulo))
    {
        peliculas[contador].setnumPeli(numpeli);
        peliculas[contador].setanio(anio);
        peliculas[contador].setduracion(duracion);
        peliculas[contador].setgenero(genero);

    }

    return 0;
}
