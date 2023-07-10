/*
功能：拷贝源文件内容到目标文件(用到fgets和fputs函数)
char *fgets(char *s,int size,FILE *stream);
int fputs(const char *s,FILE *stream);

命令行：./mycpy src_file dest_file
*/

#include <stdio.h>
#include <stdlib.h>

#define   BUFSIZE   1024

int main(int argc,char **argv)
{
	FILE *fps,*fpd;
	char buf[BUFSIZE];
	
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
	
	while(fgets(buf,BUFSIZE,fps) != NULL)
		fputs(buf,fpd);


	fclose(fpd);
	fclose(fps);




	exit(0);
}











