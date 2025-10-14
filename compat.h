#ifndef COMPAT_H
#define COMPAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#define CLEAR "cls"
void pausa();
#else
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#define CLEAR "clear"
void pausa();
int _kbhit(void);
#endif

#define TIEMPO 20

// Funciones de compatibilidad
char leer_tecla(void);
void esperar_enter(void);

#endif
