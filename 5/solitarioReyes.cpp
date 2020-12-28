#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "colaCircular.hpp"
#include "solitarioReyes.hpp"
using namespace std;

int main(){
    tCarta baraja[40];
    tMonton reyes(5); // cola de hasta 5 cartas
    // Generar las 40 cartas de la baraja española.
    for (int i = 0, p = OROS; p <= BASTOS; p++)
        for (int f = AS; f <= REY; f++, i++)
            baraja[i] = tCarta(palo(p), figura(f));

    srand(time(NULL));
    bool victoria = false;
    int partidas = 0;
    do {
        figura inicio = figura(rand() % 10); // Figura aleatoria
        random_shuffle(baraja, baraja+40); // Barajar las cartas
        victoria = solitarioReyes(baraja, reyes, inicio); // Jugar
        // Mostrar resultado
        cout << "Partidas␣jugadas␣=␣" << ++partidas << endl;
        cout << "Montón␣de␣reyes:\n";
        while (!reyes.vacia()) {
            cout << "\t" << reyes.frente().verFig() << endl;
            reyes.pop();
        }
        cout << endl;
    } while (!victoria); // Parar al ganar una partida.
    cout << "¡Conseguido!␣Bien␣hecho.\n" << endl;
}