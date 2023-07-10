/*
功能：统计文件内字符个数
用到的函数：int fgetc() 
int fseek(FILE *stream,long offset,int whence);whence参数有SEEK_SET,SEEK_CUR,SEEK_END;
long ftell(FILE *stream);
void rewind(FILE *stream);将文件指针定位到开始处
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	FILE *fp;
	int count = 0;

	if(argc < 2)
	{
		fprintf(stderr,"Usage:./fgetc <dest_file>\n");
		exit(1);
	}
	
	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}

/*	while(fgetc(fp) != EOF)
	{
		count++;
	}

	printf("count = %d\n",count);
	fclose(fp);
*/

	fseek(fp,0,SEEK_END);  //文件指针指到末尾
	printf("%ld\n",ftell(fp));  //显示当前文件指针位置

	exit(0);
}







