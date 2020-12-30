#ifndef _ELIMINAROCURRENCIAS_HPP_
#define _ELIMINAROCURRENCIAS_HPP_
#include "listaEnlazada.hpp"

void elimOcurrencia(listaEnla<int>& lista, int x){
    listaEnla<int>::posicion p;
    while((p = lista.buscar(x)) != lista.fin()){
        lista.eliminar(p);
    }
}

#endif