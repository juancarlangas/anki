/* En la programacion, es comun que el prototipo de una funcion incluido en un archivo .h sea
 * requerido por más de un archivo .c, -en este caso, "mazo.h" es requerido tanto por "mazo.c" y
 * por main.c-. Pero si es incluido en todos estos, al final se estaría repitiendo el codigo,
 * haciendo que todo sea definido varias veces, produciéndose un error.
 *
 * Se requeriria entonces incluir el archivo .h justo en el momento adecuado, antes de que
 * sea requerido, pero... ¿podremos estar siempre al pendiente del orden en que nuestros archivos
 * son compilados? y, ¿qué tal si agregamos otros archivos que también lo requieran? Resulta casi
 * imposible y poco practico controla este aspecto, más si ya estás manejando muchos archivos.
 *
 * La meta entonces es garantizar que, sin importar cuántas veces un archivo sea incluido, solo sea
 * considerado 1 vez por el compilador -el resto del código ya tendrá las cabeceras disponibles-.
 * Se utiliza entonces en cada cabecera la directriz #ifndef acompañado de cualquier palabra
 * (preferentemente el mismo nombre de archivo en MAYÚSCULAS y con guiones _. #ifndef funciona
 * casi como un -if-, pero es leído por el compilador y se interpreta como "si no está definido ..." 
 * De cumplirse la condición, se definirá entonces la palabra. Así, la próxima vez que el archivo
 * sea incluido, la condición -ifndef- ya no se cumplirá y se ignorará el resto del código hasta
 * encontrar #ifndef (lo que correspondería en C a la llave '}')
 *
 * Este es un truco, que más que truco, ya se ha convertido en el canon de programación para los
 * archivos de cabecera (headers) */
#ifndef MAZO_H
#define MAZO_H

#include <stdint.h> // para int32_t

/* Las definciones es mejor usar mayusculas. Ademas deben crearse mas especificas, no usar palabras
 * como LIMITE, que resultan poco explicitas. Así, puedes hacer cambios concretos */
#define MAX_LETRAS 50
#define MAX_TARJETAS 50
#define MAX_MAZOS 50

/* Los nuevos tipos se acostumbra nombrarlos con mayúsculas al principio, ademas de usarse nombres
 * en singular porque lo que se define es algo unitario*/
struct Tarjeta {
	char pregunta[ MAX_LETRAS ];
	char definicion[ MAX_LETRAS ];
};

// Vamos a añadir al mazo su propio conteo interno de tarjetas
struct Mazo {
	char nombre[ MAX_LETRAS ];
	struct Tarjeta tarjeta[ MAX_TARJETAS ];
	int32_t n_tarjetas;
};

void crear_mazo( struct Mazo _Mazo[], int32_t *_MazosCreados );
void imprimir_mazos( struct Mazo _Mazo[], int32_t _MazosCreados );
void adivinar();
void ingresar_pregunta( struct Mazo _Mazo[], const int32_t *_MazosCreadosPtr );

#endif
