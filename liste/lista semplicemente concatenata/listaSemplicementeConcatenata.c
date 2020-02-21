#include <stdio.h>
#include <stdlib.h>

/*
STRUTTURA CHE RAPPRESENTA UNO ELEMENTO DI UNA LISTA SEMPLICEMENTE CONCATENATA CONTENTENTE I SEGUENTI CAMPI:
	-info: è l'intero considerato
	-next: è un puntatore al prossimo elemento della lista
*/
typedef struct elem{
	int info;
	struct elem* next;
}elemento;


/*lista è un puntatore a un elemento*/
typedef elemento* lista;

/*funzione per creare una nuova lista*/
lista crea_lista();

/*aggiunge un elemento in coda, costosa perchè proporzionale al numero di elementi*/
void aggiungi_elemento_in_coda(lista*,int);

/*aggiunge un elemento in testa, costo unitario*/
void aggiungi_elemento_in_testa(lista*,int);

/*ritorna il numero di elementi nella lista*/
int grandezza_lista(lista);

/*cancella tutti gli elementi della lista, costo unitario*/
void cancella_lista(lista*);

/*verifica se la lista è vuota
	ritorno 1 in caso positivo, 0 in caso negativo
*/
int lista_vuota(lista);

/*elimina elemento in testa, costo unitario*/
void elimina_elemento_in_testa(lista*);

/*elimina elemento in coda, costosa perchè proporzionale al numero di elementi*/
void elimina_elemento_in_coda(lista*);

/*ritorna elemento in testa, costo unitario*/
int visualizza_elemento_in_testa(lista);

/*ritorna elemento in coda, costosa perchè proporzionale al numero di elementi*/
int visualizza_elemento_in_coda(lista);

/*funzione che elimina un elemento della lista dato il riferimento ad esso*/
void elimina_elemento(lista*, elemento*);

/*funzione che elimina l'i-esimo(in base 0) elemento della lista */
void elimina_elemento_i(lista*,int);

/*funzione di supporto per stampare tutti gli elementi della lista*/
void stampa_lista(lista);



int main(){
	printf("Questa simulazione crea una lista 5 elementi interi positivi\n");
	lista miaLista = crea_lista();


	//riempio la lista di 5 elementi random inseriti in coda
	printf("Riempio inserendo in coda 5 elementi\n");
	for(int i=0;i<5;i++){
		int valore=rand() % 100 + 1;
		aggiungi_elemento_in_coda(&miaLista,valore);
		printf("Ho inserito il valore %d e la lista è grande %d\n",valore,grandezza_lista(miaLista));
	}

	//stampo la lista
	stampa_lista(miaLista);

	//cancello tutti gli elementi dalla lista
	printf("\nCancello tutti gli elementi\n");
	cancella_lista(&miaLista);

	//stampo la lista
	stampa_lista(miaLista);

	//riempio la lista di 5 elementi random inseriti in testa
	printf("Riempio inserendo in testa 5 elementi\n");
	for(int i=0;i<5;i++){
		int valore=rand() % 100 + 1;
		aggiungi_elemento_in_testa(&miaLista,valore);
		printf("Ho inserito il valore %d e la lista è grande %d\n",valore,grandezza_lista(miaLista));
	}

	//stampo la lista
	stampa_lista(miaLista);

	printf("\nProvo a eliminare tutti gli elementi, uno per uno, partendo dalla coda\n");
	for(int i=0;i<5;i++){
		elimina_elemento_in_coda(&miaLista);
		stampa_lista(miaLista);	
		printf("\n");	
	}

	//riempio la lista di 5 elementi random inseriti in testa
	printf("Riempio inserendo in testa 5 elementi\n");
	for(int i=0;i<5;i++){
		int valore=rand() % 100 + 1;
		aggiungi_elemento_in_testa(&miaLista,valore);
		printf("Ho inserito il valore %d e la lista è grande %d\n",valore,grandezza_lista(miaLista));
	}
	
	//stampo la lista
	stampa_lista(miaLista);
	
	printf("\nProvo a eliminare tutti gli elementi, uno per uno, partendo dalla testa\n");
	for(int i=0;i<5;i++){
		elimina_elemento_in_testa(&miaLista);
		stampa_lista(miaLista);	
		printf("\n");	
	}

	printf("Provo a eliminare un elemento dalla lista vuota\n");
	elimina_elemento_in_coda(&miaLista);

	//riempio la lista di 5 elementi random inseriti in testa
	printf("Riempio inserendo in testa 5 elementi\n");
	for(int i=0;i<5;i++){
		int valore=rand() % 100 + 1;
		aggiungi_elemento_in_testa(&miaLista,valore);
		printf("Ho inserito il valore %d e la lista è grande %d\n",valore,grandezza_lista(miaLista));
	}

	printf("Il valore in testa e' %d mentre quello in coda e' %d\n", visualizza_elemento_in_testa(miaLista),visualizza_elemento_in_coda(miaLista));

	//stampo la lista
	stampa_lista(miaLista);

	printf("\nElimino l'elemento in posizione 2 (base 0)\n");
	elimina_elemento_i(&miaLista,2);

	//stampo la lista
	stampa_lista(miaLista);

	printf("\nElimino l'elemento %d\n",miaLista->next->next->info);
	elimina_elemento(&miaLista,miaLista->next->next);

	//stampo la lista
	stampa_lista(miaLista);
	
}


