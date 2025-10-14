#include "./menu.h"
#include "./juegos.h"
#include "./utils.h"

int main(void)
{
	configurar_consola();
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
		menu_principal(nombre);
		tecla_presionada = leer_tecla();
		
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
				math_jump(resultado_total);
				escribir_con_tiempo(total);
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
				math_fast();
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
