#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main()
{
	queue *sq;
	datatype arr[] = {1,21,2,3};	
	sq = qu_create();
	if(sq == NULL)
		exit(1);
	
	for(int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
		qu_enqueue(sq,&arr[i]);	
	qu_travel(sq);

#if 0	
	datatype tmp = 100;
	int ret = qu_enqueue(sq,&tmp);
	if(ret == -1)
		printf("queue is full!\n");
	else
		qu_travel(sq);
#endif
	
	datatype tmp;
	qu_dequeue(sq,&tmp);
	printf("DEQUEUE:%d\n",tmp);
	qu_travel(sq);

	qu_destroy(sq);

	exit(0);
}









