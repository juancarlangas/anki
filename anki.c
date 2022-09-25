/*PROGRAMA QUE SIMULA LA APLICACION ANKI, CON LA OPCION DE DIGITAR Y ALMACENAR NUESTRAS PREGUNTAS Y RESPUESTAS DENTRO DE UNA ESTRUCTURA 
DE DATOS, CON LA OPCION DE LUEGO COMPARAR LAS RESPUESTAS SI SON CORRECTAS FINALIZAR EL PROGRAMA DE LO CONTRARIO SEGUIR INTENTANDO
*/

#include<stdio.h>
#include<string.h>

int mazos_creados = 0;
int cont_preguntas = 0;

void crear_mazo();
void imprimir_mazos();
void adivinar();
void ingresar_pregunta();

int main()
{
	int eleccion;
	char vol;
		do{
		printf("**************************************\n");
		printf("BIENVENIDO A ANKI ESTE ES EL MENU:\n");
		printf("**************************************\n");
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
					crear_mazo();
					break;

			case 2:
				imprimir_mazos();
				break;

			case 3:					//AQUI FALTA CONTINUAR CON ADIVINAR Y RESPUESTA
				adivinar();					//AGREGAR CUANTAS TARJETAS HAZ ESTUDIADO
				break;

			case 4:
				if( mazos_creados >0 ) {
				printf("\n HAZ SELECCIONADO INGRESAR PREGUNTA");
					ingresar_pregunta();	
				}else 
				printf("TODAVIA NO HAY MAZOS!!!!");
				break;
			case 5:
				printf("\nHASTA LA VISTA :)");
				return 0;
		}
		getchar();
		printf("\nQUIERES VOLVER AL MENU? [S]=SI [N]=NO  ");
		printf("DIGITE LA OPCION:  ");
		scanf("%c",&vol);
	}while(elec<5&&vol!='N');
		
}

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
