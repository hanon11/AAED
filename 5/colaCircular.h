#ifndef _COLA_CIRCULAR_H
#define _COLA_CIRCULAR_H
#include <cassert>

template<typename T> 
class Cola_circular{
public:
    Cola_circular(unsigned Tam);
    Cola_circular(const Cola_circular<T>& C);
    Cola_circular<T>& operator = (const Cola_circular<T>& C);
    bool vacia()const;
    bool llena()const;
    const T& frente() const;
    void pop();
    void push(const T& x);
    ~Cola_circular();
private:
    T *elementos;
    int fin,inicio;
    int Lmax;
};

template<typename T>
inline Cola_circular<T>::Cola_circular(unsigned Tam):
     elementos(new T[Tam+1]),
     Lmax(Tam+1),
     inicio(0),
     fin(Tam)
{
}

template<typename T>
inline Cola_circular<T>::Cola_circular(const Cola_circular<T> &C):
    elementos(new T[C.Lmax]),
    Lmax(C.Lmax),
    inicio(C.inicio),
    fin(C.fin){
    if(!C.vacia()){
        for(int i=inicio;i!=(fin+1)%Lmax;i=(i+1)%Lmax){
            elementos[i]=C.elementos[i];
        }
    }
}

template<typename T>
Cola_circular<T>& Cola_circular<T>::operator =(const Cola_circular<T>& C){
    if(this!=&C){
        inicio=C.inicio;
        fin=C.fin;
        if(Lmax!=C.Lmax){
            delete[] elementos;
            Lmax=C.Lmax;
            elementos=new T[C.Lmax];
        }
        if(!C.vacia()){
            for(int i=inicio;i!=(fin+1)%Lmax;i=(i+1)%Lmax){
                elementos[i]=C.elementos[i];
            }
        }
    }
    return *this;
}

template<typename T>
bool Cola_circular<T>::vacia()const{
    return(inicio==(fin+1)%Lmax);
}

template<typename T>
bool Cola_circular<T>::llena() const{
    return(inicio==(fin + 2)%Lmax);
}

template<typename T>
const T& Cola_circular<T>::frente()const{
    assert(!vacia());
    return(elementos[inicio]);
}

template<typename T>
void Cola_circular<T>::pop(){
    assert(!vacia());
   inicio=(inicio+1)%Lmax;
}

template<typename T>
void Cola_circular<T>::push(const T& x){
    assert(!llena());
    fin=(fin+1)%Lmax;
    elementos[fin]=x;

}

template<typename T>
Cola_circular<T>::~Cola_circular(){
    delete[] elementos;
}


#endif // _COLA_CIRCULAR_H