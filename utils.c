#include "./utils.h"

#include <windows.h> // Necesario para la API de Windows
#include <mmsystem.h> // Necesario para PlaySound()

// Nombre del archivo para la respuesta correcta (Debes obtener o crear este archivo)
#define WIN_SOUND_FILE   TEXT("WIN.wav") 
// Nombre del archivo para la respuesta incorrecta (Usamos el que subiste)
#define LOSE_SOUND_FILE  TEXT("LOSE.wav")
void configurar_consola(void)
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif
}

void play_sound_correct(void) {
	// Reproduce el sonido de éxito de forma asíncrona (no bloquea el juego)
	// Usamos TEXT() para compatibilidad con Unicode en Windows.
	PlaySound(WIN_SOUND_FILE, NULL, SND_FILENAME | SND_ASYNC);
}

void play_sound_error(void) {
	// Reproduce el sonido de error de forma asíncrona
	PlaySound(LOSE_SOUND_FILE, NULL, SND_FILENAME | SND_ASYNC);
}

void limpiar_pantalla(void)
{
	system(CLEAR);
}
