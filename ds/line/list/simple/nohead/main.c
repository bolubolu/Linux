#include <stdio.h>
#include <stdlib.h>
#include "nohead.h"


int main()
{
	node *list = NULL;
	score tmp;

	for(int i = 0; i < 7; i++)
	{
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);
		tmp.math = rand()%100;
		tmp.chinese = rand()%100;

		int ret = list_insert(&list,&tmp);
		if(ret != 0)
			exit(1);
	}	
	list_show(list);
	printf("\n");	
//	list_delete(&list);
//	list_show(list);
	int id = 2;
	score *ptr;
	ptr = list_find(list,id);
	if(ptr == NULL)
		printf("Can not find!\n");
	else 
		printf("%d %s %d %d\n",ptr->id,ptr->name,ptr->math,ptr->chinese);
	
	list_destroy(list);	

	exit(0);
}














