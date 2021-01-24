#ifndef CUBILETE_HPP
#define CUBILETE_HPP
#include "../4/pilaEnla.h"

enum postura{U,D,R,L};

struct cubilete{
    float tam;
    postura pos;
};


Pila<cubilete> juego(Pila<cubilete> cubiletes){
    Pila<cubilete> aux, final;
    cubilete auxCubilete;
    float tamMax = 0;

    while(!cubiletes.vacia()){
        while(!cubiletes.vacia()){
            aux.push(cubiletes.tope());
            if(cubiletes.tope().tam > tamMax){
                tamMax = cubiletes.tope().tam;
            }
            cubiletes.pop();
        }

        while (!aux.vacia()){
            if(aux.tope().tam == tamMax){
                auxCubilete = aux.tope();
                auxCubilete.pos = D;
                final.push(auxCubilete);
            }else{
                cubiletes.push(aux.tope());
            }
            
            aux.pop();
        }
        tamMax = 0;
    }
    return final;
}

#endif