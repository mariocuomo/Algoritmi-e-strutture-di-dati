#include <stdio.h>

/*
STRUTTURA CHE RAPPRESENTA UN NODO DI UN ALBERO N-ARIO CON STRUTTURA FIGLIO SINISTRO-FRATELLO DESTRO CONTENTENTE I SEGUENTI CAMPI:
	-info: è l'intero considerato	
	-figlio: è un puntatore al primo figlio sinistro
	-fratello: è un puntatore al fratello destro
	-genitore: è un puntatore al genitore
*/
typedef struct elem{
	int info;
	struct elem* figlio;
	struct elem* fratello;
	struct elem* genitore;
}nodo;

/*albero è un puntatore a un nodo*/
typedef nodo* albero;

/*crea un albero vuoto*/
albero crea_albero_vuoto();

/*aggiunge una radice albero*/
void aggiungi_radice(albero*,int);

/*funzione per aggiungere un figlio al nodo*/
void aggiungi_figlio(albero*,int);

/*funzione per aggiungere un fratello al nodo*/
void aggiungi_fratello(albero*,int);

/*ritorna il numeri di nodi di un albero*/
int conta_nodi(albero);

/*ritorna l'altezza dell'albero
	-1 albero vuoto,
	n>0 in tutti gli altri casi
*/
int altezza(albero);

/*verifica se un albero è vuoto
	ritorno 1 in caso positivo, 0 altrimenti
*/
int albero_vuoto(albero);

/*calcola il numero di figli di un nodo*/
int numero_figli(albero);

/*calcola il numero di fratelli di un nodo*/
int numero_fratelli(albero);

/*verifica se un nodo è una foglia
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int e_foglia(albero);

/*ritorna il numero delle foglie*/
int conta_foglie(albero);

/*verifica se due nodi sono fratelli
	ritorna 1 in caso positivo, 0 in caso negativo 
*/
int sono_fratelli(albero,albero);

/*funzione per eliminare un nodo dall'albero*/
void elimina_nodo(albero*, nodo*);

/*funzione di supporto per calcolare il massimo tra due valori*/
int massimo(int, int);



int main(){
	printf("Questa simulazione crea un albero n-ario della seguente forma\n");
	printf("Questa simulazione crea un alber n-ario della seguente forma\n");
	printf("\t\t\t0\n");
	printf("\t\t\t|\n");
	printf("\t\t5   4   3   2   1\n");
	printf("\t\t\t\t|\n");
	printf("\t\t\t\t8   7\n");

	albero mioAlbero = crea_albero_vuoto();
	printf("Ho creato un nuovo albero \n");

	printf("Ho aggiunto la radice 0 all'albero\n");
	aggiungi_radice(&mioAlbero,0);

	printf("Aggiungo il primo figlio 1 alla radice dell'albero\n");
	aggiungi_figlio(&mioAlbero,1);

	printf("L'albero attualmente ha %d nodi\n",conta_nodi(mioAlbero));

	printf("Aggiungo il secondo figlio 2 alla radice dell'albero\n");
	aggiungi_figlio(&mioAlbero,2);

	printf("Attualmente l'albero ha altezza %d\n",altezza(mioAlbero));

	printf("Aggiungo i figli 3 4 5 alla radice dell'albero\n");
	aggiungi_figlio(&mioAlbero,3);
	aggiungi_figlio(&mioAlbero,4);
	aggiungi_figlio(&mioAlbero,5);

	printf("Ora la radice ha %d figli\n",numero_figli(mioAlbero));

	printf("Aggiungo i figli 8 e 7 al nodo 3\n");
	aggiungi_figlio(&(mioAlbero->figlio->fratello->fratello),7);
	aggiungi_fratello(&(mioAlbero->figlio->fratello->fratello->figlio),8);

	printf("Attualmente ho un albero con le seguenti caratteristiche:\nNodi: %d\nFigli radice: %d\nFigli nodo 3: %d\nFoglie: %d\nAltezza: %d\n",conta_nodi(mioAlbero),numero_figli(mioAlbero),numero_figli(mioAlbero->figlio->fratello->fratello),conta_foglie(mioAlbero),altezza(mioAlbero));

	if(sono_fratelli(mioAlbero->figlio,mioAlbero->figlio->fratello)==1)
		printf("I nodi %d e %d sono fratelli",mioAlbero->figlio->info,mioAlbero->figlio->fratello->info);
	else
		printf("I nodi %d e %d non sono fratelli\n",mioAlbero->figlio->info,mioAlbero->figlio->fratello->info);

	printf("\nProvo a eliminare il nodo 3\n");
	elimina_nodo(&mioAlbero,mioAlbero->figlio->fratello->fratello);

	printf("Attualmente ho un albero con le seguenti caratteristiche:\nNodi: %d\nFigli radice: %d\nFigli nodo 3: %d\nFoglie: %d\nAltezza: %d\n",conta_nodi(mioAlbero),numero_figli(mioAlbero),numero_figli(mioAlbero->figlio->fratello->fratello),conta_foglie(mioAlbero),altezza(mioAlbero));

}

