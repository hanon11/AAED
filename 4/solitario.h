#ifndef _SOLITARIO_H
#define _SOLITARIO_H

enum figura{VACIA, AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};
enum palo{OROS, COPAS, ESPADAS, BASTOS};


class tCarta{
public:
    tCarta(palo p = OROS, figura f = AS) : pal(p), fig(f) {};
    figura verFig() const{return fig;};
    palo verPalo() const{return pal;};
    friend std::ostream& operator <<(std::ostream& os, const tCarta& c);

private:
    figura fig;
    palo pal;
    static const char* nom_palo[], * nom_fig[];

};
const char* tCarta::nom_palo[] = {"OROS   ", "COPAS  ", "ESPADAS", "BASTOS "};

const char* tCarta::nom_fig[] = {"-------", "AS     ", "DOS    ", "TRES   ", 
                                "CUATRO ", "CINCO  ", "SEIS   ", "SIETE  ",
                                "SOTA   ", "CABALLO", "REY    "};

std::ostream& operator <<(std::ostream& os, const tCarta& c)
{
    os << "(" << tCarta::nom_fig[c.verFig()] << ", " << tCarta::nom_palo[c.verPalo()] << ")";
    return os;
}

#endif
