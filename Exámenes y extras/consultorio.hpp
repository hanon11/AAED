#ifndef _CONSULTORIO_HPP_
#define _CONSULTORIO_HPP_
#include "../6/listaDoble.hpp"  //con la simplemente enlazada se puede pero asi se queda
#include "../5/colaDina.h"

struct paciente{ 
    int idPaciente;
};

struct medico{ //cada medico es una cola de pacientes
    Cola<paciente> pacientes;
};

class consultorio
{
public:
    typedef lista_doble<medico>::posicion idMédico; //uso la posicion del medico en la lista como identificador
    consultorio(); //constructor
    void nuevoMédico(medico nuevo); //insertar médico al final de la lista
    void bajaMédico(idMédico id); //dar de baja al médico de la posicion dada
    void espera(idMédico id, paciente nuevo); //añadir paciente a la cola de espera de un médico
    const paciente verTurno(idMédico id); //devuelve el paciente al que que le toca el turno de un respectivo médico
    void atender(idMédico id); //eliminar de la cola de pacientes el paciente atendido
    bool listaEspera(idMédico id); //devuelve falso si no hay pacientes en cola de un respectivo médico y verdadero si los hay
    ~consultorio(); //destructor

private:
    lista_doble<medico> listaMédicos; //tenemos una lista de médicos, es decir, de colas
};

consultorio::consultorio() {};

void consultorio::nuevoMédico(medico nuevo){
    listaMédicos.insertar(nuevo, listaMédicos.fin());
}

void consultorio::bajaMédico(idMédico id){
    listaMédicos.eliminar(id);
}

void consultorio::espera(idMédico id, paciente nuevo){
    listaMédicos.elemento(id).pacientes.push(nuevo);
}

const paciente consultorio::verTurno(idMédico id){
    return listaMédicos.elemento(id).pacientes.frente();
}


void consultorio::atender(idMédico id){
    listaMédicos.elemento(id).pacientes.pop();
}

inline bool consultorio::listaEspera(idMédico id){
    return listaMédicos.elemento(id).pacientes.vacia();
}

consultorio::~consultorio(){
    lista_doble<medico>::posicion p = listaMédicos.primera(); //declaro posicion auxiliar para recorrer la lista
    while(p != listaMédicos.fin()){ //mientras no sea el final de la lista, borrar la cola de cada médico
        listaMédicos.elemento(p).pacientes.~Cola();
        p = p->sig; //o p=listaMédicos.siguiente(p)
    }
    
    listaMédicos.~lista_doble(); //borrar lista de médicos
}

#endif