#include <stdio.h>
#include <stdlib.h>

/*funzione di ordinamento crescente
	-caso peggiore = ordine di n*n
	-caso migliore, medio =  ordine di nlogn
	con n numeri di elementi*/
void quickSort(int*,int);

/*funzione di ordinamento crescente, stampa l'evoluzione*/
void quickSort_stampa(int*,int);

/*ordina un array da una posizione di partenza a una di arrivo, stampa l'evolizone*/
void ordina_stampa(int*,int,int);

/*ordina un array da una posizione di partenza a una di arrivo*/
void ordina(int*,int,int);

/*ritorna una posizione i tale per cui tutti gli elementi prima di i sono minori di A[i] mentre i successivi sono maggiori di A[i]*/
int partiziona(int*,int,int);

/*funzione di supporto per riempire un vettore con valori random*/
void riempi(int*,int);

/*funzione di supporto per stampare un vettore*/
void stampa(int*,int);

/*scambia i valori di due posizioni date in un array*/
void scambia(int*,int,int);

int main(){
	printf("La seguente simulazione ordina un vettore di 20 elementi in ordine crescente\n");

	int vettore[20];

	printf("Riempio il vettore con numeri random\n");
	riempi(vettore,20);
	printf("Ecco i valori generati\n");
	stampa(vettore,20);

	printf("Ordino il vettore\n");
	quickSort(vettore,20);

	printf("Ecco il vettore ordinato\n");
	stampa(vettore,20);
	
	printf("Rendo nuovamente il vettore con numeri random\n");
	riempi(vettore,20);
	printf("Ecco i valori generati\n");
	stampa(vettore,20);

	printf("Ecco come avviene l'ordinamento\n");
	quickSort_stampa(vettore,20);

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

void quickSort(int* vettore, int lunghezza){
	ordina(vettore,0,lunghezza);
}

void ordina(int* vettore, int inizio, int fine){
	if(inizio<fine){
		int meta=partiziona(vettore,inizio,fine);
		ordina(vettore,inizio,meta-1);
		ordina(vettore,meta+1,fine);
	}
}

int partiziona(int* vettore, int inizio, int fine){
	int i=inizio;
	int j=inizio;

	for(;j<fine;j++){
		if(vettore[j]<=vettore[fine]){
			scambia(vettore,i,j);
			i++;
		}
	}

	scambia(vettore,i,fine);
	return i;
}

void scambia(int* vettore, int i, int j){
	int tmp=vettore[i];
	vettore[i]=vettore[j];
	vettore[j]=tmp;
}

void quickSort_stampa(int* vettore, int lunghezza){
	ordina_stampa(vettore,0,lunghezza);
}

void ordina_stampa(int* vettore, int inizio, int fine){
	if(inizio<fine){
		int meta=partiziona(vettore,inizio,fine);

		if(inizio==0 && fine==19){
			printf("Nella prima iterazione è stato scelto come pivot il valore %d in posizione %d \n",vettore[meta],meta);
			printf("L'array e' stato diviso in due parti\n");
			printf("Ciò che si trova prima del pivot risulta essere minore di esso\n");
			printf("Ciò che si trova dopo il pivot risulta essere maggiore di esso\n");

			if(meta<=7 && meta>=8)
				printf("Il pivot è stato scelto in maniera ottimale\n");
			else
				printf("Il pivot non è stato scelto in maniera ottimale\n");
			stampa(vettore,20);


		}

		ordina_stampa(vettore,inizio,meta-1);
		ordina_stampa(vettore,meta+1,fine);
	}
}

