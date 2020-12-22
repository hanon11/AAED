#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "solitario.hpp"
#include "pila.h"

using namespace std;

bool solitario(tCarta* baraja, figura* base); 

int main(){
    tCarta baraja[40];
    figura base[4];

    for(int i = 0, p = OROS; p <= BASTOS; p++){
        for(int f = AS; f <= REY; f++, i++){
            baraja[i] = tCarta(palo(p), figura(f));
        }
    }

    srand(time(0));
    bool victoria = false;
    int partidas = 0;
    do{
        random_shuffle(baraja, baraja+40);
        victoria = solitario(baraja, base);
        cout << "Partidas jugadas = " << ++partidas << endl;
        cout << "Últimas cartas colocadas:\n" << "\t" << tCarta(OROS, base[OROS]) << endl << "\t" << tCarta(COPAS, base[COPAS]) << endl << "\t" << tCarta(ESPADAS, base[ESPADAS]) << endl << "\t" << tCarta(BASTOS, base[BASTOS]) << endl << endl;
    }while(!victoria);
    cout << "Conseguido!!";
}

