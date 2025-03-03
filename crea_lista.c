#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

struct list *crea_lista(int L)
{
	int i;
	struct list *head, *paus;
	head=(struct list *)malloc(sizeof(struct list));
	head->pos=0;
	paus=head;
	
	for(i=1; i<L; i++)
	{
		paus->next=(struct list *)malloc(sizeof(struct list));
		paus->next->pos=i;
		paus=paus->next;
	}
	paus->next=NULL;
	
	return head;
}