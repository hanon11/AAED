#ifndef _bicola_H
#define _bicola_H
#include <cassert>

template <typename T>
class bicola {
public:
    bicola();
    bicola(const bicola<T>& C);
    bicola<T>& operator=(const bicola<T>& C);
    bool vacia() const;
    const T& frente() const;
    void popfrente();
    void pushfrente(const T& x);
    const T& final() const;
    void popfinal();
    void pushfinal(const T& x);
    ~bicola();

private:
    struct nodo {
        T elem;
        nodo* sig;
        nodo(const T& x, nodo* p = 0)
            : elem(x)
            , sig(p)
        {
        }
    };

    nodo* inicio;
    nodo* fin;
    void copiar(const bicola<T>& C);
};

template <typename T>
inline bicola<T>::bicola()
    : inicio(0)
    , fin(0)
{
}

template <typename T>
inline bicola<T>::bicola(const bicola<T>& C)
    : inicio(0)
    , fin(0)
{
    copiar(C);
}

template <typename T>
bicola<T>& bicola<T>::operator=(const bicola<T>& C)
{
    if (this != &C) {
        this->~bicola();
        copiar(C);
    }
    return *this;
}

template <typename T>
bool bicola<T>::vacia() const
{
    return (inicio == 0);
}

template <typename T>
const T& bicola<T>::frente() const
{
    assert(!vacia());
    return (inicio->elem);
}

template <typename T>
void bicola<T>::popfrente()
{
    assert(!vacia());
    nodo* p = inicio;
    inicio = p->sig;
    if (!inicio)
        fin = 0;
    delete p;
}

template <typename T>
void bicola<T>::pushfrente(const T& x)
{
    nodo* p = new nodo(x);
    if (inicio == 0) {
        inicio = fin = p;
    } else {
        fin = fin->sig = p;
    }
}


template <typename T>
const T& bicola<T>::final() const
{
    assert(!vacia());
    return (fin->elem);
}

template <typename T>
void bicola<T>::popfinal(){
    assert(!vacia());
    nodo* p;
    if (fin == fin->sig) {
        p = fin;
        fin = 0;
        delete p;
    }else{
        p = fin->sig;

        while (p->sig != fin) {
            p = p->sig;
        }
        fin = p;
        //p->sig = fin->sig;
    }
}

template <typename T>
void bicola<T>::pushfinal(const T& x)
{
    nodo* p = new nodo(x);
    if (fin == 0) {
        fin = p->sig = p;
    } else {
        p->sig = fin->sig;
        fin->sig = p;
        fin = p;
    }
}

template <typename T>
void bicola<T>::copiar(const bicola<T>& C)
{
    if (C.inicio) { // C no está vacía // Copiar el primer elto.
        inicio = fin = new nodo(C.inicio->elem);
        // Copiar el resto de elementos hasta el final de la bicola.
        for (nodo* p = C.inicio->sig; p; p = p->sig) {
            fin->sig = new nodo(p->elem);
            fin = fin->sig;
        }
    }
}

template <typename T>
bicola<T>::~bicola()
{
    nodo* p;
    while (inicio) {
        p = inicio->sig;
        delete inicio;
        inicio = p;
    }
    fin = 0;
}

#endif // _bicola_h