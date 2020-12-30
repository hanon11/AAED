#include "colaDina.h"
#include "../4/pila.h"

template<typename T>
bool isomorfos(const Pila<T>& pila, const Cola<T>& cola){
    bool booleano = false;
    if(!pila.vacia() && !cola.vacia()){
        Pila<T> copiaP(pila);
        Cola<T> copiaC(cola);
    
        copiaC.pop();
        size_t contador = 1;
        booleano = true;
        while(!copiaP.vacia() && !copiaC.vacia() && booleano == true){
            if(contador % 2 == 1)
                booleano = booleano && copiaP.tope() == copiaC.frente();
        
            contador++;
            copiaP.pop();
            copiaC.pop();
        }

    }

    return booleano;
}
