#include <stdio.h>
#include <string.h>
#include "sudoku.h"

void play_solve(char nick[])
{
	int i, j;
	const char path[]="Sudoku_risolti/";
	char move[5], name[15+34+strlen(nick)];
	strcpy(name, path);
	strcat(name, nick);
	strcat(name, "_SolvedSudoku");

	struct ramo *head=(struct ramo *)malloc(sizeof(struct ramo));
	for(j=0; j<9; j++) for(i=0; i<9; i++) head->m[i][j]=0;
	head->P=NULL;
	head->k=0;

	insertSudoku(head->m);
	FILE *fp=newfile(name);
	fprint_sudoku(fp, head->m);

	crea_griglia();
	taglia(head);
	head=solve_sudoku(head);
	
	if(head)
	{
		print_sudoku(head->m);
		printf("\nEcco il sudoku risolto.");
		fprint_sudoku(fp, head->m);
	}
	else printf("\nIl sudoku inserito non ha soluzioni.");
}