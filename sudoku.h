#include <stdio.h>
#include <stdbool.h>

struct cella {			//definisco la cella del sudoku
	int num;
	struct cella *pr;
	struct cella *pc;
	struct cella *bpr;
	struct cella *bpc;
	bool v[9];
};

struct cella *prig[9], *pcol[9], *pquad[9];

struct ramo {
	int i, j, k;
	int m[9][9];
	struct ramo *P;
	struct cella *p;
};

struct list {
	int pos;
	struct list *next;
};

void fprint_sudoku(FILE *fp, int m[][9]);

void print_sudoku(int m[][9]);

void w_pquad(void);

int find_q(int i, int j);

void taglia_q(int q, int n);

void taglia_r(int I, int n);

void taglia_c(int J, int n);

void taglia_num(int n, int i, int j, struct cella *p);

void taglia(struct ramo *P);

int find_num(int i, int j, struct cella *p);

void solve(struct ramo *Paus);

void delete_list(struct ramo *head);

struct ramo *undo(struct ramo *Paus);

struct ramo *solve_sudoku(struct ramo *Paus);

void crea_griglia(void);

bool control_num(int i, int j, int m[][9], int n);

bool control(int m[][9]);

struct list *crea_lista(int L);

struct ramo *randGrigliaSudoku(struct ramo *head);

struct ramo *randSudoku(struct ramo *head);

void insertSudoku(int m[][9]);

void error();

void insert_num(struct ramo *head, int v[]);

FILE *newfile(char name[]);

void do_op(char nick[], struct ramo *head, char op);

void play(char nick[], struct ramo *head);

void play_sudoku(char nick[]);

void play_solve(char nick[]);

void start();
