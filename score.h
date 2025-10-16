// score.h

#ifndef SCORE_H
#define SCORE_H

#include <stdio.h>
#include <stdlib.h> // Para qsort
#include <string.h> // Para strncpy, strcmp, etc.

// Constantes
#define MAX_NAME_LENGTH 21
#define SCORE_FILE "highscores.txt" // Nombre del archivo de texto para el ranking

// Estructura para el puntaje de un usuario
typedef struct {
	char name[MAX_NAME_LENGTH];
	int score;
} UserScore;

// Declaración de funciones (Prototipos)
void save_score_to_file(const char *name, int final_score);
void display_leaderboard();

// Función de comparación para qsort (necesaria para ordenar)
int compare_scores(const void *a, const void *b);

#endif // SCORE_H
