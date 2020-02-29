#include <stdio.h>
#include <string.h>


/*
STRUTTURA CHE RAPPRESENTA UNO ELEMENTO DI UNA LISTA SEMPLICEMENTE CONCATENATA CONTENTENTE I SEGUENTI CAMPI:
	-info: è l'intero considerato
	-key: è un riferimento alla chiave
	-next: è un puntatore al prossimo elemento della lista
*/

typedef struct elem{
	int info;
	struct elem* next;
	char* key;
}elemento;

/*lista è un puntatore a elemento*/
typedef elemento* lista;


/*
====FUNZIONI CHE LAVORANO SU MAPPE====
*/

/*funzione per inserire un elemento nel dizionario*/
void inserisci_mappa(lista*,char*,int);

/*ritorna il codice intero associato alla stringa*/
int hash(char*);

/*ritorna il numero di valori nella mappa*/
int numero_di_elementi_mappa(lista*);

/*restituisce il valore associato a quella chiave, -1 se non presente*/
int prendi_valore(lista*,char*);

void elimina_chiave(lista*,char*);


/*
====FUNZIONI CHE LAVORANO SU LISTE====
*/

/*funzione per creare una nuova lista*/
lista crea_lista();

/*ritorna il numero di elementi nella lista*/
int grandezza_lista(lista);

/*
====FUNZIONI DI SUPPORTO====
*/

/*crea una stringa copia di quella in input*/
char* crea_stringa(char*);

/*verifica se due stringhe sono uguali
	ritorna 1 in caso positivo, 0 in caso negativo
*/
int stessa_chiave(char*,char*);



int main(){

	lista mappa[20];

	int i=0;
	printf("In questa simulazione e' creata un dizionario con chiavi stringhe e valori interi\n");
	for(;i<20;i++)
		mappa[i]=crea_lista();

	char chiave[20];
	chiave[0]='p';
	chiave[1]='r';
	chiave[2]='i';
	chiave[3]='m';
	chiave[4]='o';
	chiave[5]='\0';

	printf("Inserisco il primo elemento con chiave 'primo' e valore 10\n");
	inserisci_mappa(mappa,chiave,10);

	chiave[0]='s';
	chiave[1]='e';
	chiave[2]='c';
	chiave[3]='o';
	chiave[4]='n';
	chiave[5]='d';
	chiave[6]='o';
	chiave[7]='\0';


	printf("Inserisco il secondo elemento con chiave 'secondo' e valore 20\n");
	inserisci_mappa(mappa,chiave,20);

	printf("In tutto sono presenti %d elementi\n",numero_di_elementi_mappa(mappa));

	chiave[0]='p';
	chiave[1]='r';
	chiave[2]='i';
	chiave[3]='m';
	chiave[4]='o';
	chiave[5]='\0';
	printf("Il valore associato alla chiave %s e' %d\n",chiave,prendi_valore(mappa,chiave));


	chiave[0]='p';
	chiave[1]='r';
	chiave[2]='i';
	chiave[3]='m';
	chiave[4]='o';
	chiave[5]='\0';
	printf("Il valore associato alla chiave %s e' %d\n",chiave,prendi_valore(mappa,chiave));

	chiave[0]='o';
	chiave[1]='m';
	chiave[2]='i';
	chiave[3]='r';
	chiave[4]='p';
	chiave[5]='\0';
	printf("Il valore associato alla chiave %s e' %d\n",chiave,prendi_valore(mappa,chiave));

	chiave[0]='s';
	chiave[1]='e';
	chiave[2]='c';
	chiave[3]='o';
	chiave[4]='n';
	chiave[5]='d';
	chiave[6]='o';
	chiave[7]='\0';
	printf("Elimino la con chiave 'secondo'\n");
	elimina_chiave(mappa,chiave);

	printf("Il valore associato alla chiave %s e' %d\n",chiave,prendi_valore(mappa,chiave));
}

