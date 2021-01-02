#ifndef _TREN_HPP_
#define _TREN_HPP_
#include "../4/pilaEnla.h"
#include "vagon.h" //se supone que lo dan hecho

class tren
{
private:
    Pila<vagon> izq, drcha; //supongo robot en la cima de la pila drch
public:
    tren(); //constructor
    void desIzq(); //si drch no está vacía, pasa el vagon a la izq, sino no hace nada
    void desDcha(); //si izq no está vacía, pasa el vagon a la drch, sino no hace nada
    void eliminar(); //eliminar vagon activo
    const vagon observarAct() const; //devuelve vagón activo
    bool vacío(); //devuelve si el tren está o no vacío
    ~tren(); //destructor
};

tren::tren() {}

void tren::desIzq(){
    vagon aux = drcha.tope();
    drcha.pop();
    if(drcha.vacia()){
        drcha.push(aux);
    }else{
        izq.push(aux);
}

void tren::desDcha(){
    if(!izq.vacia()){
        drcha.push(izq.tope());
        izq.pop();
    }
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