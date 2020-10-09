//Escriba un programa que genere 10 000 000 de permutaciones pseudoaleatorias de los 6
//primeros números naturales e imprima cuántas de ellas están ordenadas.
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


bool ordenado(int vect[]);

int main(){
    int vect[6] = {1, 2, 3, 4, 5, 6}, ordenadas = 0;
    for (int i = 0; i < 10000000; i++){
        random_shuffle(vect, vect + sizeof vect/sizeof *vect);
        if (ordenado(vect)){
            ordenadas++;
        }
    }
    cout << "Número de permutaciones ordenadas: " << ordenadas << endl;
}

bool ordenado(int vect[]){
    bool respuesta = true;
    for (int i = 0; i < 5 && respuesta; i++){
        if (vect[i] > vect[i+1]){
            respuesta = false;
        }
    }
    return respuesta;
}