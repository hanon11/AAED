#ifndef _LISTA_CIR_HPP_
#define _LISTA_CIR_HPP
#include <cassert>

template <typename T>
class listaCir
{
    struct nodo;
    
private:
    struct nodo{
        T elem;
        nodo *ant, *sig;
        nodo(const T& e, nodo* a = POS_NULA, nodo* s = POS_NULA) :
            elem(e), ant(a), sig(s) {}
    };
    nodo* L; 
    void copiar(const listaCir<T>& lis);

public:
    typedef nodo* posicion;
    static const posicion POS_NULA;
    listaCir(); //constructor
    listaCir(const listaCir<T>& A);
    listaCir<T>& operator =(const listaCir<T>& A);
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const;
    posicion buscar(const T& x) const;
    posicion inipos() const;
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    ~listaCir();
};


template<typename T>
const typename listaCir<T>::posicion listaCir<T>::POS_NULA(nullptr); 

template <typename T>
listaCir<T>::listaCir() : L(POS_NULA)
{}

template <typename T>
void listaCir<T>::copiar(const listaCir<T>& lis){
    L = new nodo(lis.L->elem);
    L->sig = L->ant = L;
    for(nodo *q = lis.L->sig; q != lis.L; q = q->sig)
        L->ant = L->ant->sig = new nodo(q->elto, L->ant, L);
}

template<typename T>
listaCir<T>& listaCir<T>::operator =(const listaCir<T>& A) {
    if(this != &A){
        this->~listaCir();
        copiar(A);
    }
    return *this;
}

template<typename T>
void listaCir<T>::insertar(const T& x,posicion p){
    if(L == POS_NULA) {
        L = new nodo(x);
        L->sig = L->ant = L;
    }else
        p->sig = p->sig->ant = new nodo(x, p, p->sig);
}

template<typename T>
void listaCir<T>::eliminar(posicion p) {
    assert(p != POS_NULA);
    nodo *q;
    if(p->sig == L){
        if(p != L){
            L->sig->ant = p;
            p->sig = L->sig;
            delete L;
            L = p->sig;
        }else{
            delete L;
            L = POS_NULA;
        }    

    }else{
        q = p->sig;
        p->sig = q->sig;
        q->sig->ant = p;
        delete q;
    }
}
template<typename T>
const T& listaCir<T>::elemento(posicion p)const{
    assert(p != POS_NULA);
    return p->sig->elem;
}


template<typename T>
typename listaCir<T>::posicion listaCir<T>::buscar(const T& x)const{
    bool encontrado;
    listaCir<T>::posicion p;
    if(L->elto == x)
        p = L->ant;
    else{
        p = L;
        encontrado =false;
        while(p->sig != L && !encontrado){
            if(p->sig->elto == x)
                encontrado = true;
            else
                p = p->sig;
        }
        
        if(!encontrado)
            p = POS_NULA;
    }
    return p;
}

template<typename T>
typename listaCir<T>::posicion listaCir<T>::inipos()const{
    return L;
}

template<typename T>
typename listaCir<T>::posicion listaCir<T>::siguiente(posicion p)const{
    assert(p!=POS_NULA);
    return p->sig;
}

template<typename T>
typename listaCir<T>::posicion listaCir<T>::anterior(posicion p)const{
    assert(p!= POS_NULA);
    return p->ant;
}

template<typename T>
listaCir<T>::~listaCir(){
    nodo* q;
    if(L){
        while(L != L->sig){
            q = L->sig;
            L->sig = q->sig;
            delete q;
        }
        delete L;
        L = POS_NULA;
    }
}
#endif