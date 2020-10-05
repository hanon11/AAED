//1. Utilizando rand(), escriba una función que genere un número pseudoaleatorio entero en el 
//intervalo discreto [a, b].

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void numeroRandom (int a, int b);

int main(){
    int a, b;
    cout << "Introduzca un intervalo discreto [a, b] y el programa imprimirá un número aleatrorio del mismo" << endl;
    cout << "Introduzca a: " << endl;
    cin >> a;
    cout << "Introduzca b: " << endl;
    cin >> b;
    numeroRandom(a, b);

    return 0;
}

void numeroRandom(int a, int b){
    int num;
    srand(time(NULL));
    num = a + rand() % ((a + 1) - b);
    cout << "El número aleatorio es " << num << endl;
}