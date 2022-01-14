#ifndef ESCALONADA_HPP
#define ESCALONADA_HPP
#include "../6/listaEnlazada.hpp"

struct escalon{
    double x, y;
    escalon(double xi = 0, double yi = 0) : x(xi), y(yi)
    {}
};

class escalonada
{
private:
    listaEnla<escalon> function;
public:
    escalonada(double x, double y);
    void add(double x, double y);
    void del(double x);
    double value(double x);
    double min();
    double max();
    void move(double w, double z);
    ~escalonada();
};

escalonada::escalonada(double x, double y)
{
    escalon p(x,y);
    function.insertar(p, function.primera());

}

void escalonada::add(double x, double y){
    listaEnla<escalon>::posicion p = function.primera();
    while (p != function.fin() && function.elemento(p).x <= x)
    {
        function.siguiente(p);
    }
    if(function.elemento(p).x == x)
        function.elemento(p).y = y;
    else{
        escalon esc(x,y);
        function.insertar(esc, p);
    }
    
}

//precondicion que el punto ya exista
void escalonada::del(double x){
    listaEnla<escalon>::posicion p = function.primera();
    while (p != function.fin() && function.elemento(p).x != x)
    {
        function.siguiente(p);
    }

    function.eliminar(p);
}

double escalonada::value(double x){
    listaEnla<escalon>::posicion p = function.primera();
    while (p != function.fin() && function.elemento(p).x != x)
    {
        function.siguiente(p);
    }

    return function.elemento(p).y;
}


double escalonada::max(){
    listaEnla<escalon>::posicion p = function.primera();
    double max;
    max = function.elemento(p).y;

    while (p != function.fin())
    {
        if(max < function.elemento(p).y)
            max = function.elemento(p).y;
        function.siguiente(p);
    }

    return max;
}


double escalonada::min(){
    listaEnla<escalon>::posicion p = function.primera();
    double min;
    min = function.elemento(p).y;

    while (p != function.fin())
    {
        if(min > function.elemento(p).y)
            min = function.elemento(p).y;
        function.siguiente(p);
    }

    return min;
}

void escalonada::move(double w, double z){
    listaEnla<escalon>::posicion p = function.primera();

    while (p != function.fin())
    {
        function.elemento(p).x += w;
        function.elemento(p).y += z;
        function.siguiente(p);
    }
}

escalonada::~escalonada()
{
    function.~listaEnla();
}


#endif
