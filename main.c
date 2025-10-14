/*
* Rejisto de usuarios y un top de los mejores que han jugado. Con archivos lo hacemos.
* Tambien usariamo sarchivos dinamicos para agregar un archivo con el historial personal de cada jugador.


? Acertijos logicos, con opciones
? Encontrar el pocentaje
? Esta funcion devuelve...
? Compuertas logicas
? Un juego con archivos binarios


*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define TIEMPO 20


#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#define CLEAR "cls"
void pausa() { Sleep(3000); }
#else
#include <unistd.h>
#include <sys/select.h>
#define CLEAR "clear"
void pausa() { sleep(3); }


// Función para simular kbhit() en Linux/macOS
int _kbhit(void) {
	struct timeval tv;
	fd_set fds;
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);
	select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
	return FD_ISSET(STDIN_FILENO, &fds);
}
#endif
// --- Fin de la seccion de compatibilidad ---


char leer_tecla()
{
#ifdef _WIN32
	char tecla = _getch();
	if (tecla == '\r')
	{
		tecla = '\n';   // Normalizamos ENTER a '\n' también en Windows
	}
	return tecla;
#else
	struct termios oldt, newt;
	char tecla;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	tecla = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return tecla;
#endif
}


void menu_principal( char * );
void esperar_enter();
void math_jump( short * );
void escribir_con_tiempo( short );
void math_run(); // .Juego 1
//void math_jump( short * ); // .Juego 2
void math_fast(); // .Juego 3


int main(void)
{
	SetConsoleOutputCP(CP_UTF8);  // Activar UTF-8
	srand(time(NULL));
	
	
	short total = 0;
	short *resultado_total = &total;
	char tecla_presionada;
	char nombre_jugador[21];
	char *nombre = nombre_jugador;
	
	
	printf("Ingrese su nombre, jugador (20 caracteres max)\n");
	printf("--> ");
	scanf(" %20[^ÁÉÍÓÚáéíóú\n]s", nombre_jugador);
	nombre = nombre_jugador;
	
	
	do
	{
		menu_principal( nombre );
		tecla_presionada = leer_tecla();
		
		
		switch(tecla_presionada)
		{
		case '1':
		{
			system(CLEAR);
			printf("\nJuego de memoria > se revelaran por unos segundos, los términos individualmente.\n");
			printf("Tu objetivo > recordar los numeros que se revelaron, para sumarlos y dar con el resultado total.\n");
			printf("\nENTER = continuar");
			printf("\nx = volver al menú principal");
			printf("\n-> ");
			
			
			tecla_presionada = leer_tecla();
			if (tecla_presionada == 'v')
			{
				break;
			}
			else if (tecla_presionada == '\n') {   // ENTER funciona igual en todos los SO
				system(CLEAR);
				math_run();
			}
			else
			{
				printf("Opción inválida.\n");
				esperar_enter();
			}
		}
			break;
			
			
		case '2':
			{
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
				else if (tecla_presionada == '\n') {   // ENTER funciona igual en todos los SO
					system(CLEAR);
					math_jump( resultado_total );
					escribir_con_tiempo( total );
				}
				else
				{
					printf("Opción inválida.\n");
					esperar_enter();
				}
			}
			break;
			
			
		case '3':
			{
				system(CLEAR);
				printf("\nCalculo veloz > Tendras que resolver la mayor cantidad de ejercicios simples en la menor cantidad de tiempo posible.\n");
				printf("\nENTER = continuar");
				printf("\nx = volver al menú principal");
				printf("\n-> ");
				
				
				tecla_presionada = leer_tecla();
				if (tecla_presionada == 'v')
				{
					break;
				}
				else if (tecla_presionada == '\n') {   // ENTER funciona igual en todos los SO
					system(CLEAR);
					math_fast();
				}
				else
				{
					printf("Opción inválida.\n");
					esperar_enter();
				}
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
	}while ( tecla_presionada != 'x' );
	
	return 0;
}


void menu_principal( char *nombre )
{
	system(CLEAR);
	printf("\n\n\t ### Bienvenido -> %s <- ### \n\n", nombre);
	printf("===========================================================\n\n");
	printf("1 = MathRun   ->  Memorizá y sumá\n");
	printf("2 = MathJump  ->  Resolvé antes de que se acabe el tiemmpo\n");
	printf("3 = MathFast  ->  Resolvé la mayor cantidad posible\n");
	printf("-----------------------------------------------------------\n");
	printf("\t\tx = Terminar juego\n\n");
	printf("===========================================================\n");
	printf("\nSeleccione una opcion -> ");
}






void esperar_enter()
{
	printf("\n\nPresione ENTER para volver al menú principal...");
	while (leer_tecla() != '\n');
}


void math_run()
{
	short numero = 0;
	short total = 0;
	short veces = 3;
	short respuesta_jugador = 0;
	short i;
	
	
	printf("\n\t### NVL 1 ###\n");
	
	
	for ( i = 0; i < veces; i++)
	{
		numero = (rand() % 201) -100;
		total += numero;
		
		printf("#1\t --> %hd", numero);
		fflush(stdout);
		pausa();
		
		
		printf("\033[2K\r");      
	}
	
	
	printf("Resultado -> ");
	scanf(" %hd", &respuesta_jugador);
	
	
	if ( respuesta_jugador == total )
	{
		printf("\n%hd es CORRECTO\n", respuesta_jugador);
	}
	else
	{
		printf("\n-> %hd es incorrecto, el total es -> %hd\n", respuesta_jugador, total);
	}
	
	
	esperar_enter();    
	
	
	//printf("\nSeleccione:");
	//printf("\nx = volver al menú principal");
	//printf("\nENTER = volver a jugar");
	//scanf(" %c", &opcion);
	
}


void math_jump( short *resultado_total )
{
	short termino1 = 0;
	short termino2 = 0;
	short termino3 = 0;
	short total = 0;
	short i;
	
	
	printf("\n\t### NVL 1 ###\n");
	printf("Escriba el resultado antes de que acabe el tiempo (15 sec)\n");
	termino1 = (rand() % 201) -100;
	termino2 = (rand() % 201) -100;
	termino3 = (rand() % 201) -100;
	total += termino1 + termino2 + termino3;
	
	printf("\n#1 --> ( %hd ) + ( %hd ) + ( %hd )\n", termino1, termino2, termino3);
	
	
	*resultado_total = total;
}


void escribir_con_tiempo( short resultado_total )
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
					return; // salir de la función
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
				
				
				// Mostrar buffer actualizado en tiempo real
				printf("\rTiempo restante >> %hd seg >> Resultado -> %s   ", tiempo_restante, buffer);
				fflush(stdout);
			}
		}
		
		
		tiempo_restante = TIEMPO - (short)(time(NULL) - inicio_tiempo);
	}
	
	
	// ⏳ Tiempo terminado
	printf("\n\n Se acabó el tiempo..\n");
	printf("El resultado era -> %hd\n", resultado_total);
	esperar_enter();
}




// void resultado_mathjump( short resultado_total )
// {

// }


void math_fast()
{
	short aciertos = 0;
	short termino1, termino2, respuesta_jugador;
	short total = 0;
	short tiempo_restante = TIEMPO;
	short tiempo_recorrido;
	short se_ingreso_respuesta;
	
	
	time_t guarda_tiempo = time(NULL);
	
	
	printf("\n\t### NVL 1 ###\n");
	
	while ( tiempo_restante > 0 )
	{
		total = 0;
		termino1 = (rand() % 101) -50;
		termino2 = (rand() % 101) -50;
		total += termino1 + termino2;
		
		
		printf("\n\n-----------------------------------------------------");
		printf("\n#1 --> (%hd) + (%hd) \n\n", termino1, termino2);
		
		
		while ( tiempo_restante > 0 )
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
			if ( tiempo_restante <= 0 )
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
