/* En la programacion, es comun que los
 * prototipos de una funcion sean requeridos
 * por mas de un archivo.c, pero si el archivo
 * de cabecera es incluido mas de una vez,
 * se estaria repitiendo el codigo haciendo
 * que se defina varias veces las mismas
 * variables produciendo un error.
 * Se requeriria entonces incluir el archivo
 * desde un punto especifico, pero ¿donde?
 * resulta casi imposible y poco practico
 * saber dónde es requerido, sobre todo si
 * tienes mil archivos.
 *
 * Se utilizan entonces las directrices
 * #ifndef, #define y #endif. El primero se
 * lee como "si no está definido ..." y
 * funciona basicamente como un if, pero para
 * el preprocesador. Es un truco convertido ya
 * en canon y usado en toda la programacion.
 *
 * Inventas cualquier palabra, aunque
 * conviene que sea el mismo nombre del 
 * archivo. Preguntas si esa palabra no ha
 * sido definida (osea que sea la primera vez
 * que ese archivo es incluido). Entonces la
 * defines, poniendo así un candado para la
 * proxima vez que el archivo quiera ser
 * incluirlo, pues el preprocesador vera que
 * ya fue definida anteriormente e ignorará
 * el resto del codigo hasta donde encuentra
 * #endif
 */
#ifndef MAZO_H
#define MAZO_H

#include <stdint.h> // para int32_t

/* Las definciones es mejor usar
 * mayusculas. Ademas de crean
 * mucho mas especificas, no usar
 * palabras como LIMITE, que
 * resultan poco exolicitas */
#define MAX_LETRAS 50
#define MAX_TARJETAS 50
#define MAX_MAZOS 50

/* Los nuevos tipos se acostumbra
 * definirlos con mayúsculas al
 * principio, ademas de usarse
 * nombres en singular porque lo
 * que se define es algo unitario*/
struct Tarjeta {
	char pregunta[MAX_LETRAS];
	char definicion[MAX_LETRAS];
};

struct Mazo {
	char nombre[MAX_LETRAS];
	struct Tarjeta tarjeta[MAX_TARJETAS];
	int32_t n_tarjetas;
};

/* Ahora las funciones deben recibir como
 * argumentos las variables que eran globales.
 * Como solo reciben copias, no pueden
 * modificar los valores originales. Asi que
 * para estos valores recibiran el apuntador
 * con lo que tendran acceso directo a ellos
 */
void crear_mazo( struct Mazo *_MazoPtr,
		int32_t *_MazosCreados );

/* imprimir_mazos() no requiere modificar
 * ninguno de sus argumentos, por lo que
 * mazos_creados se declara como un entero
 * constante */
void imprimir_mazos( struct Mazo *_MazoPtr,
		int32_t _MazosCreados );
void adivinar();
void ingresar_pregunta(
		struct Mazo *_MazoPtr,
		int32_t *_MazosCreadosPtr );

#endif
