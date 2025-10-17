

#include "./menu.h"
#include "./utils.h" 

void menu_principal(char *nombre)
{
	system(CLEAR);
	printf("\n%s===========================================================%s\n", 
		   ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
	
	printf("\n\t %s[ BIENVENIDO -> %s <- ]%s \n\n", 
		   ANSI_COLOR_YELLOW, nombre, ANSI_COLOR_RESET);
	
	printf("%s===========================================================%s\n\n", 
		   ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
	

	printf(" %s1 = MathRun%s   ->  Memoriza y suma\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
	printf(" %s2 = MathJump%s  ->  Resuelve antes de que se acabe el tiempo\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
	printf(" %s3 = MathFast%s  ->  Resuelve la mayor cantidad posible\n", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
	
	printf("\n %s4 = Ranking%s   ->  Muestra la tabla de los mejores puntajes\n", ANSI_COLOR_MAGENTA, ANSI_COLOR_RESET);
	
	printf("-----------------------------------------------------------\n");

	printf(" %sx = Salir%s     ->  Terminar juego\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
	
	printf("===========================================================\n");
	printf("%s\nSelecciona una opcion -> %s", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
	
}
