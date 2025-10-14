#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "usuarios.h"
#include "reportes.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void mostrarMenuPrincipal() {
	int opcion;
	
	do {
		system(CLEAR);
		printf("\n=== MENU PRINCIPAL ===\n");
		printf("1. Gestionar usuarios\n");
		printf("2. Gestionar reportes\n");
		printf("3. Salir\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &opcion);
		
		switch(opcion) {
		case 1:
			gestionarUsuarios();
			break;
		case 2:
			gestionarReportes();
			break;
		case 3:
			printf("Saliendo...\n");
			break;
		default:
			printf("Opcion invalida.\n");
		}
		
		if(opcion != 3) {
			printf("\nPresione ENTER para continuar...");
			getchar(); getchar();
		}
		
	} while(opcion != 3);
}

