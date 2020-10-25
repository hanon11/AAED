#include <iostream>
#include "1.h"
#include <algorithm>
#include "cronometro.h"
using namespace std;
//escoge el algoritmo de ordenacion
void ordenacion(int seleccion, int vector[], int i);

int main(){
    cronometro crono;
    int seleccion, i = 20000, k = 1000;
    int vector[20000];
    for (int j = 0; j < i; j++){ //relleno el vector con numeros del 1 a i
        vector[j] = j+1;
    }

    do{
        cout << "1. Intercambio directo\n2. Seleccion directa\n3. Inserccion directa." << endl;
        cin >> seleccion;
    }while (seleccion < 1 || seleccion > 3);

    while (k <= 20000){
        random_shuffle(vector,vector + sizeof vector/sizeof *vector);
        crono.activar();
        ordenacion(seleccion, vector, k);
        crono.parar();
        double tiempo = crono.tiempo();
        cout << "El tiempo para ordenar " << k << " elementos es: " << tiempo << endl;
        k += 1000;
    }

}

void ordenacion(int seleccion, int vector[], int i){
    switch (seleccion)
        {
        case 1:
            ordenacion_intercambio(vector, vector+i);
            break;
        case 2: 
            ordenacion_seleccion(vector, vector+i);
            break;
        case 3: 
            ordenacion_insercion(vector, vector+i);
            break;
        default:
            break;
        }
}
