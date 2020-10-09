//. Utilizando rand(), escriba una función que genere un número pseudoaleatorio de coma
//flotante y precisión doble en el intervalo continuo [a, b].
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double numeroRandom (int a, int b);

int main(){
    int a, b;
    double num;
    srand(time(NULL));
    cout << "Introduzca un intervalo discreto [a, b] y el programa imprimirá un número aleatrorio perteneciente al mismo" << endl;
    cout << "Introduzca a: " << endl;
    cin >> a;
    cout << "Introduzca b: " << endl;
    cin >> b;
    num = numeroRandom(a, b);
    cout << "El número aleatorio es " << num << endl;

}

double numeroRandom(int a, int b){
    return static_cast<double>(a + rand() / (static_cast<double>(RAND_MAX/(b - a))));
}