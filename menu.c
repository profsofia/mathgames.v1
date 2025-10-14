#include "./menu.h"

void menu_principal(char *nombre)
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
