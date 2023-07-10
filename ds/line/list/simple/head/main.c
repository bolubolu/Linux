#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main()
{
	list *l, *l1;
	datatype arr[] = {12,23,34,45};
	datatype arr1[] = {21,45,11,32,52};
	datatype arr2[] = {23,45};	

	l = list_create();
	l1 = list_create();
	if(l == NULL)
		exit(1);
	if(l1 == NULL)
		exit(1);

	for(int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
	{
		if(list_insert_at(l,0,&arr[i]))
			exit(1);	
	}
	list_display(l);
	
	for(int i = 0; i < sizeof(arr1)/sizeof(*arr1); i++)
	{
		if(list_order_insert(l1,&arr1[i]))
			exit(1);
	}
//	list_display(l1);

//	list_delete(l,arr2);
//	list_display(l);

	int val;
	int err = list_delete_at(l,1,&val);
	if(err)
		exit(1);
	list_display(l);
	printf("delete:%d\n", val);
		

	list_destroy(l);
	list_destroy(l1);	

	exit(0);
}













