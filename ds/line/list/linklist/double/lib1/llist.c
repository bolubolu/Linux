#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

struct llist_node_st    //变长结构体
{
	struct llist_node_st *prev;
	struct llist_node_st *next;
	char data[1];      //变长数组
};


int llist_insert(LLIST *,const void *data, int mode);
void *llist_find(LLIST *, const void *key, llist_cmp *);
int llist_delete(LLIST *, const void *key, llist_cmp *);
int llist_fetch(LLIST *, const void *key, llist_cmp *,void *data);
void llist_travel(LLIST *,llist_op *);

struct llist_head_st 
{
	int size;
	struct llist_node_st head;
/*	int (*insert)(struct llist_head_st *,const void *,int );
	void *(*find)(struct llist_head_st *,const void *,llist_cmp *);
	int (*delete)(struct llist_head_st *,const void *,llist_cmp *);
	int (*fetch)(struct llist_head_st *,const void *,llist_cmp *,void *);
	void (*travel)(struct llist_head_st *,llist_op *);
	void (*destroy)(struct llist_head_st *);
*/
};


LLIST *llist_create(int initsize)
{
	struct llist_head_st *new;
	new = malloc(sizeof(*new));
	if(new == NULL)
		return NULL;
	
	new->size = initsize;
	new->head.prev = &new->head;
	new->head.next = &new->head;
/*	new->insert = llist_insert;
	new->delete = llist_delete;
	new->find = llist_find;
	new->fetch = llist_fetch;
	new->travel = llist_travel;
	new->destroy = llist_destroy;
*/
	return new;		
}

int llist_insert(LLIST *p, const void *data, int mode)
{
	struct llist_node_st *newnode;
	struct llist_head_st *ptr = p;
	newnode = malloc(sizeof(*newnode) + ptr->size);
	if(newnode == NULL)
		return -1;

	memcpy(newnode->data, data, ptr->size);

	if(mode == LLIST_FORWARD)
	{
		newnode->prev = &ptr->head;
		newnode->next = ptr->head.next;
	}
	else if(mode == LLIST_BACKWARD)
	{
		newnode->next = &ptr->head;				
		newnode->prev = ptr->head.prev;
	}
	else   //error
	{
		return -3;
	}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;

	return 0;
}

static struct llist_node_st *find_(struct llist_head_st *ptr, const void *key, llist_cmp *cmp)
{
	struct llist_node_st *cur;
	for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
	{
		if(cmp(key,cur->data) == 0)
			break;	
	}
	return cur;
}

void *llist_find(LLIST *p, const void *key, llist_cmp *cmp)
{
	struct llist_node_st *node;
	struct llist_head_st *ptr = p;
	node = find_(ptr,key,cmp);
	if(node == &ptr->head)
		return NULL;
	return node->data;
}

int llist_delete(LLIST *p,const void *key,llist_cmp *cmp)
{
	struct llist_node_st *node;
	struct llist_head_st *ptr = p;
	node = find_(ptr,key,cmp);
	if(node == &ptr->head)
		return -1;

	node->prev->next = node->next;
	node->next->prev = node->prev;

	free(node);

	return 0;
}

int llist_fetch(LLIST *p, const void *key, llist_cmp *cmp, void *data)
{
	struct llist_node_st *node;
	struct llist_head_st *ptr = p;
	node = find_(ptr,key,cmp);
	if(node == &ptr->head)
		return -1;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	if(node->data != NULL)
		memcpy(data,node->data,ptr->size);

	free(node);
	return 0;
}

void llist_travel(LLIST *p, llist_op *op)
{
	struct llist_node_st *cur;
	struct llist_head_st *ptr = p;
	for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
		op(cur->data);  //回调函数，用户自己调用数据	
}

void llist_destroy(LLIST *p)
{
	struct llist_node_st *cur, *next;
	struct llist_head_st *ptr = p;
	for(cur = ptr->head.next; cur != &ptr->head; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	free(ptr);
}