lista crea_lista(){
	return NULL;
}

void aggiungi_elemento_in_coda(lista* lst, int valore){
	if(lista_vuota(*lst)==1){
		(*lst) = malloc(sizeof(elemento));
		(*lst)->info=valore;
		(*lst)->next=NULL;
	}
	else{
		elemento* nuovoElemento = malloc(sizeof(elemento));
		nuovoElemento->info=valore;
		nuovoElemento->next=NULL;
		elemento* scanner = (*lst);

		while(scanner->next!=NULL)
			scanner=scanner->next;
		scanner->next=nuovoElemento;
	}
}


void aggiungi_elemento_in_testa(lista* lst, int valore){
	elemento* nuovoElemento = malloc(sizeof(elemento));
	nuovoElemento->info=valore;
	nuovoElemento->next=(*lst);
	(*lst)=nuovoElemento;
}


int grandezza_lista(lista lst){
	int lunghezza=0;
	while(lst!=NULL){
		lst=lst->next;
		lunghezza++;
	}

	return lunghezza;
}

void cancella_lista(lista* lst){
	(*lst)=NULL;
}


int lista_vuota(lista lst){
	if(lst==NULL)
		return 1;
	return 0;
}

void elimina_elemento_in_testa(lista* lst){
	if(lista_vuota(*lst)==1)
	printf("La lista e' gia' vuota!\n");
	else{
		if(grandezza_lista(*lst)==1)
			cancella_lista(lst);
		else
			(*lst)=(*lst)->next;
	}
}

void elimina_elemento_in_coda(lista* lst){
	if(lista_vuota(*lst)==1)
	printf("La lista e' gia' vuota!\n");
	else{
		if(grandezza_lista(*lst)==1)
			cancella_lista(lst);
		else{
			elemento* scanner = (*lst);
			while(scanner->next->next!=NULL)
				scanner=scanner->next;
			scanner->next=NULL;

		}
	}
}


int visualizza_elemento_in_testa(lista lst){
	if(lista_vuota(lst)==1){
		printf("La lista e' vuota!\n");
		return -1;
	}
	return lst->info;
}

int visualizza_elemento_in_coda(lista lst){
	if(lista_vuota(lst)==1){
		printf("La lista e' vuota!\n");
		return -1;
	}
	while(lst->next!=NULL)
		lst=lst->next;
	return lst->info;
}

void elimina_elemento(lista* lst, elemento* el){
	if(lista_vuota(*lst)==1)
		printf("La lista è vuota, cosa vuoi eliminare?\n");
	else{		
		if(grandezza_lista(*lst)==1){
			if(el==(*lst))
				cancella_lista(lst);
		}
		else{

			elemento* scanner_precedente=(*lst);
			elemento* scanner_attuale = scanner_precedente->next;
			int trovato=0;
			while(scanner_attuale!=NULL && trovato==0){
				if(scanner_attuale==el){
					scanner_precedente->next=scanner_attuale->next;
					trovato=1;
				}
				scanner_precedente=scanner_attuale;
				scanner_attuale=scanner_attuale->next;
			}
			if(trovato==1)
				printf("L'elemento e' stato eliminato\n");
			else
				printf("L'elemento non e' stato trovato\n");
		}
	}
}


void elimina_elemento_i(lista* lst, int posizione){
	if(lista_vuota(*lst)==1)
		printf("La lista è vuota, cosa vuoi eliminare?\n");
	else{
		int dimensioneLista = grandezza_lista(*lst);
		if(posizione>dimensioneLista)
			printf("La lista e' piu' piccola della posizione da te scelta!\n");
		else{
			if(posizione==0)
				elimina_elemento_in_testa(lst);
			else{
				if(posizione+1 == dimensioneLista)
					elimina_elemento_in_coda(lst);
				else{
					int i=0;
					elemento* scanner = (*lst);
					while(i+1!=posizione){
						scanner=scanner->next;
						i++;
					}
					scanner->next=scanner->next->next;
				}
			}
		}
	}

}


void stampa_lista(lista lst){
	if(lst==NULL)
		printf("La lista e' vuota\n");
	else{
		printf("Ecco gli elementi della lista:\n");
		while(lst!=NULL){
			printf("%d ",lst->info);
			lst=lst->next;
		}

	}
}

