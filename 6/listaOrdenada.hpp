#ifndef _LISTA_ORD_HPP_
#define _LISTA_ORD_HPP_

#include "listaEnlazada.hpp"
#include <iostream>

template <typename T>
class listaOrdenada
{
    typedef typename listaEnla<T>::posicion posicion;
    public:

        listaOrdenada();
        listaOrdenada(const listaOrdenada<T>& l);
        listaOrdenada<T>& operator =(const listaOrdenada<T>& L);

        void insertar(const T& x);
        void eliminar(posicion p);
        
        /* Método observador para ver un elemento */
        const T& elemento(posicion p)const;

        /* Buscar un elemento (Requiere que el tipo T,tenga el operador ==) */
        posicion buscar(const T& x)const;
        
        /* Para recorrer la lista */
        posicion primera()const;
        posicion fin()const;
        posicion siguiente(posicion p)const;
        posicion anterior(posicion p)const;

        void imprimir();

        ~listaOrdenada() = default;
    private:
        listaEnla<T> lista;
};

template<typename T>
listaOrdenada<T>::listaOrdenada(){}

template<typename T>
listaOrdenada<T>::listaOrdenada(const listaOrdenada<T>& l):lista(l){}

template<typename T>
listaOrdenada<T>& listaOrdenada<T>::operator =(const listaOrdenada<T>& l){
    if(this != &l){
        lista = l;
    }
    return *this;
} 

template<typename T>
void listaOrdenada<T>::insertar(const T& x){
    posicion p = lista.primera();
    while(p!=lista.fin() && x>lista.elemento(p))
        p=lista.siguiente(p);
    lista.insertar(x,p);
}

template<typename T>
void listaOrdenada<T>::eliminar(posicion p){
    assert(p!=lista.fin());
    lista.eliminar(p);
}

template<typename T>
const T& listaOrdenada<T>::elemento(posicion p)const{
    assert(p!=lista.fin());
    return lista.elemento(p);
}

template<typename T>
typename listaOrdenada<T>::posicion listaOrdenada<T>::buscar(const T& x)const{
    return lista.buscar(x);
}

template<typename T>
typename listaOrdenada<T>::posicion listaOrdenada<T>::primera()const{
    return lista.primera();
}

template<typename T>
typename listaOrdenada<T>::posicion listaOrdenada<T>::fin()const{
    return lista.fin();
}

template<typename T>
typename listaOrdenada<T>::posicion listaOrdenada<T>::siguiente(posicion p)const{
    assert(p!=lista.fin());
    return lista.siguiente(p);
}

template<typename T>
typename listaOrdenada<T>::posicion listaOrdenada<T>::anterior(posicion p)const{
    assert(p!=lista.primera());
    return lista.anterior(p);
}

template<typename T>
void listaOrdenada<T>::imprimir(){
    posicion p = lista.primera();
    while(p!=lista.fin())
    {
        std::cout<<lista.elemento(p)<<std::endl;
        p=lista.siguiente(p);
    }
}

#endif