#include <stdio.h>
#include <stdlib.h>

#define JOSE_NR   8

typedef struct node_st
{
	int data;
	struct node_st *next;
}node;

node *jose_create(int n)
{
	node *me, *newnode, *cur;
	int i = 1;
	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;
	me->data = i;
	me->next = me;
	i++;
	cur = me;
	for( ; i <= n; i++)
	{
		newnode = malloc(sizeof(*newnode));
		if(newnode == NULL)
			return NULL;
		newnode->data = i;
		cur->next = newnode;
		newnode->next = me;
		cur = newnode;
	}
	return me;
	
}

void jose_show(node *me)
{
	node *list;
	for(list = me; list->next != me; list = list->next)
		printf("%d ", list->data);
	printf("%d\n", list->data);	
}

void jose_kill(node **me, int n)
{
	node *cur = *me, *node;
	int i = 1;
	while(cur != cur->next)
	{
		while(i < n)
		{
			node = cur;
			cur = cur->next;
			i++;
		}
		node->next = cur->next;
		printf("%d ",cur->data);

		free(cur);
		cur = node->next;
		i = 1;
	}
	printf("\n");
	*me = cur;
}


int main()
{
	node *list;
	
	list = jose_create(JOSE_NR);
	if(list == NULL)
		exit(1);
	
	jose_show(list);
	jose_kill(&list,3);
	jose_show(list);		
	
	exit(0);
}















