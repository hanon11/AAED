// Clase para cronometrar.

#ifndef CRONOMETRO_H_ 
#define CRONOMETRO_H_

#include <ctime>
using std::clock;
using std::clock_t;

const double pps = CLOCKS_PER_SEC;

class cronometro {
public:
  cronometro(): activo(false) {}
  void activar() { activo = true; t0 = clock(); }
  void parar() { if (activo) { t1 = clock(); activo = false; } }
  double tiempo() const { return ((activo ? clock() : t1) - t0) / pps; }
private:
  bool activo;	   // Estado de actividad del cronómetro.
  clock_t t0, t1;  // Tiempos inicial y final.
};

// Notas:
//
// La función clock() devuelve el tiempo en unas unidades llamadas
// «pulsos». Para convertir el tiempo a segundos es necesario dividir
// por el número de pulsos por segundo. Esta cantidad aparece definida
// en la macro CLOCKS_PER_SEC cuyo tipo puede ser entero o de coma
// flotante y que mantenemos en pps, que es de tipo double. Si
// queremos hacer explícita una posible conversión de CLOCKS_PER_SEC a
// double podemos modelar el tipo de tres formas:
//
// 1. Como en C: (double)CLOCKS_PER_SEC.
// 2. Con un constructor: double(CLOCKS_PER_SEC).
// 3. Al estilo de C++, en este caso: static_cast<double>(CLOCKS_PER_SEC).

#endif
