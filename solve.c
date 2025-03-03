#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"

void solve(struct ramo *Paus)
{
	int i, j;
	bool guardia=true;
	struct cella *paus;

	while(guardia)
	{
		guardia=false;
		
		for(i=0; i<9; i++)
		{
			paus=prig[i];
			for(j=0; j<9; j++)
			{
				if(paus->num==0)
				{
					paus->num=find_num(i, j, paus);
					Paus->m[i][j]=paus->num;
					if(paus->num!=0) {taglia_num(paus->num, i, j, paus); guardia=true;}
				}
				paus=paus->pr;
			}
		}
	}
}