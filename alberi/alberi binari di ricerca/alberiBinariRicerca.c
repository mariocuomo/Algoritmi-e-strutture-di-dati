#include <stdio.h>

/*
STRUTTURA CHE RAPPRESENTA UN NODO DI UN ALBERO CONTENTENTE I SEGUENTI CAMPI:
	-info: è l'intero considerato	
	-left: è un puntatore al figlio sinistro
	-right: è un puntatore al figlio destro
	-parent: è un puntatore al genitore
*/
typedef struct elem{
	int info;
	struct elem* left;
	struct elem* right;
	struct elem* parent;
}nodo;

/*albero è un puntatore a un nodo*/
typedef nodo* albero;

/*crea un albero vuoto*/
albero crea_albero_vuoto();

/*aggiunge una radice albero*/
void aggiungi_radice(albero*,int);

/*funzione per aggiungere un nuovo nodo*/
void aggiungi_nodo(albero*,int);

/*verifica se un albero è vuoto
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int albero_vuoto(albero);

/*ritorna il numero di nodi dell'albero*/
int numero_nodi(albero);

/*funzione che verifica se due nodi sono fratelli
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int sono_fratelli(albero,albero);

/*calcola il numero di figli di un nodo*/
int numero_figli(albero);

/*conta il numero di nodi foglia all'interno dell'albero*/
int conta_foglie(albero);

/*verifica se un nodo è una foglia
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int e_foglia(albero);

/*ritorna l'altezza dell'albero*/
int altezza_albero(albero);

/*funzione che verifica se è presente un valore all'interno dell'albero
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int e_presente(albero,int);

/*ritorna il valore massimo in un albero binario di ricerca*/
int calcola_massimo(albero);

/*ritorna il valore minimo in un albero binario di ricerca*/
int calcola_minimo(albero);

/*funzione che verifica se è un albero è un albero binario di ricerca
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int e_di_ricerca(albero);

/*funzione di supporto per verificare se tutti i nodi di un albero sono più piccoli di un valore dato
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int nodi_minori(albero, int);

/*funzione di supporto per verificare se tutti i nodi di un albero sono più grandi di un valore dato
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int nodi_maggiori(albero, int);

/*funzione di supporto per stampare tutti i nodi dell'albero in ordine crescente*/
void stampa(albero);


int main(){
	printf("La seguente simulazione crea un albero binario di ricerca della seguente forma\n");
	printf("\t\t\t20\n");
	printf("\t\t\t/\\\n");
	printf("\t\t10\t\t30\n");
	printf("\t\t\t\t/\\\n");
	printf("\t\t\t  25  40\n");

	albero mioAlbero = crea_albero_vuoto();

	printf("Aggiungo la radice 20\n");
	aggiungi_radice(&mioAlbero,20);
	printf("Aggiungo il valore 10\n");
	aggiungi_nodo(&mioAlbero,10);

	printf("Attualmente l'albero ha %d nodi\n",numero_nodi(mioAlbero));

	printf("Aggiungo il valore 30\n");
	aggiungi_nodo(&mioAlbero,30);

	if(sono_fratelli(mioAlbero->left,mioAlbero->right)==1)
		printf("I nodi %d e %d sono fratelli\n",mioAlbero->left->info, mioAlbero->right->info);
	else
		printf("I nodi %d e %d non sono fratelli\n",mioAlbero->left->info, mioAlbero->right->info);

	printf("Aggiungo il valore 25\n");
	aggiungi_nodo(&mioAlbero,25);
	printf("Il genitore del nodo %d e' %d\n",mioAlbero->right->left->info,mioAlbero->right->info);

	printf("Aggiungo il valore 40\n");
	aggiungi_nodo(&mioAlbero,40);
	
	printf("Attualmente ho un albero con le seguenti caratteristiche:\nNodi: %d\nFigli radice: %d\nFoglie: %d\nAltezza: %d\n",numero_nodi(mioAlbero),numero_figli(mioAlbero),conta_foglie(mioAlbero),altezza_albero(mioAlbero));

	if(e_presente(mioAlbero,40)==1)
		printf("E' presente il valore 40 all'interno dell'albero\n");
	else
		printf("Non e' presente il valore 40 all'interno dell'albero\n");
	
	if(nodi_minori(mioAlbero,50)==1)
		printf("L'albero contiene tutti nodi minori di 50\n");
	else
		printf("L'albero non contiene tutti nodi minori di 50\n");

	if(nodi_maggiori(mioAlbero,60)==1)
		printf("L'albero contiene tutti nodi maggiori di 60\n");
	else
		printf("L'albero non contiene tutti nodi maggiori di 60\n");

	printf("Con queste due funzioni di supporto, riesco a comprendere se un albero è un albero binario di ricerca\n");
	
	if(e_di_ricerca(mioAlbero)==1)
		printf("L'albero e' di ricerca\n");
	else
		printf("L'albero non e' di ricerca\n");

	printf("Ora aggiungo un nodo in posizione non corretta e riverifico la condizione di essere di ricerca\n");

	//aggiunta nodo
	nodo* nuovoNodo = malloc(sizeof(nodo));
	nuovoNodo->info = 5;
	nuovoNodo->left=NULL;
	nuovoNodo->right=NULL;
	nuovoNodo->parent = mioAlbero->right->left;
	mioAlbero->right->left->left=nuovoNodo; 

	printf("L'albero ha la seguente forma\n");
	printf("\t\t\t20\n");
	printf("\t\t\t/\\\n");
	printf("\t\t10\t\t30\n");
	printf("\t\t\t\t/\\\n");
	printf("\t\t\t  25  40\n");
	printf("\t\t\t  |\n");
	printf("\t\t\t  5\n");

	printf("Attualmente ho un albero con le seguenti caratteristiche:\nNodi: %d\nFigli radice: %d\nFoglie: %d\nAltezza: %d\n",numero_nodi(mioAlbero),numero_figli(mioAlbero),conta_foglie(mioAlbero),altezza_albero(mioAlbero));

	if(e_di_ricerca(mioAlbero)==1)
		printf("L'albero e' di ricerca\n");
	else
		printf("L'albero non e' di ricerca\n");

	printf("Elimino il nodo posizionato in maniera errata\n");
	free(nuovoNodo); 
	mioAlbero->right->left->left=NULL;

	printf("L'albero ha la seguente forma\n");
	printf("\t\t\t20\n");
	printf("\t\t\t/\\\n");
	printf("\t\t10\t\t30\n");
	printf("\t\t\t\t/\\\n");
	printf("\t\t\t  25  40\n");

	printf("Attualmente ho un albero con le seguenti caratteristiche:\nNodi: %d\nFigli radice: %d\nFoglie: %d\nAltezza: %d\n",numero_nodi(mioAlbero),numero_figli(mioAlbero),conta_foglie(mioAlbero),altezza_albero(mioAlbero));
	printf("Il valore piu' piccolo e' %d mentre quello piu' grande e' %d\n",calcola_minimo(mioAlbero),calcola_massimo(mioAlbero));

	printf("Ecco tutti i nodi dell'albero\n");
	stampa(mioAlbero);
}

