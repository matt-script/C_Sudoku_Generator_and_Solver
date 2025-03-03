#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"

bool control(int m[][9])
{
	int i, j;
	for(i=0; i<9; i++) for(j=0; j<9; j++) if(!control_num(i, j, m, m[i][j])) return false;
	
	return true;
}
