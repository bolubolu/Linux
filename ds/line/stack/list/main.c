#include <stdio.h>
#include <stdlib.h>

#include "llist.h"
#include "stack.h"

#define   NAMESIZE  32

typedef struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
}score;

void print_s(void *record)
{
	score *r = record;
	printf("%d %s %d %d\n",r->id,r->name,r->math,r->chinese);
}

int main()
{
	STACK *st;
	score tmp;
	st = stack_create(sizeof(score));
	if(st == NULL)
		exit(1);

	for(int i = 0; i < 7; i++)
	{
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);
		tmp.math = rand()%100;
		tmp.chinese = rand()%100;

		if(stack_push(st,&tmp))
			exit(1);
		
	}
	while(1)
	{
		int ret = stack_pop(st,&tmp);
		if(ret == -1)
			break;
		print_s(&tmp);
	}

	stack_destroy(st);
	exit(0);
}






