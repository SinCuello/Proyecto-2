#include <string>
#include <iostream>
#include "Hora.h"
using namespace std;

class Funcion
{
private:
    Hora hora;
    int numPeli, sala;
    string cveFuncion;
public:
    //constructores
    Funcion();
    Funcion(Hora, int, int, string);
    //modificacion de valores y retorno de los mismos
    void sethora(Hora a){hora=a;};
    Hora gethora(){return hora;};
    void setnumPeli(int b){numPeli=b;};
    int getnumPeli(){return numPeli;};
    void setsala(int c){sala=c;};
    int getsala(){return sala;};
    void setcveFuncion(string d)(cveFuncion=d;);
    string getcveFuncion(){return cveFuncion;};

    void muestraFuncion();
};

Funcion::Funcion()
{
    Hora prueba(0,0);
    hora=prueba;
    numPeli=0;
    sala=0;
    cveFuncion="prueba";
}

Funcion::Funcion(Hora _hora, int _numpeli, int _sala, string _cveFuncion)
{
    hora=_hora;
    numPeli=_numpeli;
    sala=_sala;
    cveFuncion=_cveFuncion;
}


