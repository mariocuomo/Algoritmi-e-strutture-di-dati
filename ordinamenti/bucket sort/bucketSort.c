#include <stdio.h>
#include <stdlib.h>


/*
STRUTTURA CHE RAPPRESENTA UNO ELEMENTO DI UNA LISTA SEMPLICEMENTE CONCATENATA CONTENTENTE I SEGUENTI CAMPI:
	-info: è l'intero considerato
	-next: è un puntatore al prossimo elemento della lista
*/
typedef struct elem{
	int info;
	struct elem* next;
}elemento;


/*lista è un puntatore a un elemento*/
typedef elemento* lista;

/*funzione per creare una nuova lista*/
lista crea_lista();

/*aggiunge un elemento in testa, costo unitario*/
void aggiungi_elemento_in_testa(lista*,int);

/*funzione di supporto per stampare tutti gli elementi della lista*/
void stampa_lista(lista);

/*funzione di ordinamento crescente ordine di n+m
	-n, dimensione dell'input
	-m, massimo valore dell'input
*/
void bucketSort(int*, int);

/*funzione di ordinamento crescente, stampa l'evoluzione dell'ordinamento a ogni passo*/
void bucketSort_stampa(int*, int);

/*funzione di supporto per calcolare il massimo di un array*/
int calcola_massimo(int*,int);

int main(){
	int vettore[20];

	//riempio il vettore con valori random
	for(int i=0;i<20;i++)
		vettore[i]=rand() % 10 + 1;

	//stampo il vettore
	printf("Attualmente il vettore contiene i seguenti valori\n");
	for(int i=0;i<20;i++)
		printf("%d ",vettore[i]);

	//ordino il vettore
	bucketSort(vettore,20);

	printf("\nDopo l'ordinamento il vettore risulta essere il seguente:\n");
	for(int i=0;i<20;i++)
		printf("%d ",vettore[i]);

	printf("\nRendo nuovamente casuale il vettore\n");
	//riempio il vettore con valori random
	for(int i=0;i<20;i++)
		vettore[i]=rand() % 10 + 1;

	for(int i=0;i<20;i++)
		printf("%d ",vettore[i]);

	printf("\nDi seguito l'evoluzione dell'ordinamento\n");
	bucketSort_stampa(vettore,20);
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

int calcola_massimo(int* v, int lunghezza){
	int massimo=v[0];
	for(int i=1;i<lunghezza;i++)
		if(v[i]>massimo)
			massimo=v[i];
	return massimo;
}

void bucketSort(int* v, int lunghezza){
	int max=calcola_massimo(v,lunghezza);
	lista vettoreBucket[max+1];

	//setto a NULL i bucket
	for(int i=0;i<max+1;i++)
		vettoreBucket[i]=crea_lista();

	//riempio i bucket
	for(int i=0;i<lunghezza;i++)
		aggiungi_elemento_in_testa(&vettoreBucket[v[i]],v[i]);

	//attacco i bucket
	int i=0; //indica la posizione nel vettore bucket
	int j=0; //indica la posizione di salvataggio nel vettore di partenza
	for(;i<max+1;i++){
		lista scanner = vettoreBucket[i];
		while(scanner!=NULL){
			v[j]=scanner->info;
			j++;
			scanner=scanner->next;
		}
	}

}

void bucketSort_stampa(int* v,int lunghezza){
	int max=calcola_massimo(v,lunghezza);
	lista vettoreBucket[max+1];

	//setto a NULL i bucket
	for(int i=0;i<max+1;i++)
		vettoreBucket[i]=crea_lista();

	//riempio i bucket
	for(int i=0;i<lunghezza;i++)
		aggiungi_elemento_in_testa(&vettoreBucket[v[i]],v[i]);


	//stampo i bucket
	for(int i=0;i<max+1;i++){
		printf("bucket %d contiene: ",i);
		stampa_lista(vettoreBucket[i]);
		printf("\n");
	}

	//attacco i bucket
	int i=0; //indica la posizione nel vettore bucket
	int j=0; //indica la posizione di salvataggio nel vettore di partenza
	for(;i<max+1;i++){
		lista scanner = vettoreBucket[i];
		while(scanner!=NULL){
			v[j]=scanner->info;
			j++;
			scanner=scanner->next;
		}
	}
}

void stampa_lista(lista lst){
	if(lst==NULL)
		printf("nessun elemento");
	else{
		while(lst!=NULL){
			printf("%d ",lst->info);
			lst=lst->next;
		}
	}
}

