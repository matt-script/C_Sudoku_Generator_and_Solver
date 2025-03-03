#include "sudoku.h"

struct ramo *undo(struct ramo *Paus)
{
	Paus->P->k+=1;
	taglia(Paus->P);
	return Paus->P;
}