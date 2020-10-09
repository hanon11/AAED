//. Escriba un programa que genere 10 000 000 de números pseudoaleatorios de precisión doble
//en el intervalo [0, 1] e imprima la media de los valores y = 4 ·√(1 − x^2)
//correspondientes a cada número x. Emplee la función del ejercicio anterior.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double numeroRandom (int a, int b);
double calcularMedia(double x);

int main(){
    double num, y, sum = 0;
    srand(time(NULL));
    for (int i = 0; i < 10000000; i++){
        num = numeroRandom(0, 1);
        num *= num;
        y = 4 * sqrt(1-num);
        sum += y;
    }
    cout << "La media es: " << calcularMedia(sum) << endl;

}

double numeroRandom(int a, int b){
    return static_cast<double>(a + rand() / (static_cast<double>(RAND_MAX/(b - a))));
}

double calcularMedia(double x){
    return x / 10000000;
}