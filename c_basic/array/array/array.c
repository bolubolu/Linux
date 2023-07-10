#include <stdio.h>
#include <stdlib.h>

#define M      3

int main()
{
	int i;
	int a[M];
	printf("%ld\n", sizeof(a));
	printf("a=%p\n", a);

	for(i = 0; i < M; i++)
		scanf("%d\n", &a[i]);
	for(i = 0; i < M; i++)
		printf("%p --> %d\n", &a[i], a[i]);	

	exit(0);	
}














