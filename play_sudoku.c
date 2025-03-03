#include <stdio.h>
#include <string.h>
#include "sudoku.h"

void play_sudoku(char nick[])
{
	int i, j, n=9;
	const char path[]="Sudoku_da_iniziare/";
	char name[19+33+strlen(nick)];
	strcpy(name, path);
	strcat(name, nick);
	strcat(name, "_StartSudoku");

	struct ramo *head=(struct ramo *)malloc(sizeof(struct ramo));
	for(j=0; j<n; j++) for(i=0; i<n; i++) head->m[i][j]=0;
	head->P=NULL;
	head->k=0;
	head=randSudoku(head);

	FILE *fp;
	fp=newfile(name);
	fprint_sudoku(fp, head->P->m);
	
	printf("COME SI GIOCA\nRiempi le celle della griglia in modo da avere tutte le\ncifre da 1 a 9 in ogni riga, colonna e quadrante 3x3.\n");
	printf("\nCOMANDI\n'c' (check) -> cancella i numeri errati\n'h' (hint) -> riempie correttamente una cella\n'r' (restart) -> fa ricominciare il sudoku\n's' (solve) -> mostra il sudoku risolto\n'q' (quit) -> esci dal gioco\n");
	printf("\nRiempi una cella seguendo la sintassi '<n_riga> <n_colonna> - <numero>'.\nEsempio: il comando '13-8' inserisce un 8 in posizione <riga 1> <colonna 3>.\n");
	printf("Nota: per cancellare un numero basta inserire '0' in quella cella.\n");
	print_sudoku(head->P->m);

	play(nick, head);
}