albero crea_albero_vuoto(){
	return NULL;
}

void aggiungi_radice(albero* t,int valore){
	nodo* nuovoNodo = malloc(sizeof(nodo));
	nuovoNodo->info=valore;
	nuovoNodo->figlio=NULL;
	nuovoNodo->fratello=NULL;
	nuovoNodo->genitore=NULL;
	(*t)=nuovoNodo;
}

void aggiungi_figlio(albero* t, int valore){
	nodo* nuovoNodo = malloc(sizeof(nodo));
	nuovoNodo->info=valore;
	nuovoNodo->figlio=NULL;
	nuovoNodo->fratello=NULL;
	nuovoNodo->genitore=(*t);

	if((*t)->figlio==NULL)
		(*t)->figlio=nuovoNodo;
	else{
		nuovoNodo->fratello=(*t)->figlio;
		(*t)->figlio=nuovoNodo;
	}
}

void aggiungi_fratello(albero* t, int valore){
	nodo* nuovoNodo = malloc(sizeof(nodo));
	nuovoNodo->info=valore;
	nuovoNodo->figlio=NULL;
	nuovoNodo->fratello=(*t)->fratello;
	nuovoNodo->genitore=(*t)->genitore;
	(*t)->fratello=nuovoNodo;

}

int albero_vuoto(albero t){
	if(t==NULL)
		return 1;
	return 0;
}

int conta_nodi(albero t){
	if(albero_vuoto(t)==1)
		return 0;
	return 1+conta_nodi(t->figlio)+conta_nodi(t->fratello);
}

int conta_foglie(albero t){
	if(albero_vuoto(t)==1)
		return 0;
	if(e_foglia(t)==1)
		return 1+conta_foglie(t->fratello);
	return conta_foglie(t->figlio)+conta_foglie(t->fratello);
}


int altezza(albero t){
	if(albero_vuoto(t)==1)
		return -1;
	if(e_foglia(t)==1){
		altezza(t->fratello);
	}
	return massimo(1+altezza(t->figlio),altezza(t->fratello));
}

int sono_fratelli(albero t1, albero t2){
	if(albero_vuoto(t1)==1 || albero_vuoto(t2)==1)
		return 0;
	if(t1->genitore==t2->genitore)
		return 1;
	return 0;

}

int massimo(int a, int b){
	if(a>b)
		return a;
	return b;
}

int numero_figli(albero t){
	if(albero_vuoto(t)==1)
		return 0;
	if(t->figlio==NULL)
		return 0;
	return 1+numero_fratelli(t->figlio);
}

int e_foglia(albero t){
	if(t->figlio==NULL)
		return 1;
	return 0;
}

int numero_fratelli(albero t){
	if(albero_vuoto(t)==1)
		return 0;
	if(t->fratello==NULL)
		return 0;
	return 1+numero_fratelli(t->fratello);
}

void elimina_nodo(albero* t, nodo* n){
	if(albero_vuoto(*t)==1){
		return;
	}

	//ho trovato il nodo da eliminare
	if((*t)==n){
		//il nodo è la radice?
		if((*t)->genitore==NULL)
			(*t)=NULL;
		//il nodo non è la radice
		else{
			nodo* attuale = (*t)->genitore->figlio;
			nodo* precedente = NULL;
			while(attuale!=n){
				precedente=attuale;
				attuale=attuale->fratello;
			}
			precedente->fratello=attuale->fratello;
		}
	}
	else{
		elimina_nodo(&(*t)->figlio,&(*n));
		elimina_nodo(&(*t)->fratello,&(*n));
	}


}
