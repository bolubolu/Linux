#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

#define  NAMESIZE   32

typedef struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
}score;

static void print_s(const void *record)
{
	const score *r = record;
	printf("%d %s %d %d\n", r->id, r->name, r->math, r->chinese);
}

static int id_cmp(const void *key, const void *record) 
{
	const int *k = key;
	const score *r = record;
	
	return (*k - r->id);
}

static int name_cmp(const void *key, const void *record)
{
	const char *k = key;
	const score *r = record;
	
	return strcmp(k,r->name);
}

int main()
{
	LLIST *handler;
	score tmp;

	handler = llist_create(sizeof(score));
	if(handler == NULL)
		exit(1);	

	for(int i = 0; i < 7; i++)
	{
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);
		tmp.math = rand()%100;
		tmp.chinese = rand()%100;
		
		int ret = llist_insert(handler, &tmp, LLIST_BACKWARD);
		if(ret)
			exit(1);
	}

	llist_travel(handler, print_s);
	
	printf("\n");

	int id = 3;
	char *del_name = "stu2";
/*
	score *data;
	data = llist_find(handler,&id,id_cmp);
	if(data == NULL)
		printf("Can not find!\n");
	else 
		print_s(data);
	printf("\n");
*/
//	int ret = llist_delete(handler,&id,id_cmp);
/*	int ret = llist_delete(handler,del_name,name_cmp);
	if(ret)
		printf("llist_delete failed!\n");
	llist_travel(handler,print_s);	
*/


	llist_destroy(handler);

	exit(0);
}











