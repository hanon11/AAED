#ifndef _PILA_H_
#define _PILA_H_
#include <cassert>
template <typename tElemento> 
class Pila{
public:
    explicit Pila(unsigned TamaMax); 
    Pila(const Pila &p);
    Pila& operator =(const Pila& p);
    bool vacia() const;
    bool llena() const;
    const tElemento &tope() const;
    void pop();
    void push(const tElemento& x);
    ~Pila(); //borra pila
private:
    tElemento *elementos;
    int Lmax; 
    int tope_; 

};


template <typename tElemento>
inline Pila<tElemento>::Pila(unsigned TamaMax):
    elementos(new tElemento[TamaMax]),
    Lmax(TamaMax),
    tope_(-1)
{}


template <typename tElemento>
Pila<tElemento>::Pila(const Pila<tElemento>& p):
    elementos(new tElemento[p.Lmax]),
    Lmax(p.Lmax),
    tope_(p.tope)
{
    for(int i = 0; i <= tope_; i++){
        elementos[i] = p.elementos[i];
    }
}
template <typename tElemento>
Pila<tElemento>& Pila<tElemento>::operator =(const Pila<tElemento>& p){
    if (this != &p) { // evitar autoasignación
    // Destruir el vector y crear uno nuevo si es necesario
    if (Lmax != p.Lmax) {
        delete[] elementos;
        Lmax = p.Lmax;
        elementos = new tElemento[Lmax];
    }
    // Copiar el vector
    tope_ = p.tope_;
    for (int i = 0; i <= tope_; i++)
        elementos[i] = p.elementos[i];
    }
    return *this;
}

template <typename tElemento>
inline bool Pila<tElemento>::vacia() const {
    return (tope_ == -1);
}

template <typename tElemento>
inline bool Pila<tElemento>::llena() const {
    return (tope_ == Lmax - 1);
}

template <typename tElemento>
inline const tElemento &Pila<tElemento>::tope() const{
    assert(!vacia());
    return elementos[tope_];
}

template <typename tElemento>
inline void Pila<tElemento>::pop(){
    assert(!vacia());
    --tope_;
}

template <typename tElemento>
inline void Pila<tElemento>::push(const tElemento& x){
    ++tope_;
    elementos[tope_] = x;
}

template <typename tElemento>
inline Pila<tElemento>::~Pila(){
    delete[] elementos;
}

#endif