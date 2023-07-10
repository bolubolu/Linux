/*
功能：拷贝源文件内容到目标文件(用到fread和fwrite函数)
size_t fread(void *ptr,size_t size,size_t nmemb,FILE *stream);
size_t fwrite(const void *ptr,size_t size,size_t nmemb,FILE *stream);
返回值为读到的对象个数！
命令行：./mycpy src_file dest_file
*/

#include <stdio.h>
#include <stdlib.h>

#define   BUFSIZE   1024

int main(int argc,char **argv)
{
	FILE *fps,*fpd;
	char buf[BUFSIZE];
	int n;	

	if(argc < 3)
	{
		fprintf(stderr,"Usage:%s <src_file> <dest_file>\n",argv[0]);
		exit(1);
	}

	fps = fopen(argv[1],"r");
	if(fps == NULL)
	{
		perror("fopen()");
		exit(1);
	}

	fpd = fopen(argv[2],"w");
	if(fpd == NULL)
	{
		fclose(fps);
		perror("fopen()");
		exit(1);
	}
	
	while((n = fread(buf,1,BUFSIZE,fps)) > 0)
		fwrite(buf,1,n,fpd);   //fwrite的对象个数为fread的返回值

	fclose(fpd);
	fclose(fps);

	exit(0);
}











