#include <iostream>
#include "pilaEnla.h"
#include <cstring>
using namespace std;

bool palindromo(string& cadena);

int main(){
    string cadena;
    cout << "Introduce una cadena y el programa te dirá si es de la forma X&Y. Siendo X una cadena e Y la cadena inversa, separadas por &: ";
    cin >> cadena;
    if (palindromo(cadena))
        cout << "Se cumple";
    else 
        cout << "No se cumple";
    return 0;
}


bool palindromo(string& cadena){
    Pila<char> pila;
    int i;
    for (i = 0; i < cadena.length() && cadena[i]!='&'; i++){
        pila.push(cadena[i]);
    }
    for(int j = i + 1; j < cadena.length(); j++){
        if(pila.tope() != cadena[j]){
            return false;
        }
        pila.pop();
    }
    return true;
}