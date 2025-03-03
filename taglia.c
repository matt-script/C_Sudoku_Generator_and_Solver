#include "sudoku.h"

void taglia(struct ramo *P)
{
	int i, j, k;
	struct cella *paus;
	
	for(i=0; i<9; i++)
	{
		paus=prig[i];
		
		for(j=0; j<9; j++)
		{
			if(P->m[i][j]==0) {paus->num=0; for(k=0; k<9; k++) paus->v[k]=1;}
			paus=paus->pr;
		}
	}
	
	for(i=0; i<9; i++)
	{
		paus=prig[i];
		
		for(j=0; j<9; j++)
		{
			if(P->m[i][j]!=0) {paus->num=P->m[i][j]; taglia_num(P->m[i][j], i, j, paus);}
			paus=paus->pr;
		}
	}
}