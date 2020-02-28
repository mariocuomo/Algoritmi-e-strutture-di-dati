#include <stdio.h>
#include <stdlib.h>


/*******************************************
=========DA COMPLETARE===========
*******************************************/

/*
STRUTTURA CHE RAPPRESENTA UN NODO DI UN ALBERO CONTENTENTE I SEGUENTI CAMPI:
	-info: è l'intero considerato	
	-left: è un puntatore al figlio sinistro
	-right: è un puntatore al figlio destro
	-parent: è un puntatore al genitore
	-sentinella: è un puntatore alla sentinella
	-color: 0=>nero, 1=>rosso
*/
typedef struct elem{
	int info;
	struct elem* left;
	struct elem* right;
	struct elem* parent;
	struct elem* sentinella;
	int color;
}nodo;



/*albero è un puntatore a nodo*/
typedef nodo* albero;

/*crea un albero vuoto*/
albero creaAlbero_vuoto();

/*aggiunge la radice all'albero*/
void aggiungi_radice(albero*,int);

/*aggiunge un nodo all'albero*/
void aggiungi_nodo(albero*,int);

/*ripristina l'albero rosso-nero*/
void ripristina(albero*,nodo*);

/*rotazione destra di un nodo*/
void ruota_destra(albero*,nodo*);

/*rotazione sinistra di un nodo*/
void ruota_sinistra(albero*,nodo*);


int main(){
	printf("Questa simulazione crea un albero binario di ricerca bilanciato\n");
	
	printf("\nPer fare cio' si utilizzano gli alberi rosso-neri\n");
	printf("Ecco alcune caratteristiche che un albero rosso-nero deve rispettare:\n");
	printf("\t- I nodi possono essere rossi oppure neri\n");
	printf("\t- La radice e la sentinella sono di colore nero\n");
	printf("\t- Se un nodo e' rosso allora entrambi i figli sono neri\n");
	printf("\t- Tutti i cammini vanno dalla radice alla sentinella\n");
	printf("\t- Non ci sono vincoli sul colore dei nodi dei figli neri\n\n");


	printf("Creo un albero binario di ricerca vuoto\n");
	albero mioAlbero = creaAlbero_vuoto();

	printf("Aggiungo la radice 100 dell'albero\n");
	aggiungi_radice(&mioAlbero,100);

	printf("Il colore della radice e' %d mentre quello della sentinella e' %d\n",mioAlbero->color,mioAlbero->sentinella->color);

	printf("Aggiungo il valore 68\n");
	aggiungi_nodo(&mioAlbero, 68);

	printf("Il colore della radice e' %d, quello della sentinella e' %d, mentre quello del nodo 68 e' %d\n",mioAlbero->color,mioAlbero->sentinella->color,mioAlbero->left->color);

	printf("Aggiungo il valore 50\n");
	aggiungi_nodo(&mioAlbero, 50);
}

albero creaAlbero_vuoto(){
	return NULL;
}

void aggiungi_radice(albero* t, int valore){
	nodo* radice = malloc(sizeof(nodo));
	nodo* sent = malloc(sizeof(nodo));
	sent->color=0;


	radice->info=valore;
	radice->left=sent;
	radice->right=sent;
	radice->color=0;
	radice->parent=NULL;
	radice->sentinella=sent;

	(*t)=radice;
}

void aggiungi_nodo(albero* t, int valore){
	nodo* nuovoNodo = malloc(sizeof(nodo));
	nuovoNodo->info=valore;
	nuovoNodo->right=(*t)->sentinella;
	nuovoNodo->left=(*t)->sentinella;
	nuovoNodo->sentinella=(*t)->sentinella;


	nodo* precedente = NULL;
	nodo* successivo = (*t);

	while(successivo!=(*t)->sentinella){
		precedente=successivo;
		if(valore < successivo->info)
			successivo=successivo->left;
		else
			successivo=successivo->right;
	}

	if(valore < precedente->info){
		precedente->left=nuovoNodo;
		nuovoNodo->parent=precedente;
	}
	else{
		precedente->right=nuovoNodo;
		nuovoNodo->parent=precedente;	
	}

	nuovoNodo->color=1;
	
	if(nuovoNodo->color==nuovoNodo->parent->color){
		printf("Prima di andare avanti ripristino la proprieta' rosso-nero dell'albero\n");
		ripristina(t,nuovoNodo);
	}	
}

void ripristina(albero* t, nodo* nuovo){
	nodo* nonno=nuovo->parent->parent;
	nodo* zio;

	if(nonno->left==nuovo->parent)
		zio=nonno->right;
	else
		zio=nonno->left;


}

