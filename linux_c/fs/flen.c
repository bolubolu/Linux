/*
利用函数stat实现获取文件大小信息
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static off_t flen(const char *fname)  //返回值为off_t类型，与当前所用系统有关(或用Makefile文件可解决)
{
	struct stat statres;
	if(stat(fname,&statres) < 0)
	{
		perror("stat()");
		exit(1);
	}
	return statres.st_size;
}

int main(int argc,char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage:...\n");
		exit(1);
	}
	
	printf("%lld\n",(long long)flen(argv[1]));

	exit(0);
}







