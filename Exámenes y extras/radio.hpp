/*Una emisora de radio en línea quiere automatizar la gestión de las listas de reproducción.Por este motivo decide organizar las canciones 
de que dispone en una estructura de datos.Los directivos de la emisora deciden que se necesitan las siguientes operaciones para programar la 
música a emitir:
    •crear:→radio, la emisora tiene el archivo sonoro completamente vacío.
    •añadir: radio cancion→radio, la emisora añade una canción nueva a su archivo sonoro.
    •sugerir: radio entero→cancion, devuelve la canción que tiene la duración dada en segundos y que menos veces se ha emitido en la radio.
    •seleccionar: radio entero→cancion, devuelve la canción que tiene la duración dada en segundos y que se ha emitido más veces.
    •emitir: radio cancion→radio, se toma nota de que la canción se emitirá en laradio. Cada vez que se emite una canción se llama a esta operación.
    •borrar: radio entero→radio, borra las n canciones que se han emitido menos veces. En caso de empate es indiferente la canción que se seleccione.
El número de canciones de que dispone la radio es conocido, pero también sabemos quecada semana la emisora adquiere nuevas canciones y las añade 
al archivo. Para cada canciónse almacena un número que la identifica y su duración en segundos. La empresa os pide quedefináis el TAD radio y que 
lo implementéis de manera que todas las operaciones tengan elmínimo coste temporal posible*/
#ifndef _RADIO_HPP_
#define _RADIO_HPP_
#include <iostream>
#include "../6/listaEnlazada.hpp"

struct cancion{
    int duracion, nReprod;
    std::string nombre;
};

class radio{
public:
    radio();
    void añadir(cancion);
    cancion sugerir(int segundos);
    cancion seleccionar(int segundos);
    void emitir(cancion);
    void borrar(int nVeces);
    ~radio();

private:
    listaEnla<cancion> listaRep;
};


radio::radio() {}

void radio::añadir(cancion x){
    listaRep.insertar(x, listaRep.fin());
}


//precondicion: que haya canciones en la lista con la duracion pasada
cancion radio::sugerir(int segundos){
    listaEnla<cancion>::posicion p = listaRep.primera(), cancionElegida = listaRep.primera();
    int repeticiones = listaRep.elemento(p).nReprod;
    while(p != listaRep.fin()){
        if(listaRep.elemento(p).nReprod < repeticiones && listaRep.elemento(p).duracion == segundos){
            repeticiones = listaRep.elemento(p).nReprod;
            cancionElegida = p;
        }
        p = listaRep.siguiente(p);
    }
    return listaRep.elemento(cancionElegida);
}

cancion radio::seleccionar(int segundos){
    listaEnla<cancion>::posicion p = listaRep.primera(), cancionElegida = listaRep.primera();
    int repeticiones = listaRep.elemento(p).nReprod;
    while(p != listaRep.fin()){
        if(listaRep.elemento(p).nReprod > repeticiones && listaRep.elemento(p).duracion == segundos){
            repeticiones = listaRep.elemento(p).nReprod;
            cancionElegida = p;
        }
        p = listaRep.siguiente(p);
    }
    return listaRep.elemento(cancionElegida);
}

void radio::emitir(cancion x){
    listaEnla<cancion>::posicion p = listaRep.primera();
    bool centinela = true;
    while(centinela && p != listaRep.fin()){
        if(x.nombre == listaRep.elemento(p).nombre){
            centinela = false;
            listaRep.elemento(p).nReprod++;
        }
        p = listaRep.siguiente(p);
    }
}

void radio::borrar(int nVeces){
    listaEnla<cancion>::posicion p = listaRep.primera(), cancionElegida = listaRep.primera();
    int repeticiones = listaRep.elemento(p).nReprod, contador = 0;
    while (contador < nVeces){
        while (p != listaRep.fin()){
            if (listaRep.elemento(p).nReprod < repeticiones){   
                repeticiones = listaRep.elemento(p).nReprod;
                cancionElegida = p;
            }
            p = listaRep.siguiente(p);
        }
        listaRep.eliminar(p);
        p = listaRep.primera();
        contador++;
    }
}

#endif