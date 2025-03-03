#include <stdio.h>
#include <string.h>
#include "sudoku.h"

void error()
{
	printf("\nErrore: comando non valido.\n");
}

void insertSudoku(int m[][9])
{
	int i, j, n;
	const char riga[10];
	printf("Inserisci i numeri del sudoku riga per riga.\n");
	printf("'b' (back) -> torna alla riga precedente\n'n' (next) -> va alla riga successiva\n");
	
	for(i=0; i<9; i++)
	{
	B:	printf("\nRiga %d > ", i+1);
		scanf("%s", riga);
		if(riga[0]=='b'&&i!=0) {i--; goto B;}
		else if(riga[0]=='n'&&i!=8) {i++; goto B;}
		else for(j=0; riga[j]!='\0'; j++)
		{
			if(riga[j]-'0'<0||riga[j]-'0'>9) error();
			else if(control_num(i, j, m, riga[j]-'0')) m[i][j]=riga[j]-'0';
			else {printf("Attenzione: il numero '%d' non puo' stare nella cella %d%d.\n", riga[j]-'0', i+1, j+1); m[i][j]=0;}
		}
		print_sudoku(m);
	}
}