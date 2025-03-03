#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sudoku.h"

void play(char nick[], struct ramo *head)
{
	bool finish=false;
	int i, j, c=0, v[3];
	
	const char path[]="Sudoku_risolti/";
	char move[5], name[15+34+strlen(nick)];
	strcpy(name, path);
	strcat(name, nick);
	strcat(name, "_SolvedSudoku");
	
	head->P->P=(struct ramo *)malloc(sizeof(struct ramo));

	for(i=0; i<9; i++) for(j=0; j<9; j++)
	{
		head->P->P->m[i][j]=head->P->m[i][j];
		if(head->P->m[i][j]!=0) c++;
	}

	while(c!=81)
	{
		printf("\nInserisci un comando > ");
		scanf("%s", move);

		if(move[0]-'0'>0&&move[0]-'0'<10)
		{
			for(i=0; i<4; i++) v[i]=move[i]-'0';
			insert_num(head->P, v);
			if(head->P->P->m[v[0]-1][v[1]-1]==v[3]) c++;
		}
		else
		{
			do_op(nick, head, move[0]);
			if(move[0]=='h') c++;
		}
	}

	printf("\nComplimenti! Hai risolto il sudoku.");
	
	FILE *fp;
	fp=newfile(name);
	fprint_sudoku(fp, head->m);
}
