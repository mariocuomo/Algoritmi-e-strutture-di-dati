#include <stdio.h>
#include <stdlib.h>

/*funzione di ordinamento crescente ordine di n+m
	-n, dimensione dell'input
	-m, massimo valore dell'input
*/
void countingSort(int*, int);

/*funzione di ordinamento crescente, stampa l'evoluzione dell'ordinamento a ogni passo*/
void countingSort_stampa(int*, int);

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
	coiuntingSort(vettore,20);

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
	countingSort_stampa(vettore,20);
}

void countingSort(int* v, int lunghezza){
	int massimo=calcola_massimo(v,lunghezza);
	int vettore[massimo];
	printf("%d",vettore[0]);
	return 1;
}

void countingSort_stampa(int* v,int lunghezza){


}
