#include "operaciones.h"


polinomio operator+(const polinomio a, const polinomio b){
    int gradoMaximo;
    if (a.grado() >= b.grado()){ //calculo el grado maximo de ambos polinomios
        gradoMaximo = a.grado();
    }else{
        gradoMaximo = b.grado();
    }
    polinomio c(gradoMaximo); //creo polinomio con el grado máximo
    for(int i = 0; i <= gradoMaximo; i++){
        c.coeficiente(i, a.coeficiente(i) + b.coeficiente(i));
    }
    return c;    
}


polinomio operator*(const polinomio a, const polinomio b){
    polinomio c(a.grado() + b.grado());
    for(int i = a.grado(); i >= 0; i--){
        for(int j = b.grado(); j >=0; j--){
            c.coeficiente(i + j, a.coeficiente(i) * b.coeficiente(j) + c.coeficiente(i + j));
        }
    }

    return c;
}


polinomio operator-(const polinomio a, const polinomio b){
    int gradoMaximo;
    if (a.grado() >= b.grado()){ //calculo el grado maximo de ambos polinomios
        gradoMaximo = a.grado();
    }else{
        gradoMaximo = b.grado();
    }
    polinomio c(gradoMaximo); //creo polinomio con el grado máximo
    for(int i = 0; i <= gradoMaximo; i++){
        c.coeficiente(i, a.coeficiente(i) - b.coeficiente(i));
    }

    return c;    
}

polinomio derivada(const polinomio a){
    polinomio c(a.grado() - 1);
    for (int i = a.grado() - 1; i >= 0; i--){
        c.coeficiente(i, a.coeficiente(i + 1) * (i + 1));
    }
    return c;
}