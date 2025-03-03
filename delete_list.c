#include <stdlib.h>
#include "sudoku.h"

void delete_list(struct ramo *head)
{
    if(head->P) delete_list(head->P);
    head->P=NULL;
    free(head);
}
