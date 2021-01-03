#ifndef _SIMBOLO_HPP_
#define _SIMBOLO_HPP_
#include "../4/pilaEnla.h"
#include <cassert>

enum trazo{I, D, S, B};

class símbolo
{
private:
    Pila<trazo> sim; //pila dinámica de trazos
    int numTrazosPila; //numero de trazos (elementos) que tiene la pila

public:
    símbolo(); //constructor
    void añadirTrazo(trazo t); //añadir un trazo a la pila de trazos
    void deshacerTrazo(int nTrazos); //deshacer n trazos de la pila
    símbolo& simX(); //
    símbolo& simY(); //
    símbolo& simXY(); //
    ~símbolo();
};

símbolo::símbolo() : 
    numTrazosPila(0)
{}

void símbolo::añadirTrazo(trazo t){
    sim.push(t);
    numTrazosPila++;
}

void símbolo::deshacerTrazo(int nTrazos){
    while(nTrazos > 0){
        assert(numTrazosPila > nTrazos);
        sim.pop();
        nTrazos--;
        numTrazosPila--;
    }
}

símbolo& símbolo::simX(){
    Pila<trazo> aux(sim), aux2;
    símbolo nuevo;

    while(!aux.vacia()){
        if(aux.tope() == trazo::S){
            aux2.push(trazo::B);
        }
        else if(aux.tope() == trazo::B){
            aux2.push(trazo::S);
        }else{
            aux2.push(aux.tope());
        }
        aux.pop();
    }

    while(!aux2.vacia()){
        nuevo.añadirTrazo(aux2.tope());
        aux2.pop();
    }

    return nuevo;

}

símbolo& símbolo::simY(){
    Pila<trazo> aux(sim), aux2;
    símbolo nuevo;

    while(!aux.vacia()){
        if(aux.tope() == trazo::D){
            aux2.push(trazo::I);
        }
        else if(aux.tope() == trazo::I){
            aux2.push(trazo::D);
        }else{
            aux2.push(aux.tope());
        }
        aux.pop();
    }

    while(!aux2.vacia()){
        nuevo.añadirTrazo(aux2.tope());
        aux2.pop();
    }
    
    return nuevo;
}

símbolo& símbolo::simXY(){
    Pila<trazo> aux(sim), aux2;
    símbolo nuevo;
    while(!aux.vacia()){
        switch(aux.tope()){
            case trazo::S:
                aux2.push(trazo::B);
                break;
            case trazo::B:
                aux2.push(trazo::S);
                break;
            case trazo::I:
                aux2.push(trazo::D);
                break;
            case trazo::D:
                aux2.push(trazo::I);
                break;
        }
        aux.pop();
    }
    while(!aux2.vacia()){
        nuevo.añadirTrazo(aux2.tope());
        aux2.pop();
    }
    
    return nuevo;
    
}

símbolo::~símbolo(){
    sim.~Pila();
}

#endif