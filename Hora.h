#include <iostream>
using namespace std;

class Hora
{
private:
    int hh, mm;
public:
    Hora();
    Hora(int, int);
    //METODOS
    void sethh(int x){hh=x;};
    int gethh(){return hh;};
    void setmm(int y){mm=y;};
    int getmm(){return mm;};

    void muestraHora();
};
//DEFAULT
Hora::Hora()
{
    hh=0;
    mm=0;
}
//PARAMETROS
Hora::Hora(int x, int y)
{
    hh=x;
    mm=y;
}

void Hora::muestraHora()
{
    cout<<"La hora es "<<hh<<":"<<mm<<endl;
}
