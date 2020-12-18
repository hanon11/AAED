#include "polinom.h"
polinomio::polinomio(unsigned gradoMax){
    vector = new double[gradoMax];
    for(int i = 0; i <= gradoMax; i++){
        vector[i] = 0;
    }
    grad_max = gradoMax;
    grad_pol = 0;
}

unsigned polinomio::grado() const {
    return grad_pol;
}

double polinomio::coeficiente(unsigned n) const{
    if (n > grad_max){
        return 0;
    }else return vector[n];
}

void polinomio::coeficiente(unsigned n, double c){
    if(n > grad_pol){
        grad_pol = n;
    }
    vector[n] = c;
}