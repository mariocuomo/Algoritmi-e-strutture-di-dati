#include <stdio.h>
#include <stdlib.h>

/*
STRUTTURA CHE RAPPRESENTA UNO ELEMENTO DI UNA LISTA SEMPLICEMENTE CONCATENATA CONTENTENTE I SEGUENTI CAMPI:
	-info: è l'intero considerato
	-next: è un puntatore al prossimo elemento della lista
*/
typedef struct elem_{
	int info;
	struct elem_* next;
}elemento;

/*lista è un puntatore a un elemento*/
typedef elemento* lista;

/*funzione per creare una nuova lista*/
lista crea_lista();

/*aggiunge un elemento in testa, costo unitario*/
void aggiungi_elemento_in_testa(lista*,int);


/*
STRUTTURA CHE RAPPRESENTA UN NODO DI UN ALBERO CONTENTENTE I SEGUENTI CAMPI:
	-info: è l'intero considerato	
	-left: è un puntatore al figlio sinistro
	-right: è un puntatore al figlio destro
	-parent: è un puntatore al genitore
*/
typedef struct elem{
	int info;
	struct elem* left;
	struct elem* right;
	struct elem* parent;
}nodo;

/*albero è un puntatore a un nodo*/
typedef nodo* albero;

/*crea un albero vuoto*/
albero crea_albero_vuoto();

/*aggiunge una radice albero*/
void aggiungi_radice(albero*,int);

/*funzione per aggiungere un nuovo nodo*/
void aggiungi_nodo(albero*,int);

/*funzione per riempire un vettore a partire da un albero binario visitandolo in maniera simmetrica*/
void riempi_lista(albero,lista*);

/*funzione per stampare un albero*/
void stampa(albero);


/*funzione di ordinamento crescente
	-caso peggiore,caso medio ordine di n^2,
	-caso migliore ordine di nlogn
*/
void treeSort(int*, int);

/*funzione di ordinamento crescente, stampa l'evoluzione dell'ordinamento a ogni passo*/
void treeSort_stampa(int*, int);

int main(){
	printf("Questa simulazione ordina un array di 20 interi positivi\n");
	int vettore[20];
	int i=0;
	printf("Riempio random il vettore\n");
	//riempio il vettore con valori random
	for(;i<20;i++)
		vettore[i]=rand() % 100 + 1;

	//stampo il vettore
	printf("Attualmente il vettore contiene i seguenti valori\n");
	for(i=0;i<20;i++)
		printf("%d ",vettore[i]);

	printf("\nOrdino l'array costruendo un albero binario di ricerca\n");
	treeSort(vettore,20);

	//stampo il vettore
	printf("Dopo l'ordinamento il vettore contiene i seguenti valori\n");
	for(i=0;i<20;i++)
		printf("%d ",vettore[i]);

	printf("\nRendo nuovamento il vettore random\n");
	//riempio il vettore con valori random
	for(;i<20;i++)
		vettore[i]=rand() % 100 + 1;

	printf("Attualmente il vettore contiene i seguenti valori\n");
	for(i=0;i<20;i++)
		printf("%d ",vettore[i]);

	printf("\nEcco come avviene l'ordinamento passo dopo passo\n");
	treeSort_stampa(vettore,20);

}

void treeSort(int* vettore,int lunghezza){
	int i=0;

	albero mioAlbero = crea_albero_vuoto();
	aggiungi_radice(&mioAlbero,vettore[0]);

	for(i=1;i<lunghezza;i++){
		aggiungi_nodo(&mioAlbero,vettore[i]);
	}

	lista miaLista = crea_lista();
	riempi_lista(mioAlbero,&miaLista);

	for(i=lunghezza-1;i>=0;i--){
		vettore[i]=miaLista->info;
		miaLista=miaLista->next;
	}

	
}

void riempi_lista(albero t, lista* lst){
	if(t!=NULL){
		riempi_lista(t->left,lst);
		aggiungi_elemento_in_testa(&*lst,t->info);
		riempi_lista(t->right,lst);
	}
}

void treeSort_stampa(int* vettore,int lunghezza){
	int i=0;

	albero mioAlbero = crea_albero_vuoto();
	aggiungi_radice(&mioAlbero,vettore[0]);

	for(i=1;i<lunghezza;i++){
		aggiungi_nodo(&mioAlbero,vettore[i]);
		stampa(mioAlbero);
		printf("\n");
	}

}

void stampa(albero t){
	if(t!=NULL){
		stampa(t->left);
		printf("%d ", t->info);
		stampa(t->right);
	}
}

lista crea_lista(){
	return NULL;
}
void aggiungi_elemento_in_testa(lista* lst, int valore){
	elemento* nuovoElemento = malloc(sizeof(elemento));
	nuovoElemento->info=valore;
	nuovoElemento->next=(*lst);
	(*lst)=nuovoElemento;
}


albero crea_albero_vuoto(){
	return NULL;
}

void aggiungi_radice(albero* t,int valore){
	nodo* nuovoNodo = malloc(sizeof(nodo));
	nuovoNodo->info=valore;
	nuovoNodo->right=NULL;
	nuovoNodo->left=NULL;
	nuovoNodo->parent=NULL;
	(*t)=nuovoNodo;
}

void aggiungi_nodo(albero* t, int valore){
	nodo* nuovoNodo = malloc(sizeof(nodo));
	nuovoNodo->info=valore;
	nuovoNodo->right=NULL;
	nuovoNodo->left=NULL;

	nodo* precedente = NULL;
	nodo* successivo = (*t);

	while(successivo!=NULL){
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

	
}



