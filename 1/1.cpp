//1. Utilizando rand(), escriba una función que genere un número pseudoaleatorio entero en el 
//intervalo discreto [a, b].

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int numeroRandom (int a, int b);

int main(){
    int a, b, num;
    srand(time(NULL));
    cout << "Introduzca un intervalo discreto [a, b] y el programa imprimirá un número aleatrorio del mismo" << endl;
    cout << "Introduzca a: " << endl;
    cin >> a;
    cout << "Introduzca b: " << endl;
    cin >> b;
    num = numeroRandom(a, b);

    cout << "El número aleatorio es " << num << endl;

    return 0;
}

int numeroRandom(int a, int b){
    int num;
    num = a + rand() % (b - a + 1) + a;
    return num;
}