#include <stdio.h>
#include <stdlib.h>

/*
STRUTTURA CHE RAPPRESENTA UNA CODA CONTENTENTE I SEGUENTI CAMPI:
	-vettore: array di interi positivi
	-testa: riferiemento alla posizione del primo elemento
	-coda: riferimento alla prima posizione libera in coda
*/

typedef struct mia_queue{
	int* vettore;
	int testa;
	int coda;
	int dimensione;
}queue;


/*funzione per creare una nuova coda data una dimensione di base*/
queue* crea_coda(int);

/*funzione per aggiungere un elemento in coda*/
void aggiungi_elemento(queue*,int);

/*verifica se una coda è vuota
	ritorna 1 in caso positivo, 0 altrimenti
*/
int coda_vuota(queue*);

/*verifica se una coda è piena
	ritorna 1 in caso positivo, 0 altrimenti
*/
int coda_piena(queue*);

/*funzione per eliminare la testa della coda*/
void elimina_ultimo_elemento(queue*);

/*funzione per ottenere senza eliminare la testa della coda*/
int ottieni_ultimo_elemento(queue*);

/*ritorna il numero di elementi nella coda*/
int grandezza_coda(queue*);

/*funzione per svuotare tutti gli elementi di una coda*/
void svuota_coda(queue*);

/*funzione di supporto per stampare gli elementi della coda*/
void stampa_coda(queue*);


int main(){
	printf("Questa simulazione crea una coda di 5 elementi\n");
	queue* miaCoda = crea_coda(5);

	printf("Riempio la coda con valori random\n");
	for(int i=0;i<5;i++){
		int valore = rand() % 100 + 1;
		aggiungi_elemento(miaCoda,valore);
		printf("Ho inserito il valore %d\n",valore);
	}

	stampa_coda(miaCoda);

	printf("Elimino la testa della coda\n");
	elimina_ultimo_elemento(miaCoda);

	stampa_coda(miaCoda);

	printf("Svuoto l'intera coda\n");
	svuota_coda(miaCoda);
	stampa_coda(miaCoda);


	printf("Riempio la coda con valori random\n");
	for(int i=0;i<5;i++){
		int valore = rand() % 100 + 1;
		aggiungi_elemento(miaCoda,valore);
		printf("Ho inserito il valore %d\n",valore);
	}

	stampa_coda(miaCoda);

	printf("Svuoto l'intera coda passo dopo passo\n");
	for(int i=0;i<5;i++){
		elimina_ultimo_elemento(miaCoda);
		stampa_coda(miaCoda);
	}

	printf("Simulo una gestione di una coda, riempendo e eliminando elementi dalla random\n");
	for(int i=0;i<20;i++){
		int valore_decisione=rand() % 100 + 1;
		
		//aggiungo
		if(valore_decisione>50){
			printf("Aggiungo\n");
			int valore = rand() % 100 + 1;
			aggiungi_elemento(miaCoda,valore);
			stampa_coda(miaCoda);
		}
		//elimino
		else{
			printf("Elimino\n");
			elimina_ultimo_elemento(miaCoda);
			stampa_coda(miaCoda);
		}
	}

}

queue* crea_coda(int dim){
	queue* nuovaCoda = malloc(sizeof(queue));
	nuovaCoda->vettore=malloc(sizeof(int)*(dim+1));
	nuovaCoda->testa=0;
	nuovaCoda->coda=0;
	nuovaCoda->dimensione=dim+1;
}

void aggiungi_elemento(queue* c,int valore){
	if(coda_piena(c)==1)
		printf("La coda e' piena, non posso inserire nuovi elementi\n");
	else{
		c->vettore[c->coda]=valore;
		c->coda++;
		if(c->coda==c->dimensione)
			c->coda=0;
	}
}

int coda_vuota(queue* c){
	if(c->testa==c->coda)
		return 1;
	return 0;
}

int coda_piena(queue* c){
	if(c->testa==0 && c->coda==c->dimensione-1)
		return 1;
	if(c->coda==c->testa-1)
		return 1;
	return 0;
}

void elimina_ultimo_elemento(queue* c){
	if(coda_vuota(c)==1)
		printf("La coda e' vuota!");
	c->testa++;
	if(c->testa==c->dimensione)
		c->testa=0;
}

int ottieni_ultimo_elemento(queue* c){
	if(coda_vuota(c)==1)
		printf("La coda e' vuota!");
	return c->vettore[c->testa];
}

int grandezza_coda(queue* c){
	if(coda_vuota(c)==1)
		return 1;
	if(coda_piena(c)==1)
		return c->dimensione-1;

	if(c->coda > c->testa)
		return c->coda-c->testa;
	return c->coda + c->dimensione-c->testa;
}

void svuota_coda(queue* c){
	c->testa=c->coda;
}


void stampa_coda(queue* c){
	if(coda_vuota(c)==1)
		printf("La coda e' vuota!\n");
	else{
		printf("La coda contiene %d elementi, che sono i seguenti\n",grandezza_coda(c));
		//posizione standard
		if(c->coda > c->testa){
			for(int i=c->testa;i<c->coda;i++)
				printf("%d ", c->vettore[i]);
		}
		else{
		//posizione non standard
		for(int i=c->testa;i<c->dimensione;i++)
			printf("%d ", c->vettore[i]);
		for(int i=0;i<c->coda;i++)
			printf("%d ", c->vettore[i]);
		}

		printf("\n");
	}
}