/*
====FUNZIONI CHE LAVORANO SU MAPPE====
*/

void inserisci_mappa(lista* tabella, char* chiave, int valore){
	//rendo la chiave intera
	int chiave_intera=hash(chiave);


	//se non è presente nessun valore con quel codice hash
	if(tabella[chiave_intera]==NULL){
		elemento* nuovo = malloc(sizeof(elemento));
		nuovo->info=valore;
		nuovo->next=NULL;
		nuovo->key=crea_stringa(chiave);
		tabella[chiave_intera]=nuovo;
		return;
	}

	//se è già presente un valore con quel codice hash
	elemento* scanner = tabella[chiave_intera];

	//se è già presente proprio quella chiave, cambia valore alla chiave
	while(scanner->next!=NULL){
		if(stessa_chiave(chiave,scanner->key)==1){
			scanner->info=valore;
			return;
		}
		scanner=scanner->next;
	}

	if(stessa_chiave(chiave,scanner->key)==1){
		scanner->info=valore;
		return;
	}

	//se non è presente, aggiungilo alla lista
	elemento* nuovo = malloc(sizeof(elemento));
	nuovo->info=valore;
	nuovo->next=NULL;
	nuovo->key=crea_stringa(chiave);
	scanner->next=nuovo;

}


int numero_di_elementi_mappa(lista* tabella){
	int i=0;
	int ritorno = 0;
	for(;i<20;i++){
		ritorno+=grandezza_lista(tabella[i]);
	}
	return ritorno;
}

int hash(char* chiave){
	int ritorno = 0;
	int i=0;
	for(; i<strlen(chiave);i++)
		ritorno+=chiave[i];
	return ritorno%20;
}

int prendi_valore(lista* tabella, char* chiave){
	int chiave_intera=hash(chiave);
	if(tabella[chiave_intera]==NULL)
		return -1;
	elemento* scanner = tabella[chiave_intera];
	while(scanner!=NULL){
		if(stessa_chiave(chiave,scanner->key)==1){
			return scanner->info;
		}
		scanner=scanner->next;
	}
	return -1;
}

void elimina_chiave(lista* tabella,char* chiave){
	int chiave_intera=hash(chiave);
	if(tabella[chiave_intera]==NULL){
		printf("Non c'e' nessuna chiave %s\n",chiave);
		return;
	}

	if(tabella[chiave_intera]->next==NULL){
		if(stessa_chiave(chiave,tabella[chiave_intera]->key)==1){
			printf("Ho eliminato la chiave %s\n",chiave);
			tabella[chiave_intera]=NULL;
			return;
		}
	}

	elemento* precedente = tabella[chiave_intera];
	elemento* successivo = precedente->next;
	while(successivo!=NULL){
		if(stessa_chiave(chiave,successivo->key)==1){
			precedente->next=successivo->next;
			printf("Ho eliminato la chiave %s\n",chiave);
			return;
		}
		precedente=successivo;
		successivo=successivo->next;
	}

	printf("Non c'e' nessuna chiave %s\n",chiave);

}

/*
====FUNZIONI CHE LAVORANO SU LISTE====
*/

lista crea_lista(){
	return NULL;
}

int grandezza_lista(lista lst){
	int lunghezza=0;
	while(lst!=NULL){
		lst=lst->next;
		lunghezza++;
	}

	return lunghezza;
}


/*
====FUNZIONI DI SUPPORTO====
*/
char* crea_stringa(char* chiave){
	char* copia = malloc(sizeof(char*)*strlen(chiave));
	int i=0;


 	while (chiave[i] != '\0') {
    	copia[i] = chiave[i];
    	i++;
    }
  	copia[i] = '\0';
	
	return copia;
}

int stessa_chiave(char* s1, char* s2){
	if(strlen(s1)!=strlen(s2))
		return 0;

	int i=0;
	for(;i<strlen(s1);i++)
		if(s1[i]!=s2[i])
			return 0;

	return 1;
}

