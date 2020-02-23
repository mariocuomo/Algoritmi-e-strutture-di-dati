#include <stdio.h>
#include <stdlib.h>

/*funzione di ordinamento, ordine di nlogn, con n numeri di elementi*/
void mergeSort(int*,int,int);

/*funzione di supporto che effettua la fusione tra due sequenze ordinate all'interno di un array*/
void merge(int*,int,int,int);

/*funzione di ordinamento crescente, stampa l'evoluzione dell'ordinamento a ogni passo*/
void mergeSort_stampa(int*,int,int);

int main(){
	int i=0;
	int vettore[20];


	printf("Questa simulazione ordina una sequenza di 20 numeri\n");

	for(i=0;i<20;i++)
		vettore[i]=rand() % 100 + 1;

	printf("Attualmente il vettore contiene i seguenti elementi:\n");
	for(i=0;i<20;i++)
		printf("%d ",vettore[i]);

	printf("\nOrdino il vettore con il merge sort\n");
	mergeSort(vettore,0,19);

	printf("Dopo l'ordinamento il vettore contiene i seguenti elementi\n");
	for(i=0;i<20;i++)
		printf("%d ",vettore[i]);

	printf("\nRendo nuovamente il vettore casuale\n");
	for(i=0;i<20;i++)
		vettore[i]=rand() % 100 + 1;

	printf("Attualmente il vettore contiene i seguenti elementi:\n");
	for(i=0;i<20;i++)
		printf("%d ",vettore[i]);

	printf("\n\nEcco come avviene l'ordinamento passo dopo passo");
	mergeSort_stampa(vettore,0,19);

	printf("Dopo l'ordinamento il vettore contiene i seguenti elementi\n");
	for(i=0;i<20;i++)
		printf("%d ",vettore[i]);

}

void mergeSort(int* vettore, int inizio, int fine){
	if(inizio<fine){
		int meta=(inizio+fine)/2;
		mergeSort(vettore,inizio,meta);
		mergeSort(vettore,meta+1,fine);
		merge(vettore,inizio,meta,fine);
	}
}

void merge(int* vettore, int inizio, int meta, int fine){
	int i=0;
	int j=0;
	int k=0;

	int vettoreSupporto[100];

	i=inizio;
	j=meta+1;

	while(i<=meta && j<=fine){
		if(vettore[i]<vettore[j]){
			vettoreSupporto[k]=vettore[i];
			i++;
		}
		else{
			vettoreSupporto[k]=vettore[j];
			j++;
		}
		k++;
	}

	while(i<=meta){
		vettoreSupporto[k]=vettore[i];
		i++;
		k++;
	}
	while(j<=fine){
		vettoreSupporto[k]=vettore[j];
		j++;
		k++;
	}

	for(k=inizio;k<=fine;k++)
		vettore[k]=vettoreSupporto[k-inizio];

}

void mergeSort_stampa(int* vettore, int inizio, int fine){
	if(inizio<fine){
		int meta=(inizio+fine)/2;
		mergeSort(vettore,inizio,meta);
		mergeSort(vettore,meta+1,fine);

		if(inizio==0 && fine==19){
			printf("\nDopo aver diviso in due sottosequenze il vettore e averle ordinate, ho la seguente situazione\n");
			int i=0;
			printf("Prima meta' dell'array: ");
			for(;i<=fine;i++){
				if(i==meta+1)
					printf("\nSeconda meta' dell'array: ");
				printf("%d ",vettore[i]);
			}
			printf("\nA questo punto devo effettuare una fusione tra le due sottosequenze\n");
		}
		merge(vettore,inizio,meta,fine);
	}
}

