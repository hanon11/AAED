#ifndef _LISTA_ENLAZADA_HPP_
#define _LISTA_ENLAZADA_HPP_
#include <cassert>

template<typename T>
class lista
{
private:
    T *elementos;
    size_t Lmax;
    size_t n;

public:
    typedef size_t posicion; //posicion de un elemento
    explicit lista(size_t TamMax); //constructor
    lista(const lista<T>& L); //constructor de copia
    lista<T>& operator =(const lista<T>& L);
    void insertar(const T& x, posicion p); 
    void eliminar(posicion p);
    const T& elemento(posicion p) const; //lectura elemento 
    T& elemento(posicion p); //lectura-escritura elemento
    posicion buscar(const T& x) const; 
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const; //posición después del último
    ~lista();
};

template <typename T>
inline lista<T>::lista(size_t TamMax) :
    elementos(new T[TamMax]),
    Lmax(TamMax),
    n(0)
{}

template <typename T>
lista<T>::lista(const lista<T>& L) :
    elementos(new T[L.Lmax]), 
    Lmax(L.Lmax),
    n(L.n)
{
    for(lista<T>::posicion p = 0; p < n; ++p)
        elementos[p] = L.elementos[p];
}

template <typename T>
lista<T>& lista<T>::operator =(const lista<T>& L){
    if (this != &L){ //evita autoasignación
        delete [] elementos;
        Lmax = L.Lmax;
        elementos = new T[Lmax];
    }
    n = L.n;
    for(lista<T>::posicion p = 0; p < n; ++p){
        elementos[p] = L.elementos[p];
    }
    return *this;
}

template <typename T>
void lista<T>::insertar(const T& x, lista<T>::posicion p){
    assert(p >= 0 && p <= n); //pos valida
    assert(n < Lmax); //lista no llena
    for(lista<T>::posicion q = n; q > p; q--){
        elementos[q] = elementos[q-1];
    }
    elementos[p] = x;
    n++;
}


template <typename T>
void lista<T>::eliminar(lista<T>::posicion p){
    assert(p > 0 && p < n); //posicion valida
    n--;
    for(lista<T>::posicion q = p; q < n; q++){
        elementos[q] = elementos[q+1];
    }
}

template <typename T>
inline const T& lista<T>::elemento(lista<T>::posicion p) const{
    assert(p >= 0 && p < n);
    return elementos[p];
}

template <typename T>
inline T& lista<T>::elemento(lista<T>::posicion p){
    assert(p >=0 && p < n);
    return elementos[p];
}

template <typename T>
typename lista<T>::posicion lista<T>::buscar(const T& x) const{
    lista<T>::posicion q = 0;
    bool encontrado = false;
    while(q < n && !encontrado){
        if(elementos[q] == x)
            encontrado = true;
        else q++;
    }
    return q;
}

template <typename T>
typename lista<T>::posicion lista<T>::siguiente(lista<T>::posicion p) const{
    assert(p >= 0 && p < n);
    return p+1;
}

template <typename T>
typename lista<T>::posicion lista<T>::anterior(lista<T>::posicion p) const{
    assert(p > 0 && p <= n);
    return p-1;
}

template <typename T>
inline typename lista<T>::posicion lista<T>::primera() const {
    return 0;
} 

template <typename T>
inline typename lista<T>::posicion lista<T>::fin() const {
    return n;
}

template <typename T>
inline lista<T>::~lista(){
    delete[] elementos;
}

#endif