#include "./compat.h"

#ifdef _WIN32
void pausa() { Sleep(3000); }
#else
void pausa() { sleep(3); }

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

char leer_tecla(void)
{
#ifdef _WIN32
	char tecla = _getch();
	if (tecla == '\r')
	{
		tecla = '\n';
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

void esperar_enter(void)
{
	printf("\n\nPresione ENTER para volver al menú principal...");
	while (leer_tecla() != '\n');
}
