#include <stdio.h>
#include <stdlib.h>


/*riempie un vettore con valori random*/
void riempi(int*,int);

/*stampa i valori di un vettore*/
void stampa(int*,int);

/*costruisce un max heap se i sottoalberi di i sono max heap
	tempo di esecuzione: log(n), con n grandezza dell'input
*/
void maxHeap(int*,int,int);

/*costruisce un max heap a partire da un heap
	tempo di esecuzione n*log(n)
*/
void costruisci_maxHeap(int*,int);

/*scambia due caselle all'interno dell'array*/
void scambia(int*,int,int);

/*restituisce il genitore di un nodo*/
int genitore(int);

/*restituisce il figlio sinistro di un nodo*/
int figlio_sinistro(int);

/*restituisce il figlio destro di un nodo*/
int figlio_destro(int);

/*stampa i valori di un vettore che rappresenta un heap*/
void stampa_con_informazioni(int*,int);



int main(){
	printf("Avviamo la creazione di un max-heap di 20 elementi\n");

	int vettore[20];

	printf("Riempio l'heap con elementi random\n");
	riempi(vettore,20);

	printf("Ecco i valori dell'heap\n");
	stampa(vettore,20);

	printf("Avvio la procedura per trasformare l'heap in un max-heap\n");
	costruisci_maxHeap(vettore,20);

	printf("Ecco i valori dell'heap\n");
	stampa(vettore,20);

	printf("Qui maggiori informazioni\n");
	stampa_con_informazioni(vettore,20);
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

void stampa_con_informazioni(int* vettore, int lunghezza){
	int i=0;
	for(;i<lunghezza;i++){
		int gen = vettore[genitore(i)];
		int sx = vettore[figlio_sinistro(i)];
		int dx = vettore[figlio_destro(i)];

		if(sx>100)
			sx=-1;
		if(dx>100)
			dx=-1;
		if(gen>100)
			gen=-1;

		printf("Nodo %d\tGenitore %d\tFiglio sinistro %d\tFiglio destro %d\t\n",vettore[i],gen,sx,dx);
	}
	printf("\n");
}


int genitore(int i){
	return (i-1)/2;
}

int figlio_destro(int i){
	return 2*i+2;
}

int figlio_sinistro(int i){
	return 2*i+1;
}

void costruisci_maxHeap(int* vettore, int lunghezza){
	int i=(lunghezza/2);
	i=i-1;

	for(;i>=0;i--)
		maxHeap(vettore,lunghezza,i);
}

void maxHeap(int* vettore,int lunghezza, int indice){
	int s=figlio_sinistro(indice);
	int d=figlio_destro(indice);
	int massimo=indice;

	if(s<=lunghezza && vettore[s]>vettore[indice])
		massimo=s;
	else
		massimo=indice;
	if(d<=lunghezza && vettore[d]>vettore[massimo])
		massimo=d;

	if(massimo!=indice){
		scambia(vettore,indice,massimo);
		maxHeap(vettore,lunghezza,massimo);
	}
}

void scambia(int* vettore, int i, int j){
	int tmp = vettore[i];
	vettore[i]=vettore[j];
	vettore[j]=tmp;
}
