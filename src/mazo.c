#include "mazo.h"
#include <stdio.h>
#include <string.h>


void crear_mazo( struct Mazo *_MazoPtr,
		int *_MazosCreadosPtr )/*{{{*/
{
		printf("POR FAVOR INGRESE EL NOMBRE DEL NUEVO MAZO: ");
		fgets( _MazoPtr[ *_MazosCreadosPtr ].nombre, MAX_LETRAS, stdin);
		++( *_MazosCreadosPtr );
}/*}}}*/

void imprimir_mazos( struct Mazo *_MazoPtr,
		const int32_t mazos_creados )/*{{{*/
{
	printf("\nMAZOS EXISTENTES: %i",
			mazos_creados );
	printf("\nNOMBRE DE LOS MAZOS: ");
		for (int32_t i = 0; i < mazos_creados; ++i )
				printf("\n%i.- %s",i+1,
						_MazoPtr[i].nombre );
}/*}}}*/

void adivinar()
{}

void ingresar_pregunta(
		struct Mazo *_MazoPtr,
		int32_t *_MazosCreadosPtr )
{
	int32_t mazo;
	printf("\nPOR FAVOR INGRESE EL NUMERO DE MAZO A ELEGIR PARA LA PREGUNTA: ");
	scanf( "%i", &mazo );
	getchar();
	printf("\nHAZ SELECCIONADO EL MAZO: %s",
			_MazoPtr[ mazo - 1 ].nombre);
	printf("\n POR FAVOR INGRESE LA PREGUNTA: ");
	fgets( _MazoPtr[ mazo ].tarjeta[ _MazoPtr[ mazo ].n_tarjetas ].pregunta, MAX_LETRAS, stdin );
	++_MazoPtr[ mazo ].n_tarjetas;
}
