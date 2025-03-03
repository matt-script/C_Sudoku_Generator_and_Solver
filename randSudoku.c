#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"

struct ramo *randSudoku(struct ramo *head)
{
	bool guardia;
	int i, j, I, J, k, c, n, L=81;
	struct cella *paus;
	struct ramo *Paus, *Punt;
	struct list *h, *p, *hd=crea_lista(L);

	head=randGrigliaSudoku(head);
	head->P=(struct ramo *)malloc(sizeof(struct ramo));
	Paus=head->P;
	for(i=0; i<9; i++) for(j=0; j<9; j++) Paus->m[i][j]=head->m[i][j];

	for(k=0; k<81; k++)
	{
		guardia=true;
		n=rand()%L;
		p=hd;
		if(!n) {h=hd; hd=hd->next;}
		else
		{
			for(i=0; i<n-1; i++) p=p->next;
			h=p->next;			
		}
		I=h->pos/9;
		J=h->pos%9;
		n=Paus->m[I][J];
		Paus->m[I][J]=0;
		p->next=h->next;
		h->next=NULL;
		L--;

		for(c=1; c<=9&&guardia; c++) if(c!=n)
		{
			Punt=(struct ramo *)malloc(sizeof(struct ramo));
			for(i=0; i<9; i++) for(j=0; j<9; j++) Punt->m[i][j]=Paus->m[i][j];
			Punt->m[I][J]=c;
			Punt->P=NULL;
			Punt->k=0;
			
			if(control_num(I, J, Punt->m, Punt->m[I][J]))
			{
				taglia(Punt);
				Punt=solve_sudoku(Punt);

				if(Punt) for(i=0; i<9&&guardia; i++) for(j=0; j<9&&guardia; j++) if(Punt->m[i][j]!=head->m[i][j]) {Paus->m[I][J]=n; guardia=false;}
			}
			free(Punt);
		}
	}

	return head;
}
