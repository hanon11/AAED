#include <algorithm>  //std:swap, std::min_element
#include "1.h"

static void burbujea(int* i, int* j);
static void inserta(int* i, int* j);

// Ordenación por intercambio directo del rango [p, f).

void ordenacion_intercambio(int* p, int* f)
{
  for (int* i = p; i != f - 1; ++i)
    burbujea(i, f);
}

// Desciende el mínimo del rango [i, j) 
// hasta la posición i.
static void burbujea(int* i, int* j)
{
  for (int* k = j - 1; k != i; --k) {
    if (*k < *(k - 1))
      std::swap(*k, *(k - 1));
  }
}

// Ordenación por selección directa del rango [p, f).

void ordenacion_seleccion(int* p, int* f)
{
  for (int* i = p; i != f - 1; ++i) {
    int* p = std::min_element(i, f); // pos. min. del rango [i, f)
    std::swap(*i, *p);
  }
} 

// Ordenacion por insercion directa del rango [p, f).

void ordenacion_insercion(int* p, int* f)
{
  for (int* i = p + 1; i != f; ++i)
    inserta(p, i);
}

// Insercion ordenada de *j en el rango ordenado [i, j - 1]
static void inserta(int* i, int* j)
{
  int x = *j;
  while (j != i && x < *(j - 1)) {
    *j = *(j - 1);
    --j;
  }
  *j = x;
}

