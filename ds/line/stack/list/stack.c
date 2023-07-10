#include <stdio.h>

#include "stack.h"


LLIST *stack_create(int initsize)
{
	return llist_create(initsize);
}

int stack_push(STACK *ptr,const void *data)
{
	llist_insert(ptr,data,LLIST_FORWARD);
}

static int always_match(const void *p1,const void *p2)
{
	return 0;
}

int stack_pop(STACK *ptr,void *data)
{
	return llist_fetch(ptr,(void *)0,always_match,data);	//假的接口,永远只删除第一个节点；
}

void stack_destroy(STACK *ptr)
{
	llist_destroy(ptr);
}











