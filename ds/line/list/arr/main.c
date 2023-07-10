#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

int main()
{
	sqlist *list = NULL;
	sqlist *list1 = NULL;
	datatype data[] = {12,23,34,45,56};
	datatype data1[] = {21,11,12,33,45};
	list = sqlist_create();  
//	sqlist_create1(&list);
	list1 = sqlist_create();
//	sqlist_create1(&list1);

	if(list == NULL)
	{
		fprintf(stderr, "sqlist_create() failed!\n");
		exit(1);
	}
	if(list1 == NULL)
	{
		fprintf(stderr,"sqlist_create() failed!\n");
		exit(1);
	}

	int err,err1;
	for(int i = 0; i < sizeof(data)/sizeof(*data); i++)
	{
		if((err = sqlist_insert(list,0,&data[i])) != 0)
		{
			if(err == -1)
				fprintf(stderr, "the arr is full.\n");
			else if(err == -2)
				fprintf(stderr, "the pos you want to insert is wrong.\n");
			else 
				fprintf(stderr, "error!\n");
			exit(1);
		}
	}

	sqlist_display(list);	

	for(int i = 0; i < sizeof(data1)/sizeof(*data1); i++)
	{
//		printf("%d\n", __LINE__);
		if((err1 = sqlist_insert(list1,0,&data1[i])) != 0)
		{
			if(err1 == -1)
				fprintf(stderr, "the arr is full.\n");
			else if(err1 == -2)
				fprintf(stderr, "the pos you want to insert is wrong.\n");
			else 
				fprintf(stderr, "error!\n");
			exit(1);
		}
	}
//	printf("%d\n", __LINE__);
		
	sqlist_display(list1);
#if 0	
	sqlist_delete(list,1);

	sqlist_display(list);
	
//	printf("%d\n",sqlist_find(list,data-1));
#endif
	sqlist_union(list,list1);

	sqlist_display(list);
	
//	sqlist_destroy(list);
	exit(0);
}












