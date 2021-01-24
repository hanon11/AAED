#ifndef _COCINA_HPP_
#define _COCINA_HPP_
#include "../6/listaDoble.hpp"
#include <cassert>


struct mueble
{
    double posicion, anchura;
    mueble(double p=0,double a=0):posicion(p),anchura(a){}
};

class cocina
{
    public:
        cocina(double l);
        bool esColocable(double anch,double p);
        void colocar(double anch,double p);
        mueble devolverMueble(int i);
        void eliminarMueble(int i);
        void juntarMueble(int i);
        ~cocina() = default;
    private:
        lista_doble<mueble> muebles;
        double longitud;
        int nMuebles;
};

cocina::cocina(double tamMax) : longitud(tamMax), nMuebles(0) {}


inline bool cocina::esColocable(double anch,double p){
    lista_doble<mueble>::posicion pos = muebles.primera();
    if(nMuebles > 0){
        while(pos != muebles.fin() && muebles.elemento(pos).posicion < p){
            pos = muebles.siguiente(pos);
        }
        if(muebles.fin() == pos){
            if(muebles.elemento(muebles.anterior(pos)).posicion + muebles.elemento(muebles.anterior(pos)).anchura + )
        }

    }else{
        

    }
}

void cocina::colocar(double anch, double p){
    assert(esColocable(anch,p));
    lista_doble<mueble>::posicion pos = muebles.primera();

    while(pos != muebles.fin() && muebles.elemento(pos).posicion < p)
        pos = muebles.siguiente(pos);
    muebles.insertar(mueble(anch,p), pos);
    nMuebles++;
}

mueble cocina::devolverMueble(int i){
    assert(nMuebles > i && i > 0);
    lista_doble<mueble>::posicion pos = muebles.primera();

    while(i > 0){
        pos = muebles.siguiente(pos);
        i--;
    }
    return muebles.elemento(pos);
}


void cocina::eliminarMueble(int i){
    assert(nMuebles > i && i > 0);
    lista_doble<mueble>::posicion pos = muebles.primera();

    while(i > 0){
        pos = muebles.siguiente(pos);
        i--;
    }
    muebles.eliminar(pos);
    nMuebles--;
}

void cocina::juntarMueble(int i){
    assert(nMuebles > i && i >= 0);
    lista_doble<mueble>::posicion pos = muebles.primera();
    if(i == 0)
        muebles.elemento(pos).posicion = 0;
    else{
        while(i > 0){
            pos = muebles.siguiente(pos);
            i--;
        }
        muebles.elemento(pos).posicion = muebles.elemento(muebles.anterior(pos)).posicion + muebles.elemento(muebles.anterior(pos)).anchura;
    }
}

cocina::~cocina() {
    muebles.~lista_doble();
}


#endif