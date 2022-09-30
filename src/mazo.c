#include "mazo.h"
#include <stdio.h>
#include <string.h>

/* Aquí hacemos uso del hecho de que un arreglo es un apuntador. En los argumentos hubieramos
 * podido escribir _MazoPtr[] en lugar de *_MazoPtr */

void crear_mazo( struct Mazo _Mazo[], int *_MazosCreadosPtr )/*{{{*/
{
	printf( "POR FAVOR INGRESE EL NOMBRE DEL NUEVO MAZO: ");
	fgets( _Mazo[ *_MazosCreadosPtr ].nombre, MAX_LETRAS, stdin); // Se lee hacia el arreglo
	++( *_MazosCreadosPtr );
}/*}}}*/

void imprimir_mazos( struct Mazo _Mazo[], const int32_t mazos_creados )/*{{{*/
{
	printf("\nMAZOS EXISTENTES: %i", mazos_creados );
	printf("\nNOMBRE DE LOS MAZOS: ");

	for ( int32_t i = 0; i < mazos_creados; ++i )
		printf( "\n%i.- %s", i + 1, _Mazo[i].nombre );
}/*}}}*/

void adivinar()/*{{{*/
{

}/*}}}*/

void ingresar_pregunta( struct Mazo _Mazo[], const int32_t *_MazosCreadosPtr )/*{{{*/
{
	int32_t mazo_elegido;

	printf("\nPOR FAVOR INGRESE EL NUMERO DE MAZO A ELEGIR PARA LA PREGUNTA: ");
	scanf( "%i", &mazo_elegido );
	getchar();
	printf("\nHAZ SELECCIONADO EL MAZO: %s", _Mazo[ mazo_elegido - 1 ].nombre);

	printf("\n POR FAVOR INGRESE LA PREGUNTA: ");
	fgets( _Mazo[ mazo_elegido ].tarjeta[ _Mazo[ mazo_elegido ].n_tarjetas ].pregunta,
			MAX_LETRAS, stdin );
	++_Mazo[ mazo_elegido ].n_tarjetas;
}/*}}}*/
