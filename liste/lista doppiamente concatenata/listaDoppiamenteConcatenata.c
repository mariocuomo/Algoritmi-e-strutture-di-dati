#include <stdio.h>
#include <stdlib.h>

/*
STRUTTURA CHE RAPPRESENTA UN ELEMENTO DI UNA LISTA DOPPIAMENTE CONCATENATA CONTENTENTE I SEGUENTI CAMPI:
	-info: è l'intero considerato
	-next: è un puntatore al prossimo elemento della lista
	-prev: è un puntatore all'elemento precedente della lista
*/
typedef struct elem{
	int info;
	struct elem* next;
	struct elem* prev;
}elemento;

/*lista è un puntatore a un elemento*/
typedef elemento* lista;

/*crea una lista vuota*/
lista crea_lista();

/*funzione per inserire un elemento in coda alla lista, costosa perchè scorre tutti gli elementi*/
void aggiungi_elemento_in_coda(lista*,int);

/*funzione per inserire un elemento in coda alla lista*, costo costante/
void aggiungi_elemento_in_testa(lista*,int);

/*funzione che elimina l'elemento in testa alla lista, costo costante*/
void elimina_elemento_in_testa(lista*);

/*funzione che elimina l'elemento in coda alla lista, costosa proporzionale a n numeri di elementi della lista*/
void elimina_elemento_in_coda(lista*);

/*elimina l'elemento dato il riferimento*/
void elimina_elemento(lista*,elemento*);

/*ritorna il numero di elementi della lista*/
int grandezza_lista(lista);

/*funzione che indica se una lista è vuota oppure no
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int lista_vuota(lista);

/*funzione di supporto per stampare gli elementi contenuti in una lista*/
void stampa_lista(lista);
/*funzione di supporto per stampare gli elementi contenuti in una lista partendo dalla coda*/
void stampa_lista_coda(lista);


int main(){
	printf("Questa simulazione crea una lista di 5 elementi\n");
	lista miaLista = crea_lista();
	stampa_lista(miaLista);
	printf("Riempio inserendo 5 elementi in coda\n");
	for(int i=0;i<5;i++){
		int valore=rand() % 100 + 1;
		aggiungi_elemento_in_coda(&miaLista,valore);
		printf("Ho inserito il valore %d e la lista è grande %d\n",valore,grandezza_lista(miaLista));
	}

	printf("La lista contiene i seguenti elementi\n");
	stampa_lista(miaLista);

	printf("Elimino tutti gli elementi partendo dalla testa uno per uno\n");
	for(int i=0;i<5;i++){
		elimina_elemento_in_testa(&miaLista);
		stampa_lista(miaLista);
	}

	printf("Riempio inserendo 5 elementi in testa\n");
	for(int i=0;i<5;i++){
		int valore=rand() % 100 + 1;
		aggiungi_elemento_in_testa(&miaLista,valore);
		printf("Ho inserito il valore %d e la lista è grande %d\n",valore,grandezza_lista(miaLista));
	}

	printf("La lista contiene i seguenti elementi\n");
	stampa_lista(miaLista);

	printf("Elimino il 2(in base 0) elemento, ovvero %d\n",miaLista->next->next->info);
	elimina_elemento(&miaLista,miaLista->next->next);
	
	printf("La lista contiene i seguenti elementi\n");
	stampa_lista(miaLista);

	printf("Elimino l'elemnto in coda\n");
	elimina_elemento_in_coda(&miaLista);

	printf("La lista contiene i seguenti elementi\n");
	stampa_lista(miaLista);

	printf("Stampo prima la lista dalla testa alla coda e poi dalla coda alla testa\n");
	stampa_lista(miaLista);
	stampa_lista_coda(miaLista);


}


lista crea_lista(){
	return NULL;
}

void aggiungi_elemento_in_coda(lista* lst, int valore){
	if(lista_vuota(*lst)==1){
		elemento* nuovo = malloc(sizeof(elemento));
		nuovo->info=valore;
		nuovo->next=NULL;
		nuovo->prev=NULL;
		(*lst)=nuovo;
	}
	else{
		elemento* scanner = (*lst);
		while(scanner->next!=NULL)
			scanner=scanner->next;
		elemento* nuovo = malloc(sizeof(elemento));
		nuovo->info=valore;
		nuovo->next=NULL;
		nuovo->prev=scanner;
		scanner->next=nuovo;
	}
}

void aggiungi_elemento_in_testa(lista* lst, int valore){
	elemento* nuovo = malloc(sizeof(elemento));
	nuovo->info=valore;
	nuovo->prev=NULL;
	if(lista_vuota(*lst)==1){
		nuovo->next=NULL;
	}
	else{
		nuovo->next=(*lst);
		nuovo->next->prev = nuovo;
	}

	(*lst)=nuovo;
}

void elimina_elemento_in_testa(lista* lst){
	if(lista_vuota(*lst)==1)
		printf("La lista e' già vuota!\n");
	else{
		if(grandezza_lista(*lst)==1)
			(*lst)=NULL;
		else{
			(*lst)=(*lst)->next;
			(*lst)->prev=NULL;
		}
	}
}

void elimina_elemento_in_coda(lista* lst){
	if(lista_vuota(*lst)==1)
		printf("La lista e' già vuota!\n");
	else{
		if(grandezza_lista(*lst)==1)
			(*lst)=NULL;
		else{
			elemento* scanner = (*lst);
			while(scanner->next->next!=NULL)
				scanner=scanner->next;
			scanner->next=NULL;
		}
	}
}

void elimina_elemento(lista* lst,elemento* el){
	if(lista_vuota(*lst)==1)
		printf("La lista è vuota, cosa vuoi eliminare?\n");
	else{
		printf("%d\n",el->info);
		el->next->prev=el->prev;
		el->prev->next=el->next;
		free(el);
	}
}


int lista_vuota(lista lst){
	if(lst==NULL)
		return 1;
	return 0;
}

int grandezza_lista(lista lst){
	if(lista_vuota(lst)==1)
		return 0;
	else
		return 1+grandezza_lista(lst->next);
}

void stampa_lista(lista lst){
	if(lista_vuota(lst)==1)
		printf("La lista e' vuota\n");
	else{
		while(lst!=NULL){
			printf("%d ",lst->info);
			lst=lst->next;
		}
		printf("\n");
	}
}

void stampa_lista_coda(lista lst){
	if(lista_vuota(lst)==1)
		printf("La lista e' vuota\n");

	else{
		while(lst->next!=NULL){
				lst=lst->next;
		}
		while(lst->prev!=NULL){
			printf("%d ",lst->info);
			lst=lst->prev;
		}
		printf("%d ",lst->info);
		printf("\n");
	}
}