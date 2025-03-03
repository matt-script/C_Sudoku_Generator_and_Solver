#include "sudoku.h"

void taglia_q(int q, int n)
{
	int h;
	struct cella *paus=pquad[q];
	n--;

	paus->v[n]=0;
	for(h=0; h<2; h++) {paus=paus->pr; paus->v[n]=0;}
	for(; h<4; h++) {paus=paus->pc; paus->v[n]=0;}
	for(; h<6; h++) {paus=paus->bpr; paus->v[n]=0;}
	paus->bpc->v[n]=0;
	paus->bpc->pr->v[n]=0;
}