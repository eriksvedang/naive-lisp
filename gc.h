#ifndef GC
#define GC

#include <stdbool.h>

struct Cell;

typedef struct Cell *proc(struct Cell *args);

typedef struct Lambda {
	struct Cell *params;
	struct Cell *body;
	struct Cell *env;
} Lambda;

typedef struct Cell {
	char type;
	bool collect;
	struct Cell* next;

	// pair ('p')
	struct Cell* first;
	struct Cell* rest;

	// int ('i')
	int value;

	// symbol ('s')
	char *name;

	// primitive operation ('o')
	proc *prim_op; 

	// lambda ('l') ADD GARBAGE COLLECTION!
	Lambda *lambda;
} Cell;

Cell *nil;

Cell* init_gc();
void maybe_run_gc();

// This will save the cell from gc:ing
void add_to_root(Cell *cell);
Cell *get_root();

Cell* make_int(int value);
Cell* make_pair(Cell *first, Cell *rest);
Cell* make_symbol(char *name);
Cell* make_prim_op(proc f, char *name);
Cell* make_lambda(Cell *params, Cell *body, Cell *env);

bool eq(Cell *a, Cell *b);

void print_cell(Cell *cell, int depth);

Cell *cons(Cell *value, Cell *list);

#endif