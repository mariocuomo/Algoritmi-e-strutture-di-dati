#include <stdio.h>
#include <stdlib.h>

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

/*aggiunge un figlio sinistro al nodo passato come parametro*/
void aggiungi_figlio_sinistro(albero*,int);

/*aggiunge un figlio destro al nodo passato come parametro*/
void aggiungi_figlio_destro(albero*,int);

/*verifica se un albero è vuoto
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int albero_vuoto(albero);

/*ritorna il numero di nodi dell'albero*/
int numero_nodi(albero);

/*verifica se un nodo è una foglia
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int e_foglia(albero);

/*conta il numero di nodi foglia all'interno dell'albero*/
int conta_foglie(albero);

/*ritorna l'altezza dell'albero*/
int altezza_albero(albero);

/*funzione per eliminare figlio sinistro di un nodo*/
void elimina_figlio_sinistro(albero);

/*funzione per eliminare figlio destro di uno nodo*/
void elimina_figlio_destro(albero);

/*verifica se un albero binario è completo, ovvero ogni nodo ha esattamente due figli
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int e_completo(albero);

/*funzione che verifica se due nodi sono fratelli
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int sono_fratelli(albero,albero);

/*funzione di supporto per calcolare il massimo tra due valori*/
int massimo(int, int);

int main(){
	printf("Questa simulazione crea un albero binario con 5 nodi\n");
	printf("RADICE-FIGLIO SINISTRO-FIGLIO DESTRO (FIGLIO SINISTRO-FIGLIO DESTRO)\n");

	albero mioAlbero = crea_albero_vuoto();
	printf("Ho creato un nuovo albero e contiene %d nodi\n",numero_nodi(mioAlbero));

	aggiungi_radice(&mioAlbero,0);
	printf("Ho aggiunto la radice di valore zero all'albero creato, ora contiene %d nodi e ha altezza %d\n",numero_nodi(mioAlbero),altezza_albero(mioAlbero));

	aggiungi_figlio_sinistro(&mioAlbero,1);
	printf("Ho aggiunto un nodo di valore uno e ora l'albero contiene %d nodi e ha altezza %d\n",numero_nodi(mioAlbero),altezza_albero(mioAlbero));	

	aggiungi_figlio_destro(&mioAlbero,2);
	printf("Ho aggiunto un nodo di valore due e ora l'albero contiene %d nodi e ha altezza %d\n",numero_nodi(mioAlbero),altezza_albero(mioAlbero));	

	if(sono_fratelli(mioAlbero->left,mioAlbero->right)==1)
		printf("I nodi %d e %d sono fratelli\n",mioAlbero->left->info, mioAlbero->right->info);
	else
		printf("I nodi %d e %d non sono fratelli\n",mioAlbero->left->info, mioAlbero->right->info);


	if(e_completo(mioAlbero)==1)
		printf("L'albero e' completo\n");
	else
		printf("L'albero non e' completo\n");

	aggiungi_figlio_sinistro(&(mioAlbero->right),3);
	aggiungi_figlio_destro(&(mioAlbero->right),4);
	printf("Ora aggiungo i due figli (3 e 4) al nodo destro 3 e ora l'albero contiene %d nodi e altezza %d\n",numero_nodi(mioAlbero),altezza_albero(mioAlbero));

	printf("Attualmente l'albero ha %d foglie\n",conta_foglie(mioAlbero));

	printf("Elimino il figlio sinistro della radice\n");
	elimina_figlio_sinistro(mioAlbero);

	printf("Attualmente l'albero ha %d nodi e %d foglie\n",numero_nodi(mioAlbero),conta_foglie(mioAlbero));
	if(e_completo(mioAlbero)==1)
		printf("L'albero e' completo\n");
	else
		printf("L'albero non e' completo\n");
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

int albero_vuoto(albero t){
	if(t==NULL)
		return 1;
	return 0;
}

void aggiungi_figlio_sinistro(albero* t, int valore){
	nodo* nuovoNodo = malloc(sizeof(nodo));
	nuovoNodo->info=valore;
	nuovoNodo->right=NULL;
	nuovoNodo->left=NULL;
	nuovoNodo->parent=(*t);
	
	if(albero_vuoto(*t)==1)
		(*t)=nuovoNodo;
	else
		(*t)->left=nuovoNodo;
}

void aggiungi_figlio_destro(albero* t, int valore){
	nodo* nuovoNodo = malloc(sizeof(nodo));
	nuovoNodo->info=valore;
	nuovoNodo->right=NULL;
	nuovoNodo->left=NULL;
	nuovoNodo->parent=(*t);

	if(albero_vuoto(*t)==1)
		(*t)=nuovoNodo;
	else
		(*t)->right=nuovoNodo;
}

int numero_nodi(albero t){
	if(albero_vuoto(t)==1)
		return 0;
	return 1+numero_nodi(t->left)+numero_nodi(t->right);
}

int e_foglia(albero t){
	if(t->left==NULL && t->right==NULL)
		return 1;
	return 0;
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

int altezza_albero(albero t){
	if(albero_vuoto(t)==1)
		return -1;
	return 1+massimo(altezza_albero(t->left),altezza_albero(t->right));
}

void elimina_figlio_destro(albero t){
	t->right=NULL;
}

void elimina_figlio_sinistro(albero t){
	t->left=NULL;
}

int e_completo(albero t){
	if(t->left!=NULL && t->right!=NULL)
		return e_completo(t->left) && e_completo(t->right);
	if(e_foglia(t)==1)
		return 1;
	return 0;
}

int sono_fratelli(albero t1,albero t2){
	if(t1->parent==t2->parent)
		return 1;
	return 0;

}

int massimo(int a, int b){
	if(a>b)
		return a;
	return b;
}
