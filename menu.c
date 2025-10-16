#include "./menu.h"
#include "./utils.h"
void menu_principal(char *nombre)

{
	system(CLEAR);
	// Usamos el color verde para el nombre y luego el RESET
	printf("\n\n\t ### Bienvenido -> %s%s%s <- ### \n\n", ANSI_COLOR_GREEN, nombre, ANSI_COLOR_RESET);
	
	printf("===========================================================\n\n");
	printf("1 = MathRun   ->  Memorizá y sumá\n");
	printf("2 = MathJump  ->  Resolvé antes de que se acabe el tiemmpo\n");
	printf("3 = MathFast  ->  Resolvé la mayor cantidad posible\n");
	
	// *************************************************************
	// NUEVA LÍNEA: Agregar la opción 4 para ver el ranking
	// *************************************************************
	printf("4 = Ver Ranking -> Muestra la tabla de los mejores puntajes\n");
	// *************************************************************
	
	printf("-----------------------------------------------------------\n");
	printf("\t\tx = Terminar juego\n\n");
	printf("===========================================================\n");
	printf("\nSeleccione una opcion -> ");
	
}
