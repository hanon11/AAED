/*Una empresa ha robotizado su almacén. Para ello lo ha dividido en 60 estantes de tres tamaños diferentes (pequeño, mediano y grande) 
a partes iguales. A cada estante se le asigna un elemento según su tamaño (en cada estante solo hay elementos de un tipo, pero puede 
haber hasta 50 elementos del mismo tipo).
Se pide diseñar un TAD para el funcionamiento del robot que incluya las siguientes operaciones:
    1. Crear un almacén vacío.
    2. Insertar un elemento en un estante. Si ya hay un estante asignado, y el elemento cabe, se coloca en ese. Si no es así, 
    se busca otro estante del mismo tamaño. Si no hay, se devuelve False. Si se puede colocar se devuelve True.
    3. Comprobar si hay elementos de un tipo determinado.
    4. Sacar un elemento de un tipo dado.
    5. Vaciar el almacén (destructor del TAD).
*/

#ifndef _ALMACEN_HPP_
#define _ALMACEN_HPP_
#include "../6/listaDoble.hpp"
#include "../5/colaDina.h"
#include <cassert>


enum size{S, M, L};

struct objeto{
    size tam;
    int idObjeto;
};

struct estante{
    Cola<objeto> balda; //estante de objetos
    int nElementos = 0, max = 50; //numero de elementos colocados y totales
    size tam; //tipo de estante
};

class almacen{
private:
    lista_doble<estante> alm;
    int nElementosAlmacen = 0, maxAlmacen = 60; //numero de elementos colocados y totales

public:
    almacen();
    bool insertar(objeto);
    bool comprobar(int x);
    objeto sacar(int x); 
    ~almacen();
};

almacen::almacen() {
    lista_doble<estante>::posicion p = alm.primera();
    int contador = 0;
    while(contador < 20){
        alm.elemento(p).tam = S;
        alm.siguiente(p);
        contador++;
    }
    while(contador < 40){
        alm.elemento(p).tam = M;
        alm.siguiente(p);
        contador++;
    }
    while(contador < 60){
        alm.elemento(p).tam = L;
        alm.siguiente(p);
        contador++;
    }
};

bool almacen::insertar(objeto x){
    lista_doble<estante>::posicion p = alm.primera();
    int contador = 0;
    switch (x.tam)
    {
    case S:
        while(contador < 20){
            if((alm.elemento(p).max - alm.elemento(p).nElementos) > 0 && x.idObjeto == alm.elemento(p).balda.frente().idObjeto){ //si se cumple puedo colocarlo
                alm.elemento(p).balda.push(x);
                alm.elemento(p).nElementos++;
                return true;
            }
            contador++;
            p = alm.siguiente(p);
        }
        if(contador == 20) //si el contador ha llegado a 20 significa que no se ha podido colocar el objeto
            return false;
        break;

    case M:
        while(contador < 40){
            if((alm.elemento(p).max - alm.elemento(p).nElementos) > 0 && x.idObjeto == alm.elemento(p).balda.frente().idObjeto){ //si se cumple puedo colocarlo
                alm.elemento(p).balda.push(x);
                alm.elemento(p).nElementos++;
                return true;
            }
            contador++;
            p = alm.siguiente(p);
        }
        if(contador == 40) //si el contador ha llegado a 40 significa que no se ha podido colocar el objeto
            return false;
        break;

    case L:
       while(contador < 60){
            if((alm.elemento(p).max - alm.elemento(p).nElementos) > 0 && x.idObjeto == alm.elemento(p).balda.frente().idObjeto){ //si se cumple puedo colocarlo
                alm.elemento(p).balda.push(x);
                alm.elemento(p).nElementos++;
                return true;
            }
            contador++;
            p = alm.siguiente(p);
        }
        if(contador == 60) //si el contador ha llegado a 60 significa que no se ha podido colocar el objeto
            return false;
        break;
    }
}



bool almacen::comprobar(int x){
    lista_doble<estante>::posicion p = alm.primera();
    int contador = 0;
    while(contador < 60){
        if(x == alm.elemento(p).balda.frente().idObjeto){
            return true;
        }
        p = alm.siguiente(p);
        contador++;
    }
    return false;
}


objeto almacen::sacar(int x){
    lista_doble<estante>::posicion p = alm.primera();
    int contador = 0;
    bool centinela = true;
    while(contador < 60 && centinela){
        if(x == alm.elemento(p).balda.frente().idObjeto){
            alm.elemento(p).balda.pop();
            alm.elemento(p).nElementos--;
        }
        p = alm.siguiente(p);
    }
}

almacen::~almacen(){
    alm.~lista_doble();
}

#endif // ALMACEN_HPP_