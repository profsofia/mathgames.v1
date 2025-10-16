#include "./juegos.h"
#include "./utils.h" // Asegúrate de que esta inclusión esté aquí y sea correcta
#include <time.h>    // Necesario para time()

// Asumo que TIEMPO y _kbhit() están definidos/disponibles
// Asumo que ANSI_COLOR_XXX y play_sound_XXX están en utils.h/utils.c

void math_fast(void)
{
	short aciertos = 0;
	short termino1, termino2, respuesta_jugador;
	short total = 0;
	// Debes tener TIEMPO definido en un header o aquí
	short tiempo_restante = TIEMPO; 
	short tiempo_recorrido;
	short se_ingreso_respuesta = 0;
	
	
	time_t guarda_tiempo = time(NULL);
	
	
	printf("\n%s\t### NVL 1 ###%s\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
	
	
	while (tiempo_restante > 0)
	{
		total = 0;
		termino1 = (rand() % 101) - 50;
		termino2 = (rand() % 101) - 50;
		total += termino1 + termino2;
		se_ingreso_respuesta = 0;
		
		
		printf("\n\n%s-----------------------------------------------------%s", 
			   ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
		printf("\n#1 --> (%hd) + (%hd) \n\n", termino1, termino2);
		
		
		while (tiempo_restante > 0)
		{
			tiempo_recorrido = (short)(time(NULL) - guarda_tiempo);
			tiempo_restante = TIEMPO - tiempo_recorrido;
			
			
			printf("\rTiempo restante >> %s%hd%s >> resultado -> ", 
				   ANSI_COLOR_YELLOW, tiempo_restante, ANSI_COLOR_RESET);
			fflush(stdout);
			
			
			if (_kbhit())
			{
				se_ingreso_respuesta = 1;
				break;
			}
		}
		
		// **********************************************
		// LÓGICA DE VALIDACIÓN CON AUDIO Y COLORES
		// **********************************************
		if (se_ingreso_respuesta)
		{
			if (tiempo_restante <= 0)
			{
				printf("\n%sSe acabo el tiempo..%s", ANSI_COLOR_RED, ANSI_COLOR_RESET);
				// 🔊 SONIDO DE ERROR / FIN DE JUEGO
				play_sound_error(); 
				break;
			}
			printf("\n\nIngrese su resultado --> ");
			scanf(" %hd", &respuesta_jugador);
			
			
			if (respuesta_jugador == total)
			{
				// Acierto
				aciertos++;
				printf("\n%s¡Acierto!%s", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
				// 🔊 SONIDO DE ÉXITO
				play_sound_correct(); 
			}
			else
			{
				// Error
				printf("\n%sResultado incorrecto, era -> %hd%s\n", 
					   ANSI_COLOR_RED, total, ANSI_COLOR_RESET);
				// 🔊 SONIDO DE ERROR
				play_sound_error(); 
				break;
			}
		}
		else
		{
			printf("\n%sSe acabo el tiempo..%s", ANSI_COLOR_RED, ANSI_COLOR_RESET);
			// 🔊 SONIDO DE ERROR / FIN DE JUEGO
			play_sound_error(); 
			break;
		}
		// **********************************************
	}
	printf("\n\n%s-----------------------------------------------------%s", 
		   ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
	printf("\nTotal de aciertos: %s%hd%s\n", ANSI_COLOR_GREEN, aciertos, ANSI_COLOR_RESET);
	esperar_enter();
}
