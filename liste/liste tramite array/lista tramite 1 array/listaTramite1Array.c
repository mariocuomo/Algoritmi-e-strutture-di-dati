#include <stdio.h>

/*
STRUTTURA CHE RAPPRESENTA UNA LISTA CONTENTENTE I SEGUENTI CAMPI:
	-info: array di interi positivi di valori
		-posizione i: valore
		-posizione i+1: indice del precedente
		-posizione i+2: indice del successivo

	-dim: indica la dimensione massima della lista
	-head: indice della testa
	-free: indice della prima posizione libera
*/
typedef struct el{
	int* info;

	int dim;
	int head;
	int free;
}lista;


/*funzione per creare una lista vuota di elementi*/
lista* creaLista(int);

/*funzione per svuotare una lista*/
void svuota_lista(lista*);

/*verifica se una lista è vuota
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int e_vuota(lista*);

/*verifica se una lista è piena
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int e_piena(lista*);

/*funzione per aggiungere un elemento in testa alla lista*/
void aggiungi_elemento(lista*,int);

/*funzione per eliminare l'elemento in testa della lista*/
void elimina_testa(lista*);

/*funzione di supporto per stampare la lista*/
void stampa(lista*);


int main(){
	printf("Questa simulazione crea una lista di 5 elementi\n");
	lista* miaLista=creaLista(5);
	int i=0;


	if(e_vuota(miaLista)==1)
		printf("La lista e' vuota\n");
	else
		printf("La lista non e' vuota\n");

	printf("Comincio a riempire la lista con 5 elementi\n");
	for(;i<5;i++){
		int valore=rand() % 100 + 1;
		printf("Aggiungo il valore %d\n",valore);
		aggiungi_elemento(miaLista,valore);
	}

	stampa(miaLista);


	printf("A questo punto svuoto l'intera lista\n");
	svuota_lista(miaLista);
	stampa(miaLista);

	printf("Comincio a riempire la lista con 2 elementi\n");
	for(i=0;i<2;i++){
		int valore=rand() % 100 + 1;
		printf("Aggiungo il valore %d\n",valore);
		aggiungi_elemento(miaLista,valore);
	}

	stampa(miaLista);

	printf("Elimino la testa della lista\n");
	elimina_testa(miaLista);

	stampa(miaLista);

		printf("Aggiungo i restanti 4 elementi\n");
	for(i=0;i<4;i++){
		int valore=rand() % 100 + 1;
		printf("Aggiungo il valore %d\n",valore);
		aggiungi_elemento(miaLista,valore);
	}

	stampa(miaLista);

	printf("A questo punto svuoto l'intera lista\n");
	for(i=0;i<5;i++)
		elimina_testa(miaLista);

	stampa(miaLista);

	printf("Provo a eliminare un elemento che non c'e'\n");
	elimina_testa(miaLista);


}

lista* creaLista(int dimensione){
	lista* nuovaLista = malloc(sizeof(lista));
	nuovaLista->info=malloc(sizeof(int)*dimensione*3);

	nuovaLista->dim=dimensione*3;
	nuovaLista->head=-1;
	nuovaLista->free=0;

	svuota_lista(nuovaLista);

	return nuovaLista;
}

void svuota_lista(lista* lst){
	int i=0;



	for(;i<lst->dim;i+=3){
		lst->info[i]=0;
		lst->info[i+1]=i-3;
		lst->info[i+2]=i+3;
	}

	lst->info[lst->dim-3]=-1;
	lst->info[0]=-1;

	lst->head=-1;
	lst->free=0;
}

int e_vuota(lista* lst){
	if(lst->head==-1)
		return 1;
	return 0;
}

int e_piena(lista* lst){
	if(lst->free==-1)
		return 1;
	return 0;
}

void aggiungi_elemento(lista* lst, int valore){
	if(e_piena(lst)==1){
		printf("Mi dispiace ma la lista e' piena\n");
		return;
	}
	
	int posizione=lst->free;

	//lst->next=lst->info+2
	//lst->prev=lst->info+1

	lst->free = lst->info[lst->free+2];

	if(e_piena(lst)==0)
		lst->info[lst->free+1]=-1;

	lst->info[posizione]=valore;
	lst->info[posizione+1]=-1;
	lst->info[posizione+2]=lst->head;

	if(e_vuota(lst)==0)
		lst->info[lst->head+1]=posizione;

	lst->head=posizione;

}


void elimina_testa(lista* lst){
	if(e_vuota(lst)==1){
		printf("Attento, la lista è vuota\n");
		return;
	}

	int vecchia_posizione_free=lst->free;
	int vecchia_posizione_head=lst->head;

	lst->head=lst->info[vecchia_posizione_head+2];
	lst->info[lst->head+1]=-1;

	lst->free=vecchia_posizione_head;
	lst->info[lst->free+2]=vecchia_posizione_free;
	lst->info[vecchia_posizione_free+1]=vecchia_posizione_head;
	
}

void stampa(lista* lst){
	if(e_vuota(lst)==1){
		printf("La lista è vuota\n");
		return;
	}

	printf("La lista contiene i seguenti elementi\n");
	int i=lst->head;
	while(i!=-1){
		printf("%d ",lst->info[i]);
		i=lst->info[i+2];
	}
	printf("\n");
}
