#include "./utils.h"

void configurar_consola(void)
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif
}

void limpiar_pantalla(void)
{
	system(CLEAR);
}
