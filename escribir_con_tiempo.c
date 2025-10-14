#include "./juegos.h"

void escribir_con_tiempo(short resultado_total)
{
	char buffer[16] = {0};
	short pos = 0;
	short tiempo_restante = TIEMPO;
	time_t inicio_tiempo = time(NULL);
	
	printf("\n--> Escriba el resultado antes de que se acabe el tiempo <--\n");
	
	while (tiempo_restante >= 0)
	{
		printf("\rTiempo restante >> %hd seg >> Resultado -> %s", tiempo_restante, buffer);
		fflush(stdout);
		
		time_t inicio_segundo = time(NULL);
		while (time(NULL) - inicio_segundo < 1)
		{
			if (_kbhit())
			{
				char c = leer_tecla();
				
				if (c == '\n') {
					buffer[pos] = '\0';
					short respuesta_jugador = (short)atoi(buffer);
					
					if (respuesta_jugador == resultado_total) {
						printf("\n\n-> %hd es CORRECTO\n", respuesta_jugador);
					} else {
						printf("\n\n-> %hd es incorrecto.", respuesta_jugador);
						printf("\nEl resultado era -> %hd\n", resultado_total);
					}
					esperar_enter();
					return;
				}
				else if ((c == '\b' || c == 127) && pos > 0) {
					buffer[--pos] = '\0';
				}
				else if ((c >= '0' && c <= '9') || c == '-') {
					if (pos < (short)(sizeof(buffer) - 1)) {
						buffer[pos++] = c;
						buffer[pos] = '\0';
					}
				}
				
				printf("\rTiempo restante >> %hd seg >> Resultado -> %s   ", tiempo_restante, buffer);
				fflush(stdout);
			}
		}
		
		tiempo_restante = TIEMPO - (short)(time(NULL) - inicio_tiempo);
	}
	
	printf("\n\n Se acabó el tiempo..\n");
	printf("El resultado era -> %hd\n", resultado_total);
	esperar_enter();
}
