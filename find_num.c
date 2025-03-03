#include "sudoku.h"

int find_num(int i, int j, struct cella *p)
{
	int n, sum=0, h, k, c=0, q=find_q(i, j);
	struct cella *paus;

	for(k=0; k<9; k++)
	{	
		paus=p;
		sum+=paus->v[k];
		
		if(paus->v[k]==true)
		{
			n=k+1;
			
			paus=pquad[q];
			c=paus->v[k];
			for(h=1; h<3; h++) {paus=paus->pr; c=c+paus->v[k];}
			for(; h<5; h++) {paus=paus->pc; c=c+paus->v[k];}
			for(; h<7; h++) {paus=paus->bpr; c=c+paus->v[k];}
			c=c+paus->bpc->v[k];
			c=c+paus->bpc->pr->v[k];
			if(c==1) return k+1;
			else c=0; 	
			
			paus=prig[i];
			while(c<2&&paus!=NULL) {c+=paus->v[k]; paus=paus->pr;}
			if(c==1) return k+1;
			else c=0;

			paus=pcol[j];
			while(c<2&&paus!=NULL) {c+=paus->v[k]; paus=paus->pc;}
			if(c==1) return k+1;
			else c=0;
		}
	}
	
	if(sum==1) return n;

	return 0;
}