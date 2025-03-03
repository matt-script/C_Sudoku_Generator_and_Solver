#include "sudoku.h"

void taglia_r(int I, int n)
{
	struct cella *paus=prig[I];
	n--;

	while(paus!=NULL)
	{
		paus->v[n]=0;
		paus=paus->pr;
	}
}