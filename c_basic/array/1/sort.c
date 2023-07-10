#include <stdio.h>
#include <stdlib.h>

#define   M   10

static void fabonacci(void)    //fabonacci数列
{
	int fib[M] = {1,1};
	for(int i = 2; i < sizeof(fib)/sizeof(fib[0]); i++)
		fib[i] = fib[i-1] + fib[i-2];
	for(int i = 0; i < sizeof(fib)/sizeof(fib[0]); i++)
		printf("%d ",fib[i]);
	printf("\n");

	int i = 0, j = sizeof(fib)/sizeof(fib[0]) - 1, temp;
	while(i<j)      //逆序存放
	{
		temp = fib[i];
		fib[i] = fib[j];
		fib[j] = temp;
		i++;
		j--;
	}
	for(i = 0; i < sizeof(fib)/sizeof(fib[0]); i++)
		printf("%d ", fib[i]);
	printf("\n");

	return;
}


static void sort1(void)     //冒泡排序
{
	int a[M] = {11,2,32,22,4,21,24,14,22,54};
	for(int i = 0; i < M; i++)
		printf("%d ", a[i]);
	printf("\n");

	for(int i = 0; i < (M-1); i++)
	{
		for(int j = 0; j < (M-1-i); j++)
		{
			if(a[j] > a[j+1])
			{
				int temp;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	for(int i = 0; i < M; i++)
		printf("%d ", a[i]);
	printf("\n");
}

static void sort2(void)     //选择法排序
{
	int i,j,k,temp;
	int a[M] = {2,11,43,32,21,3,6,17,32,13};
	for(i = 0; i < M; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	for(i = 0; i < M; i++)
	{
		k = i;
		for(j = i+1; j < M; j++)
		{
			if(a[k] > a[j])
				k = j;
		}
		if(k != i)
		{
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}

	for(i = 0; i < M; i++)
		printf("%d ", a[i]);
	printf("\n");
}

static void base_convert(void)     //进制转换
{
	int num, base;
	printf("please enter the converted number:");
	scanf("%d", &num);
	printf("please enter the base:");
	scanf("%d", &base);

	int a[128],i = 0;
	do
	{
		a[i] = num%base;
		num = num/base;
		i++;
	}while(num != 0);

	for(i--; i >= 0; i--)
	{
		if(a[i] > 9)
			printf("%c", a[i]-10+'A');
		else
			printf("%d", a[i]);
	}
	printf("\n");
}

static void primer(void)    //删除法求1000以内的质数
{
	char primer[1001] = {0};
	int i, j;
	for(i = 2; i < 1001; i++)
	{
		if(primer[i] == 0)
		{
			for(j = i*2; j < 1001; j += i)
				primer[j] = -1;
		} 
	}
	for(i = 2; i < 1001; i++)
		if(primer[i] == 0)
			printf("%d ", i);
	printf("\n");
}

int main()
{
//	fabonacci();
//	sort1();
//	sort2();
//	base_convert();
	primer();
	exit(0);
}














