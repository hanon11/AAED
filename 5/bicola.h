#ifndef _BICOLA_H
#define _BICOLA_H
#include <cassert>

template<typename T> 
class Bicola{
public:
    Bicola();
    bool vacia()const;
    const T& frente() const;
    const T& final() const;
    void popfrente();
    void pushfrente(const T& x);
    ~Bicola();
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
    nodo* fin;
    void copiar(const Bicola<T>& C);
};

template<typename T>
inline Bicola<T>::Bicola():
    fin(0)
{}


template <typename T>
void Bicola<T>::copiar(const Bicola<T>& B){
    fin = new nodo(B.fin->elto);
    nodo * q = B.fin->sig;
    nodo * p = fin;
    while(q!=B.fin)
    {
        p->sig=new nodo(q->elto);
        p=p->sig;
        q=q->sig;
    }
}

template<typename T>
bool Bicola<T>::vacia()const{
    return(fin == 0);
}

template<typename T>
const T& Bicola<T>::frente()const{
    assert(!vacia());
    return(fin->sig->elem);
}

template<typename T>
void Bicola<T>::popfrente(){
    assert(!vacia());
    nodo *p = fin->sig;
    if(p == fin){
        delete p;
        fin = fin->sig = 0;
    }else{
        fin->sig = p->sig;
        delete p;
    }
}

template<typename T>
void Bicola<T>::pushfrente(const T& x){
    nodo *p = new nodo(x);
    if(fin == 0){
        fin = p->sig = p;
    }else{
        p->sig = fin->sig;
        fin->sig = p;
    }
}


template<typename T>
Bicola<T>::~Bicola(){
    nodo* p;
    while (fin != fin->sig) {
        p = fin->sig;
        fin->sig = p->sig;
        delete p;
    }
    fin = 0;
}


#endif // _BICOLA_H