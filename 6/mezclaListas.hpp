#ifndef _MECLALISTAS_HPP_
#define _MEZCLALISTAS_HPP_
#include "listaOrdenada.hpp"
#include "listaEnlazada.hpp"

listaEnla<int> mezcla(listaEnla<int> lista1, listaEnla<int> lista2){
    listaEnla<int> listaFinal;
    listaEnla<int>::posicion p1, p2, p3;

    p1 = lista1.primera();
    p2 = lista2.primera();
    p3 = listaFinal.primera();

    while (p1 != lista1.fin() && p2 != lista2.fin()){
        if(lista1.elemento(p1) <= lista2.elemento(p2)){
            listaFinal.insertar(lista1.elemento(p1), p3);
            p1 = p1->sig;
        }else{
            listaFinal.insertar(lista2.elemento(p2), p3);
            p2 = p2->sig;
        }
        p3 = p3->sig;
    

    }
    while (p1 != lista1.fin()){
        listaFinal.insertar(lista1.elemento(p1), p3);
        p1 = p1->sig;
        p3 = p3->sig;
    }
    while (p2 != lista2.fin()){
        listaFinal.insertar(lista2.elemento(p2), p3);
        p2 = p2->sig;
        p3 = p3->sig;
    }
    return listaFinal;
}
#endif