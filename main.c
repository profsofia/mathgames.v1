// main.c (inicio)

#include "./menu.h"
#include "./juegos.h"
#include "./utils.h"
#include "./score.h" 



int main(void)
{
	configurar_consola();
	srand(time(NULL));
	
	short total = 0;
	short *resultado_total = &total;
	//char tecla_presionada;
	char tecla_presionada = '\0';
	char nombre_jugador[21];
	char *nombre = nombre_jugador;

	system(CLEAR); // Limpiamos la pantalla al inicio para mayor impacto
	
	printf("%s=================================================%s\n", 
		   ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
	
	printf("%s|                MATH GAMES V1.0              |%s\n", 
		   ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
	
	printf("%s=================================================%s\n", 
		   ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
	
	printf("\n");
	printf("%s>>> Pone a prueba tu velocidad mental y tus calculos! <<<%s\n",
		   ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
	
	printf("\n-------------------------------------------------\n");
	printf("Ingresa tu nombre de usuario (20 caracteres max): ");

	if (fgets(nombre_jugador, sizeof(nombre_jugador), stdin) != NULL) {
		// Eliminar el salto de línea que agrega fgets 
		nombre_jugador[strcspn(nombre_jugador, "\n")] = 0;
	} else {
		// Manejo de error si no se pudo leer el nombre
		strcpy(nombre_jugador, "Jugador_Anonimo");
	}

	
	do
	{
		menu_principal(nombre);
		tecla_presionada = leer_tecla();
		if (tecla_presionada == '\n') {
			tecla_presionada = leer_tecla();
		}
		
		switch(tecla_presionada)
		{
		case '1':
			system(CLEAR);
			printf("\nJuego de memoria > se revelaran por unos segundos, los términos individualmente.\n");
			printf("Tu objetivo > recordar los numeros que se revelaron, para sumarlos y dar con el resultado total.\n");
			printf("\nENTER = continuar");
			printf("\nv = volver al menú principal");
			printf("\n-> ");
			
			tecla_presionada = leer_tecla();
			if (tecla_presionada == 'v')
			{
				break;
			}
			else if (tecla_presionada == '\n') {
				system(CLEAR);
				math_run();
			}
			else
			{
				printf("Opción inválida.\n");
				esperar_enter();
			}
			break;
			
		case '2':
			system(CLEAR);
			printf("\nPiensa rápido > trendrás que reslver un ecuación matemática antes de que se acabe el tiempo.\n");
			printf("\nENTER = continuar");
			printf("\nv = volver al menú principal");
			printf("\n-> ");
			
			tecla_presionada = leer_tecla();
			if (tecla_presionada == 'v')
			{
				break;
			}
	
			

			else if (tecla_presionada == '\n') {
				system(CLEAR);
				math_jump(resultado_total); // Esta función actualiza 'total'
				escribir_con_tiempo(total);
				
				if (total > 0) {
					save_score_to_file(nombre, total);
					// Usamos color cian para el mensaje de éxito
					printf("\n%s¡Puntaje %d guardado en el historial de scores!%s\n", 
						   ANSI_COLOR_CYAN, total, ANSI_COLOR_RESET);
				} else {
					// Usamos color rojo para el mensaje de error/puntuación nula
					printf("\n%sNo se guarda el puntaje (es 0 o menos).%s\n", 
						   ANSI_COLOR_RED, ANSI_COLOR_RESET);
				}
			}
			else
			{
				printf("Opción inválida.\n");
				esperar_enter();
			}
			break;
			
		case '3':
			system(CLEAR);
			printf("\nCalculo veloz > Tendras que resolver la mayor cantidad de ejercicios simples en la menor cantidad de tiempo posible.\n");
			printf("\nENTER = continuar");
			printf("\nv = volver al menú principal");
			printf("\n-> ");
			
			tecla_presionada = leer_tecla();
			if (tecla_presionada == 'v')
			{
				break;
			}
			else if (tecla_presionada == '\n') {
				system(CLEAR);
				math_fast(nombre); 
			}
			else
			{
				printf("Opción inválida.\n");
				esperar_enter();
			}
			break;
	
			
	    case '4':		
			system(CLEAR);
			printf("\nScores segun usuario\n");
			printf("\nENTER = continuar");
			printf("\nv = volver al menú principal");
			printf("\n-> ");
			
			tecla_presionada = leer_tecla();
			if (tecla_presionada == 'v')
			{
				break;
			}
			else if (tecla_presionada == '\n') {
				system(CLEAR);
				display_leaderboard(); 
			}
			else
			{
				printf("Opción inválida.\n");
				esperar_enter();
			}
			break;
			
		case 'x':
			system(CLEAR);
			printf("Gracias por probar el programa!");
			break;
			
		default:
			printf("\nEscriba solo las opciones validas, porfavor\n");
			esperar_enter();
			break;
		}
	} while (tecla_presionada != 'x');
	
	return 0;
}
