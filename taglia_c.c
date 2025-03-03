#include "sudoku.h"

void taglia_c(int J, int n)
{
	struct cella *paus=pcol[J];
	n--;

	while(paus!=NULL)
	{
		paus->v[n]=0;
		paus=paus->pc;
	}
}