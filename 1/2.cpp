//Escriba un programa que simule 10 000 000 de tiradas de un dado. Imprima las frecuencias
//relativas que se obtienen para cada una de las caras. Emplee la función del ejercicio anterior.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int numeroRandom (int a, int b);

int main(){
    int tiradas = 10000000, vector[6] = {0, 0, 0, 0, 0, 0};
    srand(time(NULL));
    for (int i = 0; i < tiradas; i++){
        int num = numeroRandom(1, 6);
        vector[num - 1]++;
    }

    for (int j = 0; j < 6; j++){
        cout << (float) vector[j] / 10000000 << endl;
    }
}

int numeroRandom (int a, int b){
    int num;
    num =  rand() % (b - a + 1) + a;
    return num;
}
