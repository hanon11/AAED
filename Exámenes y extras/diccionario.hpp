#ifndef DICCIONARIO_HPP
#define DICCIONARIO_HPP
#include <iostream>
#include <cstring>
#include "../6/listaEnlazada.hpp"
using namespace std;

struct palabra
{
    string nom;
    listaEnla<string> traducciones;
    palabra(string pal = "") : nom(pal) {}

};


class diccionario
{
private:
    listaEnla<palabra> dic;
public:
    diccionario();
    void insertar(string pal, string traduccion);
    void eliminar(string pal, string traduccion);
    listaEnla<string> consultar(string pal);
    ~diccionario();
};

diccionario::diccionario()
{}

void diccionario::insertar(string pal, string traduccion){
    listaEnla<palabra>::posicion p = dic.primera();
    while(p != dic.fin() && dic.elemento(p).nom != pal){
        dic.siguiente(p);
    }
    dic.elemento(p).traducciones.insertar(traduccion, dic.elemento(p).traducciones.fin());
}


void diccionario::eliminar(string pal, string traduccion){
    listaEnla<palabra>::posicion p = dic.primera();
    listaEnla<string>::posicion p2 = dic.elemento(p).traducciones.primera();
    while(p != dic.fin() && dic.elemento(p).nom != pal){
        dic.siguiente(p);
    }

    while(p2 != dic.elemento(p).traducciones.fin() && dic.elemento(p).traducciones.elemento(p2) != traduccion){
        dic.elemento(p).traducciones.siguiente(p2);
    }

    dic.elemento(p).traducciones.eliminar(p2);
    
}

listaEnla<string> consultar(string pal){
    listaEnla<palabra>::posicion p = dic.primera();
    while(p != dic.fin() && dic.elemento(p).nom != pal){
        dic.siguiente(p);
    }
    return dic.elemento(p).traducciones;
}

diccionario::~diccionario()
{
    dic.~listaEnla();
}


#endif