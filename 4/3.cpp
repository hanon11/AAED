#include <iostream>
#include "pilaEnla.h"
using namespace std;

void invertir(Pila<char>& P, char a, char b);

int main(){
    Pila<char> P;
    string cadena = {'9','8','7','6','5','4','3','2','1'};
    char a = '3', b = '7';
    cout << "Pila original: ";
    for(int i = 0; i < cadena.length(); i++){ //llenamos la pila
        P.push(cadena[i]);
        cout << P.tope(); //imprimo pila original
    }
    invertir(P, a, b);
    cout << "\nPila final : ";
    while(!P.vacia()){ //imprimo pila final
        cout << P.tope();
        P.pop();
    }

}

void invertir(Pila<char>& P, char a, char b){
    Pila <char> aux1, aux2; //uso aux1 para guardar los datos de la pila y aux2 para invertir el intervalo a-b
    bool booleano=true;
    while (!P.vacia()){ //mientras la pila no esté vacía
        if(P.tope() != a){
            aux1.push(P.tope());
            P.pop();
        }else{
            do{
                if(P.tope() == b)
                    booleano = false;
                aux2.push(P.tope());
                P.pop();
            }while(booleano && !P.vacia());

            while(!aux2.vacia()){
                aux1.push(aux2.tope());
                aux2.pop();
            }
        }
    }
    while(!aux1.vacia()){
        P.push(aux1.tope());
        aux1.pop();
    }
}