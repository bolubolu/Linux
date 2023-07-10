#ifndef NOHEAD_H__
#define NOHEAD_H__

#define NAMESIZE    32

typedef struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
}score;

typedef struct node_st
{
	struct score_st data;
	struct node_st *next;
}node;


int list_insert(node **list, score *data);
void list_show(node *list);
int list_delete(node **list);
score *list_find(node *list,int id);
void list_destroy(node *list);


#endif


