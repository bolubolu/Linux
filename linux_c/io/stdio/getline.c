/*
功能：统计文件中每行的字符个数（包括换行符）
函数：	ssize_t getline(char **lineptr,size_t *n,FILE *stream)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv)
{
	FILE *fp;
	char *linebuf = NULL;
	size_t linesize = 0;  //初始化

	if(argc < 2)
	{
		fprintf(stderr,"Usage:%s <dest_file>\n",argv[0]);
		exit(1);
	}
	
	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}
	
	while(1)
	{
		if(getline(&linebuf,&linesize,fp) < 0)
			break;
		printf("%d\n",strlen(linebuf));
		printf("%d\n",linesize);
	}
	
	fclose(fp);

	exit(0);
}










