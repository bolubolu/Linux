#include <stdio.h>
#include <stdlib.h>
#include "nohead.h"

#define NAMESIZE    32


int list_insert(node **list, score *data)
{
	node *new;
	new = malloc(sizeof(*new));
	if(new == NULL)
		return -1;
	
	new->data = *data;
	new->next = *list;
	*list = new;
	return 0;
}

void list_show(node *list)
{
	node *cur;
	for(cur = list; cur != NULL; cur = cur->next)
	{
		printf("%d %s %d %d\n", cur->data.id,cur->data.name,cur->data.math,cur->data.chinese);
	}
}

int list_delete(node **list)
{
	node *cur;
	if(*list == NULL)
		return -1;
	cur = *list;
	*list = (*list)->next;
	free(cur);
	return 0;
}

score *list_find(node *list, int id)
{
	node *cur;
	for(cur = list; cur != NULL; cur = cur->next)
	{
		if(cur->data.id == id)	
			return &cur->data;
	}
	return NULL;
}

void list_destroy(node *list)
{
	node *cur;
	if(list == NULL)
		return ;
	for(cur = list; cur != NULL; cur = list->next)
	{
		list = cur->next;
		free(cur);
	}
}










