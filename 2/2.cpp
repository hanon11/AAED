#include <iostream>
#include "1.h"
#include <algorithm>
using namespace std;
//escoge el algoritmo de ordenacion y devuelve 1 en caso de ordenar bien el vector
int ordenacion(int seleccion, int vector[], int i);
//si el vector se encuentra ordenado devuelve verdadero
bool ordenado(int vect[], int tamaño);

int main(){
    int seleccion, permutacionesOrdenadas = 0;
    do{
        cout << "1. Intercambio directo\n2. Seleccion directa\n3. Inserccion directa." << endl;
        cin >> seleccion;
    }while (seleccion < 1 || seleccion > 3);

    for (int i = 1; i < 10; i++){
        permutacionesOrdenadas = 0;
        int vector[i], permutaciones = 1;
        for (int j = 0; j < i; j++){ //relleno el vector con numeros del 1 a i
            vector[j] = j+1;
            permutaciones *= (j+1); //calculo el numero de posibles combinaciones del vector (i!)
        }
        cout << "Número de posibles permutaciones: " << permutaciones << endl; 
        for (int k = 0; k < permutaciones; k++){   
            random_shuffle(vector,vector + sizeof vector/sizeof *vector);
            permutacionesOrdenadas += ordenacion(seleccion, vector, i);
        }
        cout << "Número de permutaciones ordenadas: " << permutacionesOrdenadas << endl;
    }

}

int ordenacion(int seleccion, int vector[], int i){
    int contador = 0;
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
        if (ordenado(vector, i-1))
            contador = 1;

    return contador;
}

bool ordenado(int vect[], int tamaño){
    bool respuesta = true;
    for (int i = 0; i < tamaño && respuesta; i++){
        if (vect[i] > vect[i+1]){
            respuesta = false;
        }
    }
    return respuesta;
}