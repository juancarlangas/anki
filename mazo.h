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
	int n_tarjetas;
};
