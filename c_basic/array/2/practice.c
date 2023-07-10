#include <stdio.h>
#include <stdlib.h>

#define  M  2
#define  N  3

static void change(void)   //行列互换
{
	int a[M][N] = {1,2,3,4,5,6}, b[N][M];
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			printf("%d ", a[i][j]);
			b[j][i] = a[i][j];
		}
		printf("\n");
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
}

static void max(void)   //求最大值
{
	int a[M][N] = {12,2,32,3,24,13};
	int max = a[0][0], row = 0, colum = 0;
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(a[i][j] > max)
			{
				max = a[i][j];
				row = i;
				colum = j;
			}
		}
	}
	printf("max: a[%d][%d] = %d\n", row, colum, max);
}

static void sum(void)     //求各行各列的和
{
	int a[5][4] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			a[4][3] += a[i][j];
			a[4][j] += a[i][j];
			a[i][3] += a[i][j];
		}
	} 
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 4; j++)
			printf("%3d ", a[i][j]);
		printf("\n");
	}
}

#define  K  2
static void mul(void)   //矩阵乘积
{
	int a[M][N] = {1,2,3,4,5,6};
	int b[N][K] = {1,0,0,1,1,0};
	int c[M][K] = {0};

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < K; j++)
		{
			for(int k = 0; k < N; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < K; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
}

int main(void)
{
//	change();
//	max();
//	sum();
	mul();
	exit(0);
}











