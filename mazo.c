#include "mazo.h"
#include <stdio.h>
#include <string.h>

void crear_mazo()
{
		printf("POR FAVOR INGRESE EL NOMBRE DEL NUEVO MAZO: ");
		fgets( mazo[mazos_creados].nombre, MAX_LETRAS, stdin);
		++mazos_creados;
}

void imprimir_mazos()
{
	printf("\nCANTIDAD DE MAZOS EXISTENTES: %i", mazos_creados );
	printf("\nNOMBRE DE LOS MAZOS: ");
		for (int i = 0; i < mazos_creados; ++i )
			{
				printf("\n%i.- %s",i+1, mazo[i].nombre );
			}

}

void adivinar()
{
//FUNCION AUN NO CREADA
}

void ingresar_pregunta( int a )
{
	printf("\nPOR FAVOR INGRESE EL NUMERO DE MAZO A ELEGIR PARA LA PREGUNTA: ");
	scanf( "%i",&a );
	getchar();
	printf("\nHAZ SELECCIONADO EL MAZO: %s", mazo[ a - 1 ].nombre);
	printf("\n POR FAVOR INGRESE LA PREGUNTA: ");
	fgets( mazo[mazos_creados].pregunta[cont_preguntas].pregunt,limite,stdin);
	cont_preguntas++;
}
