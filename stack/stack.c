#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


/*
STRUTTURA CHE RAPPRESENTA UNO STACK CONTENTENTE I SEGUENTI CAMPI:
	-vettore: array di interi positivi
	-ultimo: riferiemento alla posizione dell'ultimo elemento inserito
	-dimensione: dimensione dell'array
*/

typedef struct mio_stack{
	int *vettore;
	int ultimo;
	int dimensione;
}stack;

/*funzione per creare un nuovo stack data una dimensione di partenza*/
stack* crea_stack(int);

/*funzione per aggiungere un elemento all'interno dello stack
  gestisce la riallocazione in caso di spazio esaurito  
*/
void aggiungi_elemento(stack*,int);

/*funzione per eliminare l'ultimo elemento inserito*/
void elimina_elemento(stack*);

/*funzione per stampare i valori inseriti all'interno dello stack*/
void stampa_stack(stack*);

/*funzione per ottenere l'ultimo elemento inserito senza eliminarlo*/
int vedi_ultimo_elemento(stack*);

/*funzione per ottere l'ultimo elemento inserito eliminandolo
  ritorna -1 se lo stack è vuoto
*/
int prendi_ultimo_elemento(stack*);

/*funzione di supporto per modificare dimensione di un array*/
void modifica_dimensione_array(stack*, int);

/*funzione di supporto per verificare se uno stack è pieno
	ritorna 1 in caso positivo
	ritorno 0 in caso negativo
*/
int stack_pieno(stack*);

/*funzione di supporto per verificare se uno stack è vuoto
	ritorna 1 in caso positivo
	ritorno 0 in caso negativo
*/
int stack_vuoto(stack*);

/*funzione per svuotare uno stack*/
void svuota_stack(stack*);


int main(){
	printf("Questa simulazione crea uno stack di 5 elementi interi positivi\n");
	stack* mioStack = crea_stack(5);

	printf("Riempio lo stack con valori randomici positivi\n");
	for(int i=0;i<5;i++)
		aggiungi_elemento(mioStack, rand()%(11));
		
	printf("Situazione attuale:\n");
	stampa_stack(mioStack);

	printf("Provo a inserire il valore 10\n");
	aggiungi_elemento(mioStack,10);

    printf("Situazione attuale:\n");
	stampa_stack(mioStack);

	printf("Visualizzo l'ultimo elemento: %d\n", vedi_ultimo_elemento(mioStack));

	printf("Situazione attuale:\n");
	stampa_stack(mioStack);

	printf("Provo a eliminare l'ultimo elemento inserito\n");
	elimina_elemento(mioStack);

	printf("Situazione attuale:\n");
	stampa_stack(mioStack);

	printf("Provo a prendere l'ultimo elemento eliminandolo: %d\n",prendi_ultimo_elemento(mioStack));
	
	printf("Situazione attuale:\n");
	stampa_stack(mioStack);


	printf("Provo a eliminare tutti gli elementi\n");
	while(mioStack->ultimo!=0){
		elimina_elemento(mioStack);
		stampa_stack(mioStack);
	}


	printf("Riempio lo stack con valori randomici\n");
	for(int i=0;i<5;i++)
		aggiungi_elemento(mioStack,rand()%(11));

	printf("Situazione attuale:\n");
	stampa_stack(mioStack);

	printf("Svuoto tutto lo stack\n");
	svuota_stack(mioStack);
	printf("Situazione attuale:\n");
	stampa_stack(mioStack);

}




stack* crea_stack(int dim){
	stack* nuovoStack = malloc(sizeof(stack));
	nuovoStack->ultimo=-1;
	nuovoStack->dimensione=dim;
	nuovoStack->vettore = malloc(sizeof(int)*dim);

	return nuovoStack;
}


void aggiungi_elemento(stack* s, int elemento){
	if(stack_pieno(s)){
		printf("Lo stack è pieno ma raddoppio la dimensione di base\n");
		modifica_dimensione_array(s,(float)0.5);
	}
	s->ultimo++;
	s->vettore[s->ultimo]=elemento;
}


void elimina_elemento(stack* s){
	if(stack_vuoto(s))
		printf("Lo stack è vuoto\n");
	else{
		s->ultimo--;
	}

	double percentuale_occupazione = (float)s->ultimo/(float)s->dimensione;
	if(percentuale_occupazione<=0.3){
		printf("Lo stack è oneroso, diminuisco la grandezza\n");
		modifica_dimensione_array(s,3);
	}
}

void stampa_stack(stack* s){
	printf("L'array dello stack attualmente ha dimensione %d ",s->dimensione);
	if(stack_vuoto(s))
		printf("ma purtroppo è vuoto");
	else{
		printf("e contiene %d elemento/i, che sono: ",s->ultimo+1);
		for(int i=0;i<=s->ultimo;i++)
			printf("%d ",s->vettore[i]);
	}
	printf("\n");
}

int vedi_ultimo_elemento(stack* s){
	return s->vettore[s->ultimo];
}

int prendi_ultimo_elemento(stack* s){
	int elemento_ritorno=-1;
	if(stack_vuoto(s))
		printf("Lo stack è vuoto\n");
	else{
		elemento_ritorno=s->vettore[s->ultimo];
		s->ultimo--;

		double percentuale_occupazione = (float)s->ultimo/(float)s->dimensione;
		if(percentuale_occupazione<=0.3){
			printf("Lo stack è oneroso, diminuisco la grandezza\n");
			modifica_dimensione_array(s,3);
		}
	}

	return elemento_ritorno;
}

void modifica_dimensione_array(stack* s, int fattore){
	int nuova_dimensione=0;
	
	if(fattore==3)
		nuova_dimensione = (int)((float)s->dimensione/fattore);
	else
		nuova_dimensione = s->dimensione*2;

	s->vettore = realloc(s->vettore, sizeof(int)*nuova_dimensione);
    s->dimensione = nuova_dimensione;
}

int stack_pieno(stack* s){
	if(s->dimensione==s->ultimo+1)
		return 1;
	return 0;
}

int stack_vuoto(stack* s){
	if(s->ultimo==-1)
		return 1;
	return 0;
}

void svuota_stack(stack* s){
	s->ultimo=-1;
	modifica_dimensione_array(s,3);
}




