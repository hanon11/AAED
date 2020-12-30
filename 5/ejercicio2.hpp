#ifndef _EJERCICIO2_HPP
#define _EJERCICIO2_HPP

#include "colaDina.h"
#include "../4/pilaEnla.h"

template<typename T>
void invertir(Cola<T>& COLA,T a,T b){
    bool centinela = true;
    if(!COLA.vacia()){
        Cola<T> aux;
        Pila<T> pila;

        while(!COLA.vacia() && COLA.frente()!=a){
            aux.push(COLA.frente());
            COLA.pop();
        }
        
        while(!COLA.vacia() && centinela){
            if(COLA.frente() == b)
                centinela = false;
            pila.push(COLA.frente());
            COLA.pop();
        }

        if(!COLA.vacia()){
            while(!pila.vacia()){
                aux.push(pila.tope());
                pila.pop();
            }
            while(!COLA.vacia()){
                aux.push(COLA.frente());
                COLA.pop();
            }

            COLA = aux;
            
        }
    }
}
#endif //_EJERCICIO2_HPP