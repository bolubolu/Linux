/*mydu:
实现du函数的功能:目录下每个文件/子文件的大小（k）
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <glob.h>
#include <string.h>

#define  PATHSIZE    1024

static int path_noloop(const char *path)
{
	char *pos;
	pos = strrchr(path,'/');  //strrchr函数找到字符串最右边的字符
	if(pos == NULL)
		exit(1);
	
	if(strcmp(pos+1,".") == 0 || strcmp(pos+1,"..") == 0)
		return 0;
	return 1;
}

static int64_t mydu(const char *path)
{
	static struct stat statres;
	static char nextpath[PATHSIZE];
	glob_t globres;
	int64_t sum;

	if(lstat(path,&statres) < 0)
	{
		perror("lstat()");
		exit(1);
	}
	
/*****非目录文件的情况*****/
	if(!S_ISDIR(statres.st_mode))
		return statres.st_blocks;   //返回stat的block值/2即为占多少k

/******目录文件的情况*******/
	strncpy(nextpath,path,PATHSIZE);
	strcat(nextpath,"/*");
	glob(nextpath,0,NULL,&globres);
	
	strncpy(nextpath,path,PATHSIZE);
	strcat(nextpath,"/.*");
	glob(nextpath,GLOB_APPEND,NULL,&globres);  //GLOB_APPEND,追加

	sum = statres.st_blocks;

	for(int i = 0; i < globres.gl_pathc; i++)
	{
		if(path_noloop(globres.gl_pathv[i])) //判断当前参数是否为.or .. 防止进入死循环导致栈溢出(隐藏文件有.和..)
			sum += mydu(globres.gl_pathv[i]);   //递归
	}

	return sum;

}

int main(int argc,char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage:...\n");
		exit(1);
	}

	printf("%ld\n",mydu(argv[1])/2);


	exit(0);
}





