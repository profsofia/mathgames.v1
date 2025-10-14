#include "./juegos.h"

void math_jump(short *resultado_total)
{
	short termino1 = 0;
	short termino2 = 0;
	short termino3 = 0;
	short total = 0;
	
	printf("\n\t### NVL 1 ###\n");
	printf("Escriba el resultado antes de que acabe el tiempo (15 sec)\n");
	
	termino1 = (rand() % 201) - 100;
	termino2 = (rand() % 201) - 100;
	termino3 = (rand() % 201) - 100;
	total += termino1 + termino2 + termino3;
	
	printf("\n#1 --> ( %hd ) + ( %hd ) + ( %hd )\n", termino1, termino2, termino3);
	
	*resultado_total = total;
}
