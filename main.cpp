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
    int numero, contador;
    string linea, parrafo, numerostring;
    //------------------
    ifstream archEntrada;

    contador=0;

    archEntrada.open("actores.txt");

    while(getline(archEntrada,linea))
    {
        parrafo=linea;
        numerostring=parrafo.substr(0,2);
        numero=stoi(numerostring);
        parrafo.erase(0,2);
        actores[contador].setid(numero);
        actores[contador].setnombre(parrafo);
        contador++;
    }
    for(int i=0; i<=20; i++)
    {
        cout<<actores[i].muestraActor()<<endl;
    }

    return 0;
}
