#include <stdio.h>
#include <stdlib.h>

/*funzione di ordinamento crescente
	-caso peggiore,caso medio ordine di n^2,
	-caso migliore ordine di n
*/
void bubbleSort(int*, int);

/*funzione di ordinamento crescente, stampa l'evoluzione dell'ordinamento a ogni passo*/
void bubbleSort_stampa(int*, int);


int main(){
	int vettore[10];

	//riempio il vettore con valori random
	for(int i=0;i<10;i++)
		vettore[i]=rand() % 10 + 1;

	//stampo il vettore
	printf("Attualmente il vettore contiene i seguenti valori\n");
	for(int i=0;i<10;i++)
		printf("%d ",vettore[i]);

	//ordino il vettore
	bubbleSort(vettore,10);

	printf("\nDopo l'ordinamento il vettore risulta essere il seguente:\n");
	for(int i=0;i<10;i++)
		printf("%d ",vettore[i]);

	printf("\nRendo nuovamente casuale il vettore\n");
	//riempio il vettore con valori random
	for(int i=0;i<10;i++)
		vettore[i]=rand() % 10 + 1;

	for(int i=0;i<10;i++)
		printf("%d ",vettore[i]);

	printf("\nDi seguito l'evoluzione dell'ordinamento\n");
	bubbleSort_stampa(vettore,10);
}

void bubbleSort(int* v, int lunghezza){
	int scambio=1;
	while(scambio==1){
		scambio=0;
		for(int i=0;i<lunghezza-1;i++)
			if(v[i]>v[i+1]){
				scambio=1;
				int tmp=v[i+1];
				v[i+1]=v[i];
				v[i]=tmp;
			}
	}
}

void bubbleSort_stampa(int* v,int lunghezza){
	int scambio=1;
	while(scambio==1){
		scambio=0;
		for(int i=0;i<lunghezza-1;i++)
			if(v[i]>v[i+1]){
				scambio=1;
				int tmp=v[i+1];
				v[i+1]=v[i];
				v[i]=tmp;
				for(int k=0;k<lunghezza;k++)
					printf("%d ",v[k]);
				printf("\n");
			}
	}

}
