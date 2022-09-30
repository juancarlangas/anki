#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para macros EXIT_SUCCESS, EXIT_FAILURE, etc
#include <iso646.h> // Para uso de "and" y "or" en lugar de "&&" y "||"

// incluimos prototipos ahora en "mazo.h (ubicado en la misma carpeta)"
#include "mazo.h" 

/* usamos el alias -int32_t- como buena practica para que el compilador escoja el tipo de int
 * garantizando que el numero de bits sea constante (Win, Mac, Linux, etc) */
int32_t main()
{
	// ahora el arreglo mazo[] sera local
	struct Mazo mazo[ MAX_MAZOS ]; // creamos

	// tambien locales
	int32_t mazos_creados = 0;

	int32_t eleccion;
	char vol;

	do {
		printf("*************************************************\n");
		printf("BIENVENIDO A ANKI\n");
		printf("*************************************************\n");

		printf("[1]CREAR UN MAZO NUEVO\n");
		printf("[2]VER MAZOS EXISTENTES\n");
		printf("[3]ADIVINAR\n");
		printf("[4]INGRESAR PREGUNTA\n");
		printf("[5]SALIR\n");

		printf("DIGITE LA OPCION:  ");
		scanf( "%i",&eleccion );
		getchar(); //clean

		switch ( eleccion ) {
			case 1:
				if ( mazos_creados < MAX_MAZOS )
					/* Al ser variables locales, ahora deben ser enviados como parámetros.
					 * Se envían sus direcciones para que las funciones puedan tener acceso a
					 * su información. A esto se le llama "simular una llamada POR REFERENCIA" */
					crear_mazo( mazo, &mazos_creados);
					break;
			case 2:
				/* imprimir_mazos no requiere modificar nada, por lo que mazos_creados es enviado
				 * por valor (recibirá una copia). de mazo sí se envía su dirección porque resulta
				 * más complicado y poco práctico en términos de rendimiento y memoria enviar
				 * EL ARREGLO DE struct completo. Más adelante veremos como garantizar que aunque
				 * se envíe el apuntador, la función que lo reciba NO pueda modificarlo. Por ahora
				 * solo tener cuidado de que no lo haga */
				imprimir_mazos( mazo, mazos_creados);
				break;
			case 3:
				adivinar();
				break;
			case 4:
				/* Al contrario de una función(), en enunciados if, for, etc, el paréntesis
				 * se acostumbra a un espacio de la palabra */
				if ( mazos_creados > 0 ) {
					printf("\n HAZ SELECCIONADO INGRESAR PREGUNTA");
					ingresar_pregunta( mazo, &mazos_creados );	
				} else 
					printf("TODAVIA NO HAY MAZOS!!!!");
				break;
			case 5:
				printf( "\nHASTA LA VISTA :)\n\n" );
				break;
		}

		if ( eleccion < 5 ) {
			printf( "\nQUIERES VOLVER AL MENU? [S]=SI [N]=NO  ");
			scanf( "%c",&vol );
			getchar();
		}

	} while( eleccion < 5 or vol == 'Y' or vol == 'y' );

	return EXIT_SUCCESS;
}

