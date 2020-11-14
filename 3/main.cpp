#include <iostream>
#include "polinom.h"
#include "operaciones.h"
using namespace std;

polinomio crea();

int main(){
    bool booleano = true;
    polinomio a(1), b(1), c(1);
    int opcion, op;
    do{
        do{
            cout << "Bienvenido, ingrese primero el polinomio A y luego el B: " << endl << "1. Crear polinomio A" << endl << "2. Crear polinomio B" << endl;
            cin >> opcion;
        }while(opcion < 1 || opcion > 2);
        switch (opcion){
            case 1:
                a = crea();
                break;
            case 2:
                b = crea();
                booleano = false;
                break;
            default:
                break;
        }

    }while(booleano); //repite mientras sea verdadero

    do{
        cout<< endl << "|OPCIONES|\n 1. Suma de polinomios\n 2. Resta\n 3. Multiplicacion \n 4. Derivada de A\n 5. Derivada de B\n 0. Salir"<<endl;
        cin >> op;
        switch (op){
            case 1:
                c = a + b;
                break;
            case 2:
                c = a - b;
                break;    
            case 3:
                c = a * b;
                break;
            case 4:
                c = derivada(a);
                break;
            case 5:
                c = derivada(b);
                break;
            default:
                break;
        }
        for (int i = c.grado(); i >= 0; i--){
            if (i == 0){
                cout << c.coeficiente(i) << endl;
                
            }else if (i == 1)
                cout << c.coeficiente(i) << "x" << " + ";
            else cout << c.coeficiente(i) << "x^" << i << " + ";
        }
    }while(op != 0);

}


polinomio crea(){
    int grado, coef;
    cout << "¿De qué grado va a ser tu polinomio?" << endl;
    cin >> grado;
    polinomio pol(grado);
    fflush(stdin);
    for (int i = grado; i >= 0; i--){
        cout << "Ingresa el coeficiente correspondiente a x^" << i << ": ";
        cin >> coef;
        pol.coeficiente(i, coef);
        cout << endl;
    }

    return pol;
}