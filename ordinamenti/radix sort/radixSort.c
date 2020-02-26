#include <stdio.h>
#include <stdlib.h>

/*LUNGHEZZA PAROLE E NUMERO DI PAROLE*/
#define LUNGHEZZAPAROLE 10
#define NUMEROPAROLE 10

/*funzione di ordinamento crescente ordine di n+m
	-n, dimensione dell'input
	-m, massimo valore dell'input
*/
void radixSort(int**);

/*funzione di ordinamento, stampa l'evoluzione dell'ordinamento*/
void radixSort_stampa(int**);

/*funzione che ordina un vettore considerando la i-esima colonna*/
void ordina(int**,int);

/*funzione di supporto per stampare una matrice*/
void stampa(int**);


int main(){
	int i=0;
	int j=0;
	int **parole = malloc(sizeof(int*)*NUMEROPAROLE);

	printf("La seguente simulazione ordina lessicograficamente 10 parole random di lunghezza 10\n");
	
	for (i=0; i<NUMEROPAROLE; ++i){
	  parole[i] = malloc(sizeof(int)*LUNGHEZZAPAROLE);
  		int lettera;
		for(j=0;j<10;j++){
			lettera=97 + rand()%25;
			parole[i][j]=lettera;
		}
	}

	printf("Ecco le parole generate\n");
	stampa(parole);
	

	printf("\nEcco le parole ordinate\n");
	radixSort(parole);

	stampa(parole);

	printf("\nGenero nuovamente 10 parole random\n");
	for (i=0; i<NUMEROPAROLE; ++i){
	  parole[i] = malloc(sizeof(int)*LUNGHEZZAPAROLE);
  		int lettera;
		for(j=0;j<10;j++){
			lettera=97 + rand()%25;
			parole[i][j]=lettera;
		}
	}

	stampa(parole);

	printf("\nEcco come avviene l'ordinamento\n");
	radixSort_stampa(parole);



}


void ordina(int** vettore,int colonna){
	int i=0;
	int j=0;

	for(;i<NUMEROPAROLE-1;i++){
		int minimo=i;
		for(j=i+1;j<NUMEROPAROLE;j++){
			if(vettore[j][colonna]<vettore[minimo][colonna])
				minimo=j;
		}

		int *temp;
		temp = vettore[minimo];
		vettore[minimo] = vettore[i];
		vettore[i] = temp;
		
	}
}

void radixSort(int** vettore){
	int i=LUNGHEZZAPAROLE-1;
	while(i>=0){
		ordina(vettore,i);
		i--;
	}
}

void radixSort_stampa(int** vettore){
	int i=LUNGHEZZAPAROLE-1;
	while(i>=0){
		ordina(vettore,i);
		printf("\nSto ordinando prendendo in considerazione la lettera numero %d\n",i+1);
		stampa(vettore);
		i--;
	}
}

void stampa(int** matrice){
	int i=0;
	int j=0;

	for(;i<NUMEROPAROLE;i++){
		for(j=0;j<LUNGHEZZAPAROLE;j++)
			printf("%c",matrice[i][j]);
		printf("\n");
	}
}
