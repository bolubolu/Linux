#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
	int count = 0;
	FILE *fp = NULL;

	while(1)
	{
		fp = fopen("tmp","r");
		if(fp == NULL)
		{
		//	fprintf(stderr,"fopen() failed!  errno = %d\n",errno);
			perror("fopen()");  //打印错误信息
		//	fprintf(stderr,"fopen():%s\n",strerror(errno)); //strerror函数需包含string.h
			break;
		}
		count++;
	}
	printf("count = %d\n",count);
	
	fclose(fp);

	exit(0);
}










