#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

void crea_griglia(void)
{
	//Dichiarazione variabili ausiliarie
	int i, j;
	struct cella *paus;

	//Allocazione di memoria della prima cella della lista
	pquad[0]= (struct cella *)malloc(sizeof(struct cella));
	prig[0]= pquad[0];
	pcol[0]= pquad[0];
	paus= pquad[0];

	for(i=1; i<=9; i++)		//ciclo per ogni riga
	{
		for(j=1; j<9; j++)	//ciclo per ogni cella della riga
		{
			/*Nella prima riga della griglia viene allocata la memoria per la cella a destra e sotto
			  quella corrente mentre nelle altre solo sotto, in più vengono inizializzati opportunamente
			  i puntatori delle celle già presenti. I puntatori esterni delle celle appartenenti alla
			  cornice assumono il valore NULL*/

			if(i==1) paus->pr= (struct cella *)malloc(sizeof(struct cella));
			else paus->pr= paus->bpc->pr->pc;
			if(i!=9) {paus->pc= (struct cella *)malloc(sizeof(struct cella)); paus->pc->bpc= paus;}
			else paus->pc= NULL;
			paus->pr->bpr= paus;
		
			if(j==1) {
				prig[i]=paus->pc;	//inizializzo il vettore di accesso alle righe
				paus->bpr= NULL;
			}
			if(i==1) {
				pcol[j]=paus->pr;	//inizializzo il vettore di accesso alle colonne
				paus->bpc= NULL;
			}

			paus= paus->pr;			//scorro verso destra
		}

		paus->pr= NULL;
		paus->pc= (struct cella *)malloc(sizeof(struct cella));
		
		if(i==1) paus->bpc= NULL;
		if(i!=9) paus=prig[i];		//passo alla riga successiva
	}
	
	paus->pc= NULL;
	w_pquad();		//inizializzo il vettore di accesso ai quadranti
}