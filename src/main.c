#include<stdio.h>
#include<string.h>

// incluimos prototipos movidos a mazo.h en la misma carpeta
#include "mazo.h" 

// usamos el alias int32_t como buena practica para que el compilador escoja el tipo de int garantizando que el numero de bits sera constante (Win, Mac, Linux, etc)
int32_t main()
{
	// ahora el arreglo maxo[] sera local
	struct Mazo mazo[ MAX_MAZOS ]; // creamos

	// tambien locales
	int32_t mazos_creados = 0;
	int32_t cont_preguntas = 0;

	int32_t eleccion;
	char vol;

		do{
		printf("***************************\n");
		printf("BIENVENIDO A ANKI\n");
		printf("***************************\n");
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
					crear_mazo( mazo, &mazos_creados);
					break;
			case 2:
				imprimir_mazos( mazo,mazos_creados);
				break;
			case 3:
				adivinar();
				break;
			case 4:
				if( mazos_creados > 0 ) {
				printf("\n HAZ SELECCIONADO INGRESAR PREGUNTA");
					ingresar_pregunta(
							mazo, &mazos_creados );	
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

