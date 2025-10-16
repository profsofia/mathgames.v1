#ifndef UTILS_H
#define UTILS_H

// Códigos de Colores ANSI
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m" // Código para restaurar el color predeterminado

#include "compat.h"

// Funciones utilitarias generales
void limpiar_pantalla(void);
void configurar_consola(void);

#endif