albero crea_albero_vuoto(){
	return NULL;
}

void aggiungi_radice(albero* t,int valore){
	nodo* nuovoNodo = malloc(sizeof(nodo));
	nuovoNodo->info=valore;
	nuovoNodo->right=NULL;
	nuovoNodo->left=NULL;
	nuovoNodo->parent=NULL;
	(*t)=nuovoNodo;
}

void aggiungi_nodo(albero* t, int valore){
	nodo* nuovoNodo = malloc(sizeof(nodo));
	nuovoNodo->info=valore;
	nuovoNodo->right=NULL;
	nuovoNodo->left=NULL;

	nodo* precedente = NULL;
	nodo* successivo = (*t);

	while(successivo!=NULL){
		precedente=successivo;
		if(valore < successivo->info)
			successivo=successivo->left;
		else
			successivo=successivo->right;
	}

	if(valore < precedente->info){
		precedente->left=nuovoNodo;
		nuovoNodo->parent=precedente;
	}
	else{
		precedente->right=nuovoNodo;
		nuovoNodo->parent=precedente;	
	}

	
}

int albero_vuoto(albero t){
	if(t==NULL)
		return 1;
	return 0;
}

int numero_nodi(albero t){
	if(albero_vuoto(t)==1)
		return 0;
	return 1+numero_nodi(t->left)+numero_nodi(t->right);
}

int sono_fratelli(albero t1,albero t2){
	if(t1->parent==t2->parent)
		return 1;
	return 0;

}

int numero_figli(albero t){
	if(albero_vuoto(t)==1)
		return 0;
	int count=0;
	if(t->left!=NULL)
		count++;
	if(t->right!=NULL)
		count++;
	return count;
}

int altezza_albero(albero t){
	if(albero_vuoto(t)==1)
		return -1;
	return 1+massimo(altezza_albero(t->left),altezza_albero(t->right));
}

int massimo(int a, int b){
	if(a>b)
		return a;
	return b;
}

int e_presente(albero t, int valore){
	if(albero_vuoto(t)==1)
		return 0;
	while(t!=NULL){
		if(valore==t->info)
			return 1;
		if(valore < t->info)
			t=t->left;
		else
			t=t->right;
	}
	return 0;
}

int e_foglia(albero t){
	if(t->left==NULL && t->right==NULL)
		return 1;
	return 0;
}

int e_di_ricerca(albero t){
	int valore_radice = t->info;
	if(e_foglia(t)==1)
		return 1;

	if(nodi_minori(t->left,valore_radice)==0 || nodi_maggiori(t->right,valore_radice)==0)
		return 0;

	return e_di_ricerca(t->left)*e_di_ricerca(t->right);

}


int calcola_massimo(albero t){
	while(t->right!=NULL)
		t=t->right;
	return t->info;
}

int calcola_minimo(albero t){
	while(t->left!=NULL)
			t=t->left;
		return t->info;
}


int nodi_minori(albero t, int valore){
	if(t->info > valore)
		return 0;

	if(e_foglia(t)==1)
		return 1;

	if(t->left==NULL)
		return nodi_minori(t->right,valore);

	if(t->right==NULL)
		return nodi_minori(t->left,valore);

	return nodi_minori(t->left,valore)*nodi_minori(t->right,valore);
}


int nodi_maggiori(albero t, int valore){
	if(t->info < valore)
		return 0;

	if(e_foglia(t)==1)
		return 1;

	if(t->left==NULL)
		return nodi_maggiori(t->right,valore);

	if(t->right==NULL)
		return nodi_maggiori(t->left,valore);

	return nodi_maggiori(t->left,valore)*nodi_maggiori(t->right,valore);
}


int conta_foglie(albero t){
	if(e_foglia(t)==1)
		return 1;
	if(t->right==NULL)
		return conta_foglie(t->left);
	if(t->left==NULL)
		return conta_foglie(t->right);
	return conta_foglie(t->left)+conta_foglie(t->right);
}

void stampa(albero t){
	if(t!=NULL){
		stampa(t->left);
		printf("%d ", t->info);
		stampa(t->right);
	}
}

