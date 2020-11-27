#include <iostream>
#include "pilaEnla.h"
#include<fstream>
#include<string>
using namespace std;

fstream& operator >>(fstream& fe, Pila<int>& P); //flujo entrada
fstream& operator <<(fstream& fs, Pila<int>& P); //flujo salida
void pila_final(const Pila<int>& P,const Pila<int>& Q, Pila<int>& R);

int main(){
    fstream fich("fichero4.txt");
    Pila<int> P, Q, R;
    fich >> P >> Q;
    pila_final(P, Q, R);
    fich << R;
    fich.close();
}

fstream& operator >>(fstream& fe, Pila<int>& P){
    char cifra;
    while(fe.get(cifra) && cifra != '\n')
        P.push(cifra -= '0');
    return fe;
}

fstream& operator <<(fstream& fs, Pila<int>& P){
    while(!P.vacia()){
        fs << P.tope();
        P.pop();
    }
    fs << endl;
    return fs;
}


void pila_final(const Pila<int>& P, const Pila<int>& Q, Pila<int>& R){
    int acarreo = 0;
    while(!P.vacia() && !Q.vacia()){ //mientras ambas pilas sigan llenas
        if((P.tope() + Q.tope() + acarreo) >= 10){ //si el numero a hacer push >=10 me llevo una
            R.push(P.tope() + Q.tope() + acarreo - 10);
            acarreo = 1;
        }else{ //sino se hace push de la suma
            R.push(P.tope() + Q.tope() + acarreo);
            acarreo = 0;
        }
        P.pop();
        Q.pop();
    }
    while(!P.vacia()){
        if((P.tope() + acarreo) >= 10){
            R.push(P.tope()+ acarreo - 10);
            acarreo++;
        }else{
            R.push(P.tope()+ acarreo);
            acarreo = 0;
        }
        P.pop();
    }
    while(!Q.vacia()){
        if((Q.tope() + acarreo) >= 10){
            R.push(Q.tope()+ acarreo - 10);
            acarreo++;
        }else{
            R.push(Q.tope()+ acarreo);
            acarreo = 0;
        }
        Q.pop();
    }
    if(acarreo != 0){
        R.push(acarreo);
    }
}