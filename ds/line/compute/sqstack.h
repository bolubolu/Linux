#ifndef SQLIST_H__
#define SQLIST_H__

#define MAXSIZE    32

typedef int datatype;

typedef struct node_st
{	
	int top;
	datatype data[MAXSIZE];
}sqstack;

sqstack *st_create(void);

int st_isempty(sqstack *);

int st_push(sqstack *,datatype *);

int st_pop(sqstack *,datatype *);

int st_top(sqstack *,datatype *);

void st_travel(sqstack *);

void st_destroy(sqstack *);


 
#endif


