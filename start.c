#include <stdio.h>
#include <string.h>
#include "sudoku.h"

void start()
{
	char nick[20], mod;
	int i;

	printf("Inserire il nickname del giocatore > ");
	scanf("%s", &nick);
	getchar();

	printf("\nBenvenuto, %s. Seleziona una modalita' di gioco.\n", nick);
	printf("'r' -> risolve il sudoku inserito\n'g' -> genera un sudoku da risolvere\n\nStart > ");

MOD:mod=getchar();

	if(mod=='r') play_solve(nick);
	else if(mod=='g') play_sudoku(nick);
	else {error(); goto MOD;}

	printf("\nGrazie per aver giocato, %s.", nick);
}