#ifndef _TREN_HPP_
#define _TREN_HPP_
#include "../4/pilaEnla.h"
#include "vagon.h" //se supone que lo dan hecho

class tren
{
private:
    Pila<vagon> izq, drcha;
public:
    tren(); //constructor
    void desIzq();
    void desDcha();
    void eliminar();
    const vagon observarAct() const;
    bool vacío();
    ~tren(); //destructor
};

tren::tren() {}

void tren::desIzq(){
    if(!drcha.vacia()){
        izq.push(drcha.tope());
        drcha.pop();
    }
}

void tren::desDcha(){
    if(!izq.vacia()){
        drcha.push(izq.tope());
        izq.pop();
    }
}

void tren::desIzq(){
    vagon aux = drcha.tope();
    drcha.pop();
    if(drcha.vacia()){
        drcha.push(aux);
    }else{
        izq.push(aux);
}

void tren::eliminar(){
    if(!drcha.vacia()){
        drcha.pop();
        if (drcha.vacia() && !izq.vacia()){
            drcha.push(izq.tope());
            izq.pop();
        }
    }
}
const vagon tren::observarAct() const{
    if(!drcha.vacia()){
        return drcha.tope();
    }
}

inline tren::vacío(){
    return(!drcha.vacia() && !izq.vacia());
}

tren::~tren(){
    izq.~Pila();
    drcha.~Pila();
}

#endif