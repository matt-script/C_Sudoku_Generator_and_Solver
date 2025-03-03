#include <time.h>
#include "sudoku.h"

struct ramo *randGrigliaSudoku(struct ramo *head)
{
	int i, j, k, h, L, num[9]={1,2,3,4,5,6,7,8,9};

	for(k=0; k<3; k++)
	{	
		L=9;
		for(h=0; h<9; h++) num[h]=h+1;
		for(i=0; i<3; i++) for(j=0; j<3; j++)
		{
			h=rand()%L;
			head->m[i+3*k][j+3*k]=num[h];
			L--;
			for(; h<L; h++) num[h]=num[h+1];
		}
	}
	
	crea_griglia();
	taglia(head);
	head=solve_sudoku(head);
	return head;
}