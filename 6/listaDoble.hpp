#ifndef _LISTA_DOBLE_HPP_
#define _LISTA_DOBLE_HPP_
#include <cassert>

template <typename T>
class lista_doble
{
    struct nodo;
private:
    struct nodo{
        T elem;
        nodo *ant, *sig;
        nodo(const T& e, nodo* a = nullptr, nodo* s = nullptr) :
            elem(e), ant(a), sig(s) {}
    };
    nodo* L; 
    void copiar(const lista_doble<T>& lis);

public:
    typedef nodo* posicion;
    lista_doble(); //constructor
    lista_doble(const lista_doble<T>& lis); //constructor de copia
    lista_doble<T>& operator =(const lista_doble<T>& lis);
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const;
    T& elemento(posicion p);
    posicion buscar(const T& x) const;
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;
    ~lista_doble();
};


template <typename T>
void lista_doble<T>::copiar(const lista_doble<T>& lis){
    L = new nodo(T());
    L->ant = L->sig = L;
    for(nodo* q = lis.L->sig; q != lis.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}

template <typename T>
inline lista_doble<T>::lista_doble() : L(new nodo(T())){
    L->ant = L->sig = L;
}

template <typename T>
inline lista_doble<T>::lista_doble(const lista_doble<T>& lis){
    copiar(lis);
}

template <typename T>
lista_doble<T>& lista_doble<T>::operator =(const lista_doble<T>& lis){
    if(this != &lis){
        this->~lista_doble();
        copiar(lis);
    }
    return *this;
}

template <typename T>
void lista_doble<T>::insertar(const T& x, lista_doble<T>::posicion p){
    p->sig = p->sig->ant = new nodo(x, p, p->sig);
}

template <typename T>
inline void lista_doble<T>::eliminar(lista_doble<T>::posicion p){
    assert(p->sig != L); //si no es fin
    nodo* q = p->sig; 
    p->sig = q->sig; 
    p->sig->ant = p;
    delete q;
}

template <typename T>
inline T& lista_doble<T>::elemento(lista_doble<T>::posicion p){
    assert(p->sig != L);
    return p->sig->elem;
}

template <typename T>
typename lista_doble<T>::posicion lista_doble<T>::buscar(const T& x) const {
    nodo* q = L;
    bool encontrado = false;
    while(q->sig != L && !encontrado){ 
        if(q->sig->elem == x)
            encontrado = true;
        else 
            q = q->sig;
    }
    return q;
}

template <typename T>
typename lista_doble<T>::posicion lista_doble<T>::siguiente(lista_doble<T>::posicion p) const{
    assert(p->sig != L);
    return p->sig;
}

template <typename T>
typename lista_doble<T>::posicion lista_doble<T>::anterior(lista_doble<T>::posicion p) const{
    assert(p->sig != L);
    return p->ant;
}

template <typename T>
typename lista_doble<T>::posicion lista_doble<T>::primera() const{
    return L;
}

template <typename T>
typename lista_doble<T>::posicion lista_doble<T>::fin() const {
    return L->ant;
}

template <typename T>
lista_doble<T>::~lista_doble(){
    nodo* q;
    while(L->sig != L){
        q = q->sig;
        L->sig = q->sig;
        delete q
    }
    delete L;
}

#endif