#ifndef JUEGOS_H
#define JUEGOS_H

#include "compat.h"

// Prototipos de funciones de juegos
void math_run(void);
void math_jump(short *resultado_total);

void math_fast(const char *nombre); // <-- Nuevo: Recibe el nombre
void escribir_con_tiempo(short resultado_total);

#endif
