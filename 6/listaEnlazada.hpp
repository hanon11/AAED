#ifndef _LISTAENLAZ_H
#define _LISTAENLAZ_H

#include <cassert>
template <typename T>
class listaEnla {
    struct nodo; 
public:
    typedef nodo* posicion; // posición de un elemento
    listaEnla(); // constructor, requiere ctor. T()
    listaEnla(const listaEnla<T>& l); // ctor. de copia, requiere ctor. T()
    listaEnla<T>& operator=(const listaEnla<T>& l); // asignación de listas
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const; // acceso a elto, lectura
    T& elemento(posicion p); // acceso a elto, lectura/escritura
    posicion buscar(const T& x) const; // T requiere operador ==
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const; // posición después del último
    ~listaEnla(); // destructor
private:
    struct nodo {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = 0)
            : elto(e)
            , sig(p)
        {
        }
    };
    nodo* L; // lista enlazada de nodos
    void copiar(const listaEnla<T>& l);
};

template <typename T>
void listaEnla<T>::copiar(const listaEnla<T>& l){
    L = new nodo(T()); // crear el nodo cabecera nodo* q = L;
    nodo* q = L;
    for (nodo* r = l.L->sig; r; r = r->sig) {
        q->sig = new nodo(r->elto);
        q = q->sig;
    }
}

template <typename T>
inline listaEnla<T>::listaEnla() : L(new nodo(T()))
{} 

template <typename T>
inline listaEnla<T>::listaEnla(const listaEnla<T>& l){
    copiar(l);
}

template <typename T>
listaEnla<T>& listaEnla<T>::operator=(const listaEnla<T>& l){
    if (this != &l) { // evitar autoasignación
        this->~listaEnla(); // vaciar la lista actual
        copiar(l);
    }
    return *this;
}

template <typename T>
inline void listaEnla<T>::insertar(const T& x, listaEnla<T>::posicion p){
    p->sig = new nodo(x, p->sig);
}
template <typename T>
inline void listaEnla<T>::eliminar(listaEnla<T>::posicion p){
    assert(p->sig); // p no es fin
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
}

template <typename T>
inline const T& listaEnla<T>::elemento(listaEnla<T>::posicion p) const{
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

template <typename T>
inline T& listaEnla<T>::elemento(listaEnla<T>::posicion p){
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

template <typename T>
typename listaEnla<T>::posicion
listaEnla<T>::buscar(const T& x) const{
    nodo* q = L;
    bool encontrado = false;
    while (q->sig && !encontrado)
        if (q->sig->elto == x)
            encontrado = true;
        else
            q = q->sig;
    return q;
}

template <typename T>
inline typename listaEnla<T>::posicion listaEnla<T>::siguiente(listaEnla<T>::posicion p) const{
    assert(p->sig); // p no es fin
    return p->sig;
}

template <typename T>
typename listaEnla<T>::posicion listaEnla<T>::anterior(listaEnla<T>::posicion p) const {
    nodo* q;
    assert(p != L); // p no es la primera posición
    for (q = L; q->sig != p; q = q->sig)
        ;
    return q;
}

template <typename T>
inline typename listaEnla<T>::posicion listaEnla<T>::primera() const{
    return L;
}

template <typename T>
typename listaEnla<T>::posicion listaEnla<T>::fin() const{
    nodo* p;
    for (p = L; p->sig; p = p->sig)
        ;
    return p;
}

// Destructor: destruye el nodo cabecera y vacía la listaEnla
template <typename T>
listaEnla<T>::~listaEnla(){
    nodo* q;
    while (L) {
        q = L->sig;
        delete L;
        L = q;
    }
}
#endif // _LISTAENLAZ_H