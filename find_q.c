#include "sudoku.h"

int find_q(int i, int j)
{
	int q;
	q= pow(i/3+1, 2)+j/3;
	if(q>6) q=q-2;

	return q-1;
}