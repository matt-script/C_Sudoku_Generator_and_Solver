#include <stdio.h>
#include "sudoku.h"

void fprint_sudoku(FILE *fp, int m[][9])
{
	int i, j;

	fprintf(fp, "\n     ");
	for(j=0; j<9; j++)
	{
		fprintf(fp, "%d ", j+1);
		if(j==2||j==5||j==8) fprintf(fp, "  ");
	}
	fprintf(fp, "\n     - - - - - - - - - - - ");

	for(i=0; i<9; i++)
	{	
		fprintf(fp, "\n %d | ", i+1);
		for(j=0; j<9; j++)
		{
			fprintf(fp, "%d ", m[i][j]);
			if(j==2||j==5||j==8) fprintf(fp, "| ");
		}
		
		if(i==2||i==5) fprintf(fp, "\n   | - - -   - - -   - - - |");
	}
	
		fprintf(fp, "\n     - - - - - - - - - - - \n");
}

void print_sudoku(int m[][9])
{
	int i, j;

	printf("\n     ");
	for(j=0; j<9; j++)
	{
		printf("%d ", j+1);
		if(j==2||j==5||j==8) printf("  ");
	}
	printf("\n     - - - - - - - - - - - ");

	for(i=0; i<9; i++)
	{	
		printf("\n %d | ", i+1);
		for(j=0; j<9; j++)
		{
			printf("%d ", m[i][j]);
			if(j==2||j==5||j==8) printf("| ");
		}
		
		if(i==2||i==5) printf("\n   | - - -   - - -   - - - |");
	}
	
		printf("\n     - - - - - - - - - - - \n");
}