#include <stdio.h>
#include <string.h>
#include "sudoku.h"

void insert_num(struct ramo *head, int v[])
{
	bool err=false;
	int i=v[0]-1, j;

	if(v[1]>0&&v[1]<10) j=v[1]-1;
	else err=true;
	if(head->m[i][j]!=0) printf("\nAttenzione: non puoi modificare i numeri di partenza.\n");
	else if((v[3]>=0&&v[3]<10)&&control_num(i, j, head->P->m, v[3])) head->P->m[i][j]=v[3];
	else if(!control_num(i, j, head->P->m, v[3])) printf("\nAttenzione: il numero '%d' non puo' stare nella cella %d%d.\n", v[3], v[0], v[1]);
	else err=true;

	if(err) error();
	else print_sudoku(head->P->m);
}
