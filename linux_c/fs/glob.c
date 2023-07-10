/**
用glob函数解析目录
int glob(const char *pattern, int flags,
		 int (*errfunc) (const char *epath, int errno),
		 glob_t *pglob);
void globfree(glob_t *pglob);
*/


#include <stdio.h>
#include <stdlib.h>
#include <glob.h>

#define PAT    "/etc/a*.conf"   //etc目录下所有.conf的内容
//#define PAT    "/etc/.*"    //etc目录下所有隐藏文件

#if 0
static int errfunc_(const char *errpath,int eerrno)
{
	puts(errpath);
	fprintf(stderr,"ERROR MSG:%s\n",stderror(eerror));
	return 0;
}
#endif

int main()
{
	glob_t globres;

	int err = glob(PAT,0,NULL,&globres);
	if(err)
	{
		printf("Error code = %d\n",err);
		exit(1);
	}	
	
	for(int i = 0; i < globres.gl_pathc; i++)
		puts(globres.gl_pathv[i]);

	globfree(&globres);

	exit(0);
}





