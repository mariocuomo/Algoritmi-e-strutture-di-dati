#include <stdio.h>
#include <stdlib.h>

/*riempie un vettore con valori random*/
void riempi(int*,int);

/*stampa i valori di un vettore*/
void stampa(int*,int);

/*verifica se un array è ordinato in maniera crescente
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int e_ordinato(int*,int);

/*funzione di ordinamento crescente
	caso migliore: ordine di n
	caso peggiore: ordine di n*n!
*/
void stupidSort(int*,int);

/*funzione per mischiare gli elementi di un array*/
void mischia(int*, int);


int main(){
	int vettore[10];

	printf("Questa simulazione ordina un array con l'algoritmo di ordinamento Stupid Sort\n");
	printf("Creo un vettore di 10 elementi random\n");

	riempi(vettore,10);
	printf("Ecco i valori generati\n");
	stampa(vettore,10);

	printf("Avvio lo Stupid Sort\n");
	stupidSort(vettore,10);

	printf("Ecco i valori ordinati\n");
	stampa(vettore,10);
}

void riempi(int* vettore,int lunghezza){
	int i=0;
	for(;i<lunghezza;i++)
		vettore[i]=rand() % 100 + 1;
}

void stampa(int* vettore, int lunghezza){
	int i=0;
	for(;i<lunghezza;i++)
		printf("%d ",vettore[i]);
	printf("\n");
}

int e_ordinato(int* vettore, int lunghezza){
	int i=0;
	for(;i<lunghezza-1;i++)
		if(vettore[i]>vettore[i+1])
			return 0;
	return 1;
}

void stupidSort(int* vettore, int lunghezza){
	while(e_ordinato(vettore,lunghezza)!=1)
		mischia(vettore,lunghezza);
}

void mischia(int* vettore, int lunghezza){
	if (lunghezza > 1) 
    {
        size_t i;
        for (i=0; i<lunghezza-1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (lunghezza - i) + 1);
          int t = vettore[j];
          vettore[j] = vettore[i];
          vettore[i] = t;
        }
    }
}
