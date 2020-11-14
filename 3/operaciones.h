#ifndef OPERACIONES
#define OPERACIONES
#include "polinom.h"

//cabecera: polinomio operator+(const polinomio &a, const polinomio &b)
//precondicion: polinomios inicializados
//postcondicion: devuelve la suma de ambos polinomios
polinomio operator+(const polinomio a, const polinomio b);

//cabecera: polinomio operator-(const polinomio &a, const polinomio &b)
//precondicion: polinomios inicializados
//postcondicion: devuelve la resta de ambos polinomios
polinomio operator-(const polinomio a, const polinomio b);

//cabecera: polinomio operator*(const polinomio &a, const polinomio &b)
//precondicion: polinomios inicializados
//postcondicion: devuelve el producto de ambos polinomios
polinomio operator*(const polinomio a, const polinomio b);


//cabecera: polinomio derivada(const polinomio &a)
//precondicion: polinomio inicializado
//postcondicion: devuelve la derivada del polinomio
polinomio derivada(const polinomio a);


#endif