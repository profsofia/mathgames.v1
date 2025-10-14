#include "./juegos.h"

void math_fast(void)
{
	short aciertos = 0;
	short termino1, termino2, respuesta_jugador;
	short total = 0;
	short tiempo_restante = TIEMPO;
	short tiempo_recorrido;
	short se_ingreso_respuesta = 0;
	
	time_t guarda_tiempo = time(NULL);
	
	printf("\n\t### NVL 1 ###\n");
	
	while (tiempo_restante > 0)
	{
		total = 0;
		termino1 = (rand() % 101) - 50;
		termino2 = (rand() % 101) - 50;
		total += termino1 + termino2;
		se_ingreso_respuesta = 0;
		
		printf("\n\n-----------------------------------------------------");
		printf("\n#1 --> (%hd) + (%hd) \n\n", termino1, termino2);
		
		while (tiempo_restante > 0)
		{
			tiempo_recorrido = (short)(time(NULL) - guarda_tiempo);
			tiempo_restante = TIEMPO - tiempo_recorrido;
			
			printf("\rTiempo restante >> %hd >> resultado -> ", tiempo_restante);
			fflush(stdout);
			
			if (_kbhit())
			{
				se_ingreso_respuesta = 1;
				break;
			}
		}
		
		if (se_ingreso_respuesta)
		{
			if (tiempo_restante <= 0)
			{
				printf("\nSe acabo el tiempo..");
				break;
			}
			printf("\n\nIngrese su resultado --> ");
			scanf(" %hd", &respuesta_jugador);
			
			if (respuesta_jugador == total)
			{
				aciertos++;
			}
			else
			{
				printf("\nResultado incorrecto, era -> %hd\n", total);
				break;
			}
		}
		else
		{
			printf("\nSe acabo el tiempo..");
			break;
		}
	}
	printf("\n\n-----------------------------------------------------");
	printf("\nTotal de aciertos: %hd\n", aciertos);
	esperar_enter();
}
