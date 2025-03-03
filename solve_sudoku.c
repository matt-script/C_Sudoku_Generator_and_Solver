#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"

struct ramo *solve_sudoku(struct ramo *Paus)
{
	int i, j, k, sum=0, min=9;
	struct cella *paus;
	struct ramo *head, *solved;

	solve(Paus);

	for(i=0; i<9; i++)
	{
		paus=prig[i];
		for(j=0; j<9; j++)
		{
			if(paus->num==0)
			{
				for(k=0; k<9; k++) sum+=paus->v[k];
				if(sum<min)
				{
					min=sum;
					Paus->p=paus;
					Paus->i=i;
					Paus->j=j;
				}
				sum=0;	
			}
			paus=paus->pr;
		}
	}
	
	if(min==9)
	{
		if(Paus->P) delete_list(Paus->P);
		return Paus;
	}
	else if(min>1)
	{	AGAIN:	
		head=(struct ramo *)malloc(sizeof(struct ramo));
		head->P=Paus;
		head->k=0;
		for(i=0; i<9; i++) for(j=0; j<9; j++) head->m[i][j]=Paus->m[i][j];

		for(k=head->P->k; k<9; k++) if(Paus->p->v[k]==true)
		{
			Paus->p->num=k+1;
			head->m[Paus->i][Paus->j]=k+1;
			head->P->k=k;
			taglia_num(Paus->p->num, Paus->i, Paus->j, Paus->p);
			return solve_sudoku(head);
		}
		free(head);
	}
	if(min==0)
	{
		if(Paus->P==NULL)
		{
			free(Paus);
			return NULL;
		}
		head=Paus;
		Paus=undo(Paus);
		free(head);
		goto AGAIN;
	}		
}