#include "miPolinom.h"
polinomio::polinomio(unsigned gradoMax){
    vector = new double[gradoMax];
    for(int i = 0; i < gradoMax; ++i){
        vector[i] = 0;
    }
    gradMax = gradoMax;
}

unsigned polinomio::grado() const {
    return gradMax;
}

double polinomio::coeficiente(unsigned n) const{
    if (n > gradMax){
        return 0;
    }else return vector[n];
}

void polinomio::coeficiente(unsigned n, double c){
    vector[n] = c;

}