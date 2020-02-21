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
	countingSort(vettore,20);

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


int calcola_massimo(int* v, int lunghezza){
	int massimo=v[0];
	for(int i=1;i<lunghezza;i++)
		if(v[i]>massimo)
			massimo=v[i];
	return massimo;
}

void countingSort(int* v, int lunghezza){
	int max=calcola_massimo(v,lunghezza);
	int vettoreContatore[max+1];
	//setto a zero i contatori
	for(int i=0;i<max;i++)
		vettoreContatore[i]=0;

	//conta tutte le occorrenze
	for(int i=0;i<lunghezza;i++)
		vettoreContatore[v[i]]++;

	int i=0; //scandisco vettoreContatore
	int j=0; //posizione in vettore di partenza
	for(int i=0;i<max;i++){
		int numeroOccorrenze = vettoreContatore[i];
		while(numeroOccorrenze!=0){
			v[j]=i;
			numeroOccorrenze--;
			j++;
		}
	}
}

void countingSort_stampa(int* v,int lunghezza){
	int max=calcola_massimo(v,lunghezza);
	printf("Calcolo il massimo contenuto nel vettore e creo un array di quella dimensione\n");
	printf("Il massimo trovato e' %d\n",max);
	int vettoreContatore[max+1];
	//setto a zero i contatori
	for(int i=0;i<max+1;i++)
		vettoreContatore[i]=0;

	//conta tutte le occorrenze
	for(int i=0;i<lunghezza;i++)
		vettoreContatore[v[i]]++;

	printf("Per ogni indice, calcolo quante occorrenze sono presenti di quel valore\n");
	printf("Per il vettore dato si ha:\n");
	
	for(int i=0;i<max+1;i++)
		printf("Il valore %d compare %d volte\n",i,vettoreContatore[i]);

	printf("Creo il vettore finale conoscendo queste informazioni\n");	


	int i=0; //scandisco vettoreContatore
	int j=0; //posizione in vettore di partenza
	for(int i=0;i<max+1;i++){
		int numeroOccorrenze = vettoreContatore[i];
		while(numeroOccorrenze!=0){
			v[j]=i;
			numeroOccorrenze--;
			j++;
		}
		printf("Il vettore attualmente e' il seguente:\n");
		for(int k=0;k<lunghezza;k++)
			printf("%d ",v[k]);
		printf("\n");
	}

}

