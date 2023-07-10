#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"

int main()
{
	datatype arr[] = {0,12,23,34,45};
	sqstack *st;

	st = st_create();
	if(st == NULL)
		exit(1);
	
	for(int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
		st_push(st,&arr[i]);

	st_travel(st);

	datatype tmp = 1;
	int ret = st_push(st,&tmp);
	if(ret != 0)
		printf("st_puch failed.\n");
	else
		st_travel(st);

	datatype tmp2;
	while(st_pop(st,&tmp2) == 0)
	{
		printf("POP:%d\n",tmp2);
	}
	st_travel(st);
	
	st_destroy(st);

	exit(0);
}







