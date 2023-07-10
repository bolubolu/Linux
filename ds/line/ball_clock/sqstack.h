#ifndef SQLIST_H__
#define SQLIST_H__

#define SIZE   32

typedef int type;

typedef struct node_st
{	
	int top;
	type data[];
}sqstack;

sqstack *st_create(void);

int st_isempty(sqstack *);

int st_push(sqstack *,type *);

int st_pop(sqstack *,type *);

int st_top(sqstack *,type *);

void st_travel(sqstack *);

void st_destroy(sqstack *);


 
#endif


