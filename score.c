// score.c

#include "score.h" 
#include "utils.h" // ¡Necesario para las constantes ANSI y esperar_enter()!

// -----------------------------------------------------------------------------
// 1. Guardar el Puntaje (Escritura en archivo de texto)
// -----------------------------------------------------------------------------
void save_score_to_file(const char *name, int final_score) {
	// Abre el archivo en modo "append" ('a'). Crea el archivo si no existe.
	FILE *file = fopen(SCORE_FILE, "a"); 
	
	if (file == NULL) {
		// Usamos el color ROJO para los mensajes de error
		printf("\n%s[ERROR] No se pudo abrir el archivo de puntajes para guardar (%s).%s\n", 
			   ANSI_COLOR_RED, SCORE_FILE, ANSI_COLOR_RESET);
		return;
	}
	
	fprintf(file, "%s %d\n", name, final_score);
	
	fclose(file);
}

// -----------------------------------------------------------------------------
// 2. Función de Comparación (Para usar con qsort)
// -----------------------------------------------------------------------------
int compare_scores(const void *a, const void *b) {
	UserScore *scoreA = (UserScore *)a;
	UserScore *scoreB = (UserScore *)b;
	
	// Retorna la diferencia. (B - A) da orden descendente
	return (scoreB->score - scoreA->score);
}

// -----------------------------------------------------------------------------
// 3. Mostrar la Tabla de Clasificación (Lectura, Ordenamiento y Presentación)
// -----------------------------------------------------------------------------
void display_leaderboard() {
	FILE *file = fopen(SCORE_FILE, "r");
	
	// CASO DE ERROR 1: El archivo no existe o no se puede abrir
	if (file == NULL) {
		printf("\n%s--- TABLA DE CLASIFICACIÓN ---%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
		printf("Aún no hay puntajes para mostrar. ¡Sé el primero!\n");
		esperar_enter(); 
		return;
	}
	
#define MAX_RECORDS 100
	UserScore scores_array[MAX_RECORDS];
	int num_scores = 0;
	
	char temp_name[MAX_NAME_LENGTH];
	int temp_score;
	
	int scan_result = fscanf(file, " %s %d", temp_name, &temp_score);
	
	// Leer todos los registros hasta el final del archivo (EOF)
	while (scan_result == 2 && num_scores < MAX_RECORDS) 
	{
		strcpy(scores_array[num_scores].name, temp_name);
		scores_array[num_scores].score = temp_score;
		
		num_scores++;
		
		scan_result = fscanf(file, " %s %d", temp_name, &temp_score);
	}
	
	fclose(file);
	
	// CASO DE ERROR 2: El archivo existe, pero está vacío
	if (num_scores == 0) {
		printf("\n%s--- TABLA DE CLASIFICACIÓN ---%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
		printf("El archivo está vacío. ¡A jugar!\n");
		esperar_enter();
		return;
	}
	
	// Ordenar el vector usando qsort
	qsort(scores_array, num_scores, sizeof(UserScore), compare_scores);
	
	// Mostrar el ranking (Top 10)
	printf("\n========================================\n");
	// Usamos el color amarillo para el título y lo reseteamos
	printf("%s TABLA DE CLASIFICACIÓN (TOP 10) %s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
	printf("========================================\n");
	// Usamos el color azul para los encabezados
	printf(" %sPUESTO | PUNTUACIÓN | JUGADOR%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
	printf("----------------------------------------\n");
	
	int limit = (num_scores < 10) ? num_scores : 10;
	
	for (int i = 0; i < limit; i++) {
		// Coloreamos el puntaje en amarillo y el nombre en verde
		printf(" %6d | %s%10d%s | %s%s%s\n", 
			   i + 1, 
			   ANSI_COLOR_YELLOW, scores_array[i].score, ANSI_COLOR_RESET,
			   ANSI_COLOR_GREEN, scores_array[i].name, ANSI_COLOR_RESET);
	}
	printf("========================================\n");
	
	// Pausa FINAL (SOLO UNA VEZ)
	esperar_enter();
}
