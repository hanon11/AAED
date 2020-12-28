#ifndef _SOLITARIOREYES_HPP_
#define _SOLITARIOREYES_HPP_
#include <iostream>
#include "colaCircular.hpp"


enum figura{AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};
enum palo{OROS, COPAS, ESPADAS, BASTOS};

class tCarta{
public:
    tCarta(palo p = OROS, figura f = AS) : pal(p), fig(f) {};
    figura verFig() const{return fig;};
    palo verPalo() const{return pal;};
    friend std::ostream& operator <<(std::ostream& os,const tCarta& c);

private:
    figura fig;
    palo pal;
    static const char* nom_palo[], * nom_fig[];

};
typedef Cola_circular<tCarta> tMonton;

bool solitarioReyes(tCarta* baraja, tMonton& reyes, figura inicio){
    tMonton aux(5);
    tMonton monton[10] = {aux, aux, aux, aux, aux, aux, aux, aux, aux, aux};
    int colocadas[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0, f = AS; f <= REY; f++){
        for (int k = 0; k < 4; k++, i++){
            monton[f].push(baraja[i]);
            if(baraja[i].verFig() == f){
                colocadas[f]++;
            }
        }
    }

    figura fig_inicial = inicio;
    tCarta carta;
    while (colocadas[REY] < 4 && colocadas[fig_inicial] < 4){
        carta = monton[fig_inicial].frente();
        monton[fig_inicial].pop();
        if(fig_inicial!=carta.verFig()){
           fig_inicial = carta.verFig();
            colocadas[fig_inicial]++;
        }
        monton[fig_inicial].push(carta);
    }
    reyes = colocadas[REY];
    return(colocadas[REY]==4);
}

const char* tCarta::nom_palo[] = {"OROS   ", "COPAS  ", "ESPADAS", "BASTOS "};

const char* tCarta::nom_fig[] = {"AS     ", "DOS    ", "TRES   ", 
                                "CUATRO ", "CINCO  ", "SEIS   ", "SIETE  ",
                                "SOTA   ", "CABALLO", "REY    "};

std::ostream& operator <<(std::ostream& os, const tCarta& c){
    os << "(" << tCarta::nom_fig[c.verFig()] << ",␣"<< tCarta::nom_palo[c.verPalo()] << ")";
    return os;
}

#endif