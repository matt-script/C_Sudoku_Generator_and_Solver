#include "sudoku.h"

void w_pquad(void)
{
	/*inizializza manualmente
	  il vettore di accesso ai quadranti*/

	pquad[1]=pcol[3];
	pquad[2]=pcol[6];
	pquad[3]=prig[3];
	pquad[4]=pcol[3]->pc->pc->pc;
	pquad[5]=pcol[6]->pc->pc->pc;
	pquad[6]=prig[6];
	pquad[7]=prig[6]->pr->pr->pr;
	pquad[8]=prig[6]->pr->pr->pr->pr->pr->pr;
}