#include <stdio.h>
#include <stdlib.h>

/*funzione di ordinamento crescente. Il tempo di calcolo varia
	-caso migliore: ordine di n
	-caso peggiore, medio : ordine di n^2
*/
void insertionSort(int*, int);

/*funzione di ordinamento crescente, stampa l'evoluzione dell'ordinamento a ogni passo*/
void insertionSort_stampa(int*, int);

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
	insertionSort(vettore,20);

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
	insertionSort_stampa(vettore,20);
}


void insertionSort(int* v, int lunghezza){
	for(int j=1;j<lunghezza;j++){
		int chiave = v[j];
		int i=j-1;
		while(i>=0 && v[i]>chiave){
			v[i+1]=v[i];
			i--;
		}
		v[i+1]=chiave;
	}
}

void insertionSort_stampa(int* v,int lunghezza){
	for(int j=1;j<lunghezza;j++){
		int chiave = v[j];
		int i=j-1;
		while(i>=0 && v[i]>chiave){
			v[i+1]=v[i];
			i--;
		}
		v[i+1]=chiave;

		for(int k=0;k<lunghezza;k++)
			printf("%d ",v[k]);
		printf("\n");
	}
}


