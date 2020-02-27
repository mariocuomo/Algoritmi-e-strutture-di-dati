#include <stdio.h>
#include <stdlib.h>


/*
STRUTTURA CHE RAPPRESENTA UNA CODA DI PRIORITA' CONTENTENTE I SEGUENTI CAMPI:
	-vettore: array di interi positivi che codifica un max heap
	-dimensione_max: numero di elementi massimo dell'array
	-dimensione_attuale: numero di elementi attualmente all'interno
*/
typedef struct mia_coda{
	int *vettore;
	int dimensione_max;
	int dimensione_attuale;
}coda;


/*=======FUNZIONI CHE LAVORANO SULLA CODA DI PRIORITA'========*/

/*crea una coda a partire da una dimensione di base*/
coda* crea_coda(int);

/*verifica se una coda è vuota
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int e_vuota(coda*);

/*estrae il massimo dalla coda di priorità, tempo di calcolo log(n), con n numero di elementi*/
int estrai_massimo(coda*);

/*inserisci un elemento nella coda*/
void inserisci(coda*,int);



/*=======FUNZIONI CHE LAVORANO SU L'HEAP========*/


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
	printf("Questa simulazione crea una coda di priorita' che contiene al massimo 20 elementi.\n");

	coda* miaCoda = crea_coda(20);
	int i=0;

	printf("Riempio la coda con 10 valori random\n");
	for(;i<10;i++){
		miaCoda->vettore[i]=rand() % 100 + 1;
		miaCoda->dimensione_attuale++;
	}

	printf("Ecco i valori inseriti attualmente\n");
	for(i=0;i<10;i++){
		printf("%d ",miaCoda->vettore[i]);
	}

	printf("\nAvvio la procedura per trasformare il vettore della in un max-heap\n");
	costruisci_maxHeap(miaCoda->vettore,miaCoda->dimensione_attuale);

	printf("Ecco i valori ordinati come un max-heap\n");
	stampa_con_informazioni(miaCoda->vettore, miaCoda->dimensione_attuale);

	printf("Estraggo il valore con massima priorità %d, ovvero la radice\n",estrai_massimo(miaCoda));
	printf("La coda è stata rigenerata per soddisfare la condizione di max heap\n");

	stampa_con_informazioni(miaCoda->vettore, miaCoda->dimensione_attuale);

	printf("Inserisco il valore 62 nella coda di priorità");
	inserisci(miaCoda,62);
	printf("La coda è stata rigenerata per soddisfare la condizione di max heap\n");
	stampa_con_informazioni(miaCoda->vettore, miaCoda->dimensione_attuale);

	printf("Inserisco il valore 90 nella coda di priorità");
	inserisci(miaCoda,90);
	printf("La coda è stata rigenerata per soddisfare la condizione di max heap\n");
	stampa_con_informazioni(miaCoda->vettore, miaCoda->dimensione_attuale);

}

/*=======FUNZIONI CHE LAVORANO SULLA CODA DI PRIORITA'========*/

coda* crea_coda(int dim){
	coda* nuovaCoda=malloc(sizeof(coda));
	nuovaCoda->dimensione_max=dim;
	nuovaCoda->dimensione_attuale=0;
	nuovaCoda->vettore=malloc(sizeof(int)*dim);

	return nuovaCoda;
}

int e_vuota(coda* c){
	if(c->dimensione_attuale==0)
		return 1;
	return 0;
}

int estrai_massimo(coda* c){
	if(e_vuota(c)==1){
		printf("La coda e' vuota!\n");
		return -1;
	}

	int massimo=c->vettore[0];
	c->vettore[0]=c->vettore[c->dimensione_attuale-1];
	c->dimensione_attuale--;
	maxHeap(c->vettore,c->dimensione_attuale,0);
	return massimo;
}

void inserisci(coda* c, int valore){
	c->dimensione_attuale++;
	int i = c->dimensione_attuale-1;

	while(i>0 && c->vettore[genitore(i)]<valore){
		c->vettore[i]=c->vettore[genitore(i)];
		i=genitore(i);
	}

	c->vettore[i]=valore;
}


/*=======FUNZIONI CHE LAVORANO SU L'HEAP========*/

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

void stampa_con_informazioni(int* vettore, int lunghezza){
	int i=0;
	for(;i<lunghezza;i++){
		int gen = vettore[genitore(i)];
		int sx = vettore[figlio_sinistro(i)];
		int dx = vettore[figlio_destro(i)];

		if(sx>100 || sx<0|| sx==0)
			sx=-1;
		if(dx>100 || dx<0|| dx==0)
			dx=-1;
		if(gen>100 || gen<0 || gen==0)
			gen=-1;

		printf("Nodo %d\tGenitore %d\tFiglio sinistro %d\tFiglio destro %d\t\n",vettore[i],gen,sx,dx);
	}
	printf("\n");
}

