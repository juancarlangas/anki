/*PROGRAMA QUE SIMULA LA APLICACION ANKI, CON LA OPCION DE DIGITAR Y ALMACENAR NUESTRAS PREGUNTAS Y RESPUESTAS DENTRO DE UNA ESTRUCTURA 
DE DATOS, CON LA OPCION DE LUEGO COMPARAR LAS RESPUESTAS SI SON CORRECTAS FINALIZAR EL PROGRAMA DE LO CONTRARIO SEGUIR INTENTANDO
*/

#include<stdio.h>
#include<string.h>
/* Las definciones es mejor usar
 * mayusculas. Ademas de crean
 * mucho mas especificas, no usar
 * palabras como LIMITE, que
 * resultan poco exolicitas */
#define MAX_LETRAS 50
#define MAX_TARJETAS 50

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
} mazo[50];


int mazos_existentes = 0;
int cont_preguntas = 0;

void mazo_nuevo();
void mazos_exist();
void adivinar();
void ingresar_pregunta();
int main()
{
	int elec;
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
		scanf("%i",&elec);

		switch (elec){

			case 1:
				if (mazos_existentes<limite)
					getchar();
					mazo_nuevo();
					break;
			case 2:
				getchar();
				mazos_exist();
				break;
			case 3:					//AQUI FALTA CONTINUAR CON ADIVINAR Y RESPUESTA
				adivinar();					//AGREGAR CUANTAS TARJETAS HAZ ESTUDIADO
				break;
			case 4:
				if(mazos_existentes>0){
				printf("\n HAZ SELECCIONADO INGRESAR PREGUNTA");
					mazos_exist();
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

void mazo_nuevo(){
		printf("POR FAVOR INGRESE EL NOMBRE DEL NUEVO MAZO: ");
		fgets(cantidad_mazos[mazos_existentes].nombre,limite,stdin);
		mazos_existentes++;
}

void mazos_exist(){
	printf("\nCANTIDAD DE MAZOS EXISTENTES: %i",mazos_existentes);
	printf("\nNOMBRE DE LOS MAZOS: ");
		for (int i = 0; i < mazos_existentes; i++)
			{
				printf("\n%i.- %s",i+1,cantidad_mazos[i].nombre);
			}

}

void adivinar(){
//FUNCION AUN NO CREADA
}

void ingresar_pregunta(int a){
	printf("\nPOR FAVOR INGRESE EL NUMERO DE MAZO A ELEGIR PARA LA PREGUNTA: ");
	scanf("%i",&a);
	printf("\nHAZ SELECCIONADO EL MAZO: %s",cantidad_mazos[a-1].nombre);
	printf("\n POR FAVOR INGRESE LA PREGUNTA: ");
	fgets(cantidad_mazos[mazos_existentes].preguntas[cont_preguntas].pregunt,limite,stdin);
	cont_preguntas++;
}
