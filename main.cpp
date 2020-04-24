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
    contador=0;

    int numPeli,anio,duracion,cantActores,id;
    string genero;
    archEntrada.open("peliculas.txt");

    while(getline(archEntrada,linea))
    {
        parrafo=linea;//Lee la primera linea y la guarda en el string parrafo

        numerostring=parrafo.substr(0,3);//Del string parrafo agarra los primeros 3
        numPeli=stoi(numerostring);//Los convierte a integers
        peliculas[contador].setnumPeli(numPeli);//setea el objeto con el numPeli

        numerostring=parrafo.substr(4,4);
        anio=stoi(numerostring);
        peliculas[contador].setanio(anio);

        numerostring=parrafo.substr(9,3);
        duracion=stoi(numerostring);
        peliculas[contador].setduracion(duracion);

        numerostring=parrafo.substr(13,5);
        genero=numerostring;
        peliculas[contador].setgenero(genero);


        parrafo.erase(0,18);//Aqui solo tengo una parte del string
        numerostring=parrafo.substr(0,2);//En pocas palabra hago el string mas pequenio
        cantActores=stoi(numerostring);
        peliculas[contador].setlistaActores(cantActores);

        for(int i=0; i<cantActores; i++)
        {
            parrafo.erase(0,2);
            numerostring=parrafo.substr(0,2);
            id=stoi(numerostring);
            actores[i].setid(id);
        }
        parrafo.erase(0,2);//borro el 73
        peliculas[contador].settitulo(parrafo);

        contador++;
    }

    string nombre;
    int hora, minutos, sala, numPeliF, numxyz;
    cout<<"Cuantas funciones quieres "<<endl;
    cin>>numxyz;
    for(int i=0; i<numxyz; i++)
    {
        cout<<"A continuacion me diras las funciones del dia "<<endl;
        cout<<"Dame el clave de la Pelicula numero "<<i<<endl; cin>>nombre; funciones[i].setcveFuncion(nombre);
        cout<<"Dame al numero de la Sala numero"<<i<<endl; cin>>sala; funciones[i].setsala(sala);
        cout<<"Dame el numeor de la pelicula numero"<<i<<endl; cin>>numPeliF; funciones[i].setnumPeli(numPeliF);

        cout<<"Dame la hora y los minutos de la funcion (primero hora, despues minutos) numero"<<i<<endl;
        do
        {
            cout<<"Recuerda que la hora debe estar entre 0 y 23 y los min 0 y 59)"<<endl;
            cin>>hora>>minutos;
            if(hora<24 && hora>= 0 && minutos<60 && minutos>=0)
            {
                cout<<"La hora es valida"<<endl;
            }
            else
                cout<<"Ingresa una hora valida"<<endl;
        }
        while(hora<24 && hora>= 0 && minutos<60 && minutos>=0);
        Hora c(hora,minutos);
        funciones[i].sethora(c);
    }
    char letra;
    bool mal=false;
    do
    {
        cout<<"\n-----MENU PRINCIPAL-----";
        cout<<"\n A CONSULTA LISTA DE ACTORES";
        cout<<"\n B CONSULTA LISTA DE PELICULAS";
        cout<<"\n C CONSULTA LISTA DE FUNCIONES";
        cout<<"\n D CONSULTA FUNCIONES POR HORA";
        cout<<"\n E CONSULTA FUNCIONES POR CLAVE";
        cout<<"\n F CONSULTA FUNCIONES POR ACTOR";
        cout<<"\n G TERMINAR";
        cout<<"\n-------------------------"<<endl;
        cout<<"Digita una letra"<<endl;
        cin>>letra;
        switch(letra)
        {
        case 'A':
            {
                for(int i=0; i<=20; i++)
                {
                    cout<<"Nombre: "<<actores[i].getnombre()<<endl;
                    cout<<"Id : "<<actores[i].getid()<<endl;
                    cout<<endl;
                }
            }
            break;
        case 'B':
            {
                for(int i=0; i<=20; i++)
                {
                    cout<<"------------------------------"<<endl;
                    cout<<"Titulo "<<peliculas[i].gettitulo()<<endl;
                    cout<<"Anio "<<peliculas[i].getanio()<<endl;
                    cout<<"Duracion "<<peliculas[i].getduracion()<<endl;
                    cout<<"Genero "<<peliculas[i].getgenero()<<endl;
                    for(int j=0; j<peliculas[i].getlistActores(); j++)
                    {
                        cout<<peliculas[i].getActor(j).getnombre()<<endl;
                    }
                    cout<<"------------------------------"<<endl;
                }
            }
            break;
        case 'C':
            {
                for(int i=0; i<=cantActores; i++)
                {
                    cout<<"------------------------------"<<endl;
                    cout<<"Clave de la funcion "<<funciones[i].getcveFuncion()<<endl;
                    cout<<"Nombre de la pelicula "<<peliculas[i].gettitulo()<<endl;
                    cout<<"Numero de la sala "<<funciones[i].getsala()<<endl;
                    cout<<"Hora en que se presenta "<<funciones[i].gethora().gethh()<<endl;
                    cout<<"Los minutos se presenta "<<funciones[i].gethora().getmm()<<endl;
                    cout<<"------------------------------"<<endl;
                }
            }
            break;
        case 'D':
            {
                int m,h;
                cout<<"Dame la hora y los minutos de la funcion (primero hora, despues minutos)"<<endl;
                do
                {
                    cout<<"Recuerda que la hora debe estar entre 0 y 23 y los min 0 y 59)"<<endl;
                    cin>>h>>m;
                    if(h<24 && h>= 0 && m<60 && m>=0)
                    {
                        cout<<"La hora es valida"<<endl;
                    }
                    else
                        cout<<"Ingresa una hora valida "<<endl;
                }while(hora<24 && hora>= 0 && minutos<60 && minutos>=0);
                Hora a(h,m);
                for(int i=0; i<cantActores; i++)
                {
                    Hora b;
                    b=funciones[i].gethora();

                    if(a.gethh() == b.gethh() && a.getmm() == a.gethh())
                    {
                        cout<<"Titulo "<<peliculas[i].gettitulo()<<endl;
                        cout<<"Numero de la sala "<<funciones[i].getsala()<<endl;
                    }
                    else{
                        cout<<"Digita un horario valido"<<endl;
                    }
                }
             }
             break;
        case 'E':
            {
                int nita=-1;
                string clave;
                do
                {
                    cout<<"Dame la clave de la funcion"<<endl;
                    cin>>clave;
                    nita++;
                    cout<<"Recuerda que esto se va a repetir hasta que digites una clave correcta"<<endl;
                }while(clave!=funciones[nita].getcveFuncion());
                cout<<"El numero de la sala "<<funciones[nita].getsala()<<endl;
                cout<<"El titulo de la pelicula "<<peliculas[nita].gettitulo()<<endl;
                cout<<"La hora en que se presenta "<<funciones[nita].gethora().gethh()<<endl;
                cout<<"Los minutos en que se presenta "<<funciones[nita].gethora().getmm()<<endl;
                cout<<"La duracion de la pelicula es "<<peliculas[nita].getduracion()<<endl;
                cout<<"El genero de la peliucla es "<<peliculas[nita].getgenero()<<endl;
                cout<<"Los nombres de los actores son "<<actores[nita].getnombre()<<endl;
            }
            break;
        case 'F':
            {
                int idx=-1,idy;
                do
                {
                    cout<<"Dame el id del actor"<<endl;
                    cin>>idy;
                    cout<<"Recuerda que esto se va a repetir hasta que me digites un id valido"<<endl;
                    idx++;
                }while(idy=!actores[idx].getid());
                cout<<"El titulo de la pelicula es "<<peliculas[idx].gettitulo()<<endl;
                cout<<"El anio de la pelicula es "<<peliculas[idx].getanio()<<endl;
            }
            break;
        case 'G':
            {
                exit(0);
            }
        default:
            {
                cout<<"Opcion no valida"<<endl;
                mal=true;
            }
        }
    }while(mal==true);




    return 0;
}
