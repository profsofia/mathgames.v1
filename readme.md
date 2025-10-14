#  MathGames en C

Un programa de consola en C que pone a prueba la **memoria y rapidez mental del jugador** mediante tres minijuegos matemáticos.  
Diseñado para ejecutarse tanto en **Windows como en Linux/macOS**, usando técnicas de control de consola y detección de teclas en tiempo real.

---

##  Objetivo del programa

El propósito de esta aplicación es practicar y evaluar la **agilidad mental** del usuario mediante operaciones aritméticas simples y control de tiempo.  
Además, busca demostrar el uso de:
- Entrada de teclado no bloqueante (`_kbhit()` y `getchar()`).
- Control de tiempo con la librería `time.h`.
- Compatibilidad multiplataforma.
- Limpieza de pantalla y pausas adaptadas al sistema operativo.

---

##  Juegos incluidos

### 1.  MathRun — *“Memorizá y sumá”*
Se muestran varios números durante unos segundos.  
El jugador debe recordar y escribir su suma total.

- Dificultad: Baja  
- Habilidades: memoria y concentración  
- Tiempo entre números: 3 segundos  

---

### 2.  MathJump — *“Resuelve antes de que acabe el tiempo”*
El programa muestra una ecuación (tres sumandos).  
El jugador debe escribir el resultado **antes de que se acabe el tiempo (20 segundos)**.  
La entrada se procesa en tiempo real, sin detener el cronómetro.

- Dificultad: Media  
- Habilidades: cálculo rápido, manejo de presión  
- Tiempo total: 20 segundos  

---

### 3.  MathFast — *“Cálculo veloz”*
Durante 20 segundos, el jugador debe resolver la mayor cantidad posible de operaciones simples.  
Si se equivoca, el juego termina.

- Dificultad: Media-alta  
- Habilidades: velocidad, precisión, atención  
- Condición de fin: error o tiempo agotado  

---

##  Estructura del código

El programa está dividido en **funciones modulares** dentro del mismo archivo `main.c`:

| Función | Descripción |
|----------|--------------|
| `main()` | Controla el flujo general del programa. Pide el nombre del jugador, muestra el menú y ejecuta los juegos según la tecla presionada. |
| `menu_principal(char *nombre)` | Muestra el menú de selección con el nombre del jugador. |
| `leer_tecla()` | Lee una tecla sin necesidad de presionar ENTER. Usa `_getch()` en Windows y `termios` en Linux/macOS. |
| `_kbhit()` | Detecta si una tecla fue presionada sin bloquear el flujo. Implementado manualmente en Linux. |
| `pausa()` | Detiene la ejecución unos segundos. Implementación dependiente del sistema operativo. |
| `esperar_enter()` | Espera que el usuario presione ENTER antes de continuar. |
| `math_run()` | Implementa el primer juego (memoria). Muestra números y pide su suma. |
| `math_jump(short *resultado_total)` | Genera una ecuación aleatoria y guarda el resultado correcto. |
| `escribir_con_tiempo(short resultado_total)` | Muestra un temporizador y permite ingresar la respuesta en tiempo real. |
| `math_fast()` | Implementa el tercer juego. Calcula cuántas sumas correctas puede resolver el jugador antes de que se acabe el tiempo. |

---

##  Compatibilidad

El programa fue diseñado para funcionar correctamente en:

-  **Windows** (usa `conio.h`, `windows.h`, y comando `cls`)
- **Linux / macOS** (usa `termios`, `unistd.h`, y comando `clear`)

Se manejan condicionales con `#ifdef _WIN32` para adaptar las funciones de:
- Limpieza de pantalla (`CLEAR`)
- Pausa (`Sleep()` / `sleep()`)
- Lectura no bloqueante (`_kbhit()`)

---

##  Compilación

### En Windows
Compilar con:
```bash
gcc main.c -o mathgames.exe


Ejecutar con:

mathgames.exe

En Linux / macOS

Compilar con:

gcc main.c -o mathgames


Ejecutar con:

./mathgames

Conceptos técnicos utilizados

E/S no bloqueante: permite detectar teclas sin detener el flujo del programa.

Temporizadores con time_t: se usan para medir segundos y limitar el tiempo de juego.

ANSI escape codes: para limpiar líneas en pantalla sin borrar todo (\033[2K\r).

Semillas aleatorias (srand(time(NULL))): generan operaciones diferentes cada vez.

Punteros: usados para pasar resultados entre funciones (short *resultado_total).

-------- Uso rápido-----------

Ejecutá el programa.

Escribí tu nombre (máximo 20 caracteres).

Elegí una opción del menú:

1 → MathRun (memorizá y sumá)

2 → MathJump (resolvé antes del tiempo)

3 → MathFast (resolvé la mayor cantidad posible)

x → salir del programa

Seguí las instrucciones que aparecen en pantalla.

Presioná ENTER cuando el juego te lo indique para volver al menú principal.

Repetí o cambiá de juego las veces que quieras.
 Tip: el programa muestra y borra números dinámicamente, así que prestá atención —no hay segundas oportunidades.

-----------Posibles mejoras futuras------

## Guardar puntajes en un archivo binario.

## Crear un historial por jugador.

## Implementar niveles de dificultad progresiva.

## Agregar un sistema de ranking o top 10.

## Mostrar los resultados con colores en consola.

Desarrollado como práctica de programación en C,
con enfoque en control de tiempo, E/S en consola y lógica de juegos.
