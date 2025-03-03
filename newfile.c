#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sudoku.h"

FILE *newfile(char name[])
{
	char buf[21];

	time_t rt;
	time (&rt);
	struct tm* t;
	t = localtime(&rt);
	strftime(buf,21,"_%d%m%Y-%I%M%p.txt", t);
	strcat(name, buf);

	FILE *fp=fopen(name,"w");

	return fp;
}