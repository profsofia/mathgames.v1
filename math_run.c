#include "./juegos.h"

void math_run(void)
{
	short numero = 0;
	short total = 0;
	short veces = 3;
	short respuesta_jugador = 0;
	short i;
	
	printf("\n\t### NVL 1 ###\n");
	
	for (i = 0; i < veces; i++)
	{
		numero = (rand() % 201) - 100;
		total += numero;
		
		printf("#1\t --> %hd", numero);
		fflush(stdout);
		pausa();
		
		printf("\033[2K\r");      
	}
	
	printf("Resultado -> ");
	scanf(" %hd", &respuesta_jugador);
	
	if (respuesta_jugador == total)
	{
		printf("\n%hd es CORRECTO\n", respuesta_jugador);
	}
	else
	{
		printf("\n-> %hd es incorrecto, el total es -> %hd\n", respuesta_jugador, total);
	}
	
	esperar_enter();
}
