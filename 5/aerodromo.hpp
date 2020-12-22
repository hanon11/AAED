#ifndef _AERODROMO_HPP_
#define _AERODROMO_HPP_
#include <cassert>
#include <iostream>
#include "colaCircular.hpp"
#include "colaDina.h"

using namespace std;

enum E_S{E,S};

class aerodromo{
public:
    aerodromo():aer(12){};
    void estacionar(aerodromo& A, E_S, const string);
    Cola_circular<string> ver()const noexcept{ return aer; }

private:
    Cola_circular<string> aer;
    Cola<string> espera;
};

inline void aerodromo::estacionar(aerodromo& A, E_S accion, const string matricula){
    if(accion == E){ //si va a estacionar
        if(!aer.llena())
            aer.push(matricula);
        else //si el aerodromo está lleno debe quedarse en espera
            espera.push(matricula); 

    }else{ //si va a salir
        Cola_circular<string> aux(12);
        while(aer.frente() != matricula){
            aux.push(aer.frente());
            aer.pop();
        }
        aer.pop();
        while(!aer.vacia()){
            aux.push(aer.frente());
            aer.pop();
        }
        aer = aux;
    }
}

#endif