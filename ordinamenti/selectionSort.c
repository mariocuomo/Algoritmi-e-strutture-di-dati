#include <stdio.h>
#include <stdlib.h>

/*funzione di ordinamento crescente
	-caso peggiore, caso medio, caso migliore ordine di n^2
*/
void selectionSort(int*, int);

/*funzione di ordinamento crescente, stampa l'evoluzione dell'ordinamento a ogni passo*/
void selectionSort_stampa(int*, int);

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
	selectionSort(vettore,10);

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
	selectionSort_stampa(vettore,10);

}

void selectionSort(int* v, int lunghezza){
	for(int i=0;i<lunghezza-1;i++){
		int minimo=i;
		for(int j=i+1;j<lunghezza;j++){
			if(v[j]<v[minimo])
				minimo=j;
		}

		int tmp = v[i];
		v[i]=v[minimo];
		v[minimo]=tmp;
	}
}

void selectionSort_stampa(int* v, int lunghezza){
	for(int i=0;i<lunghezza-1;i++){
		int minimo=i;
		for(int j=i+1;j<lunghezza;j++){
			if(v[j]<v[minimo])
				minimo=j;
		}
		for(int k=0;k<lunghezza;k++)
			printf("%d ",v[k]);
		printf("Trovato il minimo=%d che sarà scambiato con %d in posizione %d\n",v[minimo],v[i],i);

		int tmp = v[i];
		v[i]=v[minimo];
		v[minimo]=tmp;
	}
}

