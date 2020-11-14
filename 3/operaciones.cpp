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


polinomio crea(){
    int grado, coef;
    cout << "¿De qué grado va a ser tu polinomio?" << endl;
    cin >> grado;
    polinomio pol(grado);
    for (int i = grado; i >= 0; i--){
        cout << "Ingresa el coeficiente correspondiente a x^" << i << ": ";
        cin >> coef;
        pol.coeficiente(i, coef);
        cout << endl;
    }

    return pol;
}
void imprime(const polinomio c){
    for (int i = c.grado(); i >= 0; i--){
        if (c.coeficiente(i) >= 0 && i != c.grado())
            cout << " + ";
        if (i == 0){
            cout << c.coeficiente(i) << endl;
                
        }else if (i == 1){
            cout << c.coeficiente(i) << "x ";

        }else cout << c.coeficiente(i) << "x^" << i << " ";
    }
}