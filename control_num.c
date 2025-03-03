#include <stdio.h>
#include <stdbool.h>
#include "sudoku.h"

bool control_num(int i, int j, int m[][9], int n)
{
	int I, J, q=find_q(i, j);
	if(n!=0)
	{
		for(J=0; J<9; J++) if(J!=j&&m[i][J]==n) return false;
		for(I=0; I<9; I++) if(I!=i&&m[I][j]==n) return false;
		for(I=3*(q/3); I<3*(q/3+1); I++) for(J=3*(q%3); J<3*(q%3+1); J++) if((I!=i||J!=j)&&m[I][J]==n) return false;
	}
	
	return true;
}