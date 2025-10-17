#include "./juegos.h"
#include "./utils.h" // Necesario para colores, pausa(), y funciones de audio

void math_run(void)
{
	short numero = 0;
	short total = 0;
	short veces = 3;
	short respuesta_jugador = 0;
	short i;
	
	// Titulo del Nivel con Color
	printf("\n%s\t### NIVEL 1 ###%s\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
	printf("-----------------------------------------\n");
	
	
	for (i = 0; i < veces; i++)
	{
		numero = (rand() % 201) - 100;
		total += numero;
		
		// Muestra el numero destacado
		printf("%sTERMINO %hd: %s%hd%s", 
			   ANSI_COLOR_YELLOW, i + 1, ANSI_COLOR_GREEN, numero, ANSI_COLOR_RESET);
		fflush(stdout);
		pausa();
		
		// Limpia la linea para el siguiente termino
		printf("\033[2K\r");
	}
	
	// Linea final antes de pedir la respuesta
	printf("\n%s=========================================%s\n", 
		   ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
	
	printf("Resultado total -> ");
	scanf(" %hd", &respuesta_jugador);
	
	
	if (respuesta_jugador == total)
	{
		// Respuesta Correcta: Color Verde y Sonido de Éxito
		printf("\n%s>>> %hd es CORRECTO! Felicitaciones! <<<%s\n", 
			   ANSI_COLOR_GREEN, respuesta_jugador, ANSI_COLOR_RESET);
		play_sound_correct(); 
	}
	else
	{
		// Respuesta Incorrecta: Color Rojo y Sonido de Error
		printf("\n%s>>> %hd es INCORRECTO. El total era -> %hd%s\n", 
			   ANSI_COLOR_RED, respuesta_jugador, total, ANSI_COLOR_RESET);
		play_sound_error();
	}
	
	esperar_enter();
}
