// score.c

#include "score.h" // Incluimos nuestra propia cabecera
#include "utils.h" // Incluimos utils.h para usar 'esperar_enter()'

// -----------------------------------------------------------------------------
// 1. Guardar el Puntaje (Escritura en archivo de texto)
// -----------------------------------------------------------------------------
void save_score_to_file(const char *name, int final_score) {
	// Abrir el archivo en modo "append" ('a'). Crea el archivo si no existe.
	FILE *file = fopen(SCORE_FILE, "a"); 
	
	
	if (file == NULL) {
		printf("\n[ERROR] No se pudo abrir el archivo de puntajes para guardar (%s).\n", SCORE_FILE);
		return;
	}
	
	
	// Escribir en el formato: Nombre Puntaje\n
	// Usando fprintf para archivos de texto.
	fprintf(file, "%s %d\n", name, final_score);
	
	
	// Cerrar el archivo
	fclose(file);
}

// -----------------------------------------------------------------------------
// 2. Función de Comparación (Para usar con qsort)
// -----------------------------------------------------------------------------
int compare_scores(const void *a, const void *b) {
	// Casteamos los punteros genéricos a punteros de UserScore
	UserScore *scoreA = (UserScore *)a;
	UserScore *scoreB = (UserScore *)b;
	
	// Retorna la diferencia. (B - A) da orden descendente (mayor puntaje primero)
	return (scoreB->score - scoreA->score);
}

// -----------------------------------------------------------------------------
// 3. Mostrar la Tabla de Clasificación (Lectura, Ordenamiento y Presentación)
// -----------------------------------------------------------------------------
void display_leaderboard() {
	FILE *file = fopen(SCORE_FILE, "r"); // Abrir en modo "read"
	
	// CASO DE ERROR 1: El archivo no existe o no se puede abrir
	if (file == NULL) {
		printf("\n--- TABLA DE CLASIFICACIÓN ---\n");
		printf("Aún no hay puntajes para mostrar. ¡Sé el primero!\n");
		esperar_enter(); // <--- SOLUCIÓN: Pausar en la ruta de error
		return;
	}
	
#define MAX_RECORDS 100 // Límite de puntajes a leer en memoria
	UserScore scores_array[MAX_RECORDS];
	int num_scores = 0;
	
	char temp_name[MAX_NAME_LENGTH];
	int temp_score;
	
	// Usamos fscanf para leer los datos del archivo de texto: "Nombre Puntaje"
	int scan_result = fscanf(file, " %s %d", temp_name, &temp_score);
	
	// Leer todos los registros hasta el final del archivo (EOF)
	while (scan_result == 2 && num_scores < MAX_RECORDS) 
	{
		// Copiar los datos leídos a la estructura en el array
		strcpy(scores_array[num_scores].name, temp_name);
		scores_array[num_scores].score = temp_score;
		
		num_scores++;
		
		// Intentar leer el siguiente registro
		scan_result = fscanf(file, " %s %d", temp_name, &temp_score);
	}
	
	fclose(file);
	
	// CASO DE ERROR 2: El archivo existe, pero está vacío
	if (num_scores == 0) {
		printf("\n--- TABLA DE CLASIFICACIÓN ---\n");
		printf("El archivo está vacío. ¡A jugar!\n");
		esperar_enter(); // <--- SOLUCIÓN: Pausar en la ruta de error
		return;
	}
	
	// Ordenar el vector usando qsort (librería <stdlib.h>)
	qsort(scores_array, num_scores, sizeof(UserScore), compare_scores);
	
	// Mostrar el ranking (Top 10)
	printf("\n========================================\n");
	printf("TABLA DE CLASIFICACIÓN (TOP 10)\n");
	printf("========================================\n");
	printf(" PUESTO | PUNTUACIÓN | JUGADOR\n");
	printf("----------------------------------------\n");
	
	int limit = (num_scores < 10) ? num_scores : 10;
	
	for (int i = 0; i < limit; i++) {
		printf(" %6d | %10d | %s\n", i + 1, scores_array[i].score, scores_array[i].name);
	}
	printf("========================================\n");
	
	// Pausa para el caso de éxito
	esperar_enter();
}
