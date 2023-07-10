#include <stdio.h>
#include <stdlib.h>

#define  M  2
#define  N  3

int main()
{
	int a[M][N] = {1,2,3,4,5,6};  //初始化时行号可省略，列不可省略
#if 0	
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &a[i][j]);
#endif

	printf("a = %p\n", a);
	printf("a+1 = %p\n", a+1); //行指针

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
			printf("%p---->%d ", &a[i][j],a[i][j]);
		printf("\n");
	}
	exit(0);	
}












