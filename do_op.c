#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sudoku.h"

void do_op(char nick[], struct ramo *head, char op)
{
	bool guardia=true;
	int i, j;
	FILE *fp;
	
	const char path[]="Sudoku_risolti/";
	char move[5], name[15+34+strlen(nick)];
	strcpy(name, path);
	strcat(name, nick);
	strcat(name, "_SolvedSudoku");
	
	switch (op) {
		case 99:
			for(i=0; i<9; i++) for(j=0; j<9; j++) if(head->P->P->m[i][j]!=head->m[i][j]) head->P->P->m[i][j]=0;
			print_sudoku(head->P->P->m);
			break;
		case 104:
			for(i=0; i<9&&guardia; i++) for(j=0; j<9&&guardia; j++) if(head->P->P->m[i][j]==0) {head->P->P->m[i][j]=head->m[i][j]; guardia=false;}
			print_sudoku(head->P->P->m);
			break;
		case 113:
			printf("\nGrazie per aver giocato, %s.", nick);
			exit(0);
		case 114:
			for(i=0; i<9; i++) for(j=0; j<9; j++) if(head->P->P->m[i][j]!=head->P->m[i][j]) head->P->P->m[i][j]=0;
			print_sudoku(head->P->P->m);
			break;
		case 115:
			fp=newfile(name);
			fprint_sudoku(fp, head->m);
			print_sudoku(head->m);
			printf("\nGrazie per aver giocato, %s.", nick);
			exit(0);
		default:
			error();
			break;
	}
}
