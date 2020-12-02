#ifndef _CURSOR_H_
#define _CURSOR_H_
#include "pilaEnla.h"

class Cursor {
public: 
    Cursor();
    void avanzar();
    void retrasar();
    void fin_linea();
    void prin_linea();

    void suprimir();
    void borrar();
    void insertar(char& x);
    void sobreescribir(char& x);

private:
    Pila<char> izq;
    Pila<char> der;
};


inline void Cursor::avanzar(){
    if(!der.vacia()){
        izq.push(der.tope());
        der.pop();
    }
}

inline void Cursor::retrasar(){
    if(!izq.vacia()){
        der.push(izq.tope());
        izq.pop();
    }
}

inline void Cursor::fin_linea(){
    while(!der.vacia()){
        izq.push(der.tope());
        der.pop();
    }
}

inline void Cursor::prin_linea(){
    while(!izq.vacia()){
        der.push(izq.tope());
        izq.pop();
    }
}


inline void Cursor::suprimir(){
    if(!der.vacia()){
        der.pop();
    }
}

inline void Cursor::borrar(){
    if(!izq.vacia()){
        izq.pop();
    }
}


inline void Cursor::sobreescribir(char& x){
    if(!der.vacia()){
        der.pop();
        der.push(x);
    }
}

inline void Cursor::insertar(char& x){
    if(!izq.vacia()){
        der.push(x);
    }
}

#endif