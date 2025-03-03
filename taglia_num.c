#include "sudoku.h"

void taglia_num(int n, int i, int j, struct cella *p)
{
	int k;
	for(k=0; k<9; k++) p->v[k]=0;
	
	taglia_q(find_q(i, j), n);
	taglia_r(i, n);
	taglia_c(j, n);
}