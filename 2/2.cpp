#include <iostream>
#include "1.h"
#include <algorithm>
using namespace std;

void ordenacion(int seleccion, int vector[], int i);

int main(){
    int seleccion;
    do{
        cout << "1. Intercambio directo\n2. Seleccion directa\n3. Inserccion directa." << endl;
        cin >> seleccion;
    }while (seleccion < 1 || seleccion > 3);

    for (int i = 1; i < 10; i++){
        int vector[i];
        for (int j = 0; j < i; j++){
            vector[j] = j+1;
        }
        random_shuffle(vector,vector + sizeof vector/sizeof *vector);
        ordenacion(seleccion, vector, i);
    }
}

void ordenacion(int seleccion, int vector[], int i){
    switch (seleccion)
        {
        case 1:
            ordenacion_intercambio(&vector[0], &vector[i]);
            break;
        case 2: 
            ordenacion_seleccion(&vector[0], &vector[i]);
            break;
        case 3: 
            ordenacion_insercion(&vector[0], &vector[i]);
            break;
        default:
            break;
        }
        cout << "Ordenacion numero " << i << endl;
        for(int k = 0; k < i; k++){
            cout << vector[k] << " ";
        }
        cout << endl;

}