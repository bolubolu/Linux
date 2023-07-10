/*
**命令行分析实例:获取时间戳信息
**函数：  getopt(int argc,char *const argv[],
						const char *optstring)  
**选项:
*	-y: year 带参数 2、4
*	-m: month
*	-d: day
*	-H: hour  带参数 12、24
*	-M: minute
*	-S: second
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define   TIMESTRSIZE   1024
#define   FMTSTRSIZE    1024

int main(int argc, char **argv)
{
	FILE *fp = stdout;
	time_t stamp;
	struct tm *tm;
	char timestr[TIMESTRSIZE];
	int c;
	char fmtstr[FMTSTRSIZE];

	fmtstr[0] = '\0';	

	stamp = time(NULL);
	tm = localtime(&stamp);

	while(1)
	{
		c = getopt(argc,argv,"-H:MSy:md");   //:带参数的选项
		if(c < 0)
			break;
		switch(c)
		{
			case 1:
				if(fp == stdout)
				{
					fp = fopen(argv[optind-1],"w"); //覆盖写
					if(fp == NULL)
					{
						perror("fopen()");
						fp = stdout;
					}
				}
				break;
			case 'H':
				if(strcmp(optarg,"12") == 0)
					strncat(fmtstr,"%I(%P) ",FMTSTRSIZE);  //如果参数为12则12小时制
				else if(strcmp(optarg,"24") == 0)
					strncat(fmtstr,"%H ",FMTSTRSIZE);  //24小时制
				else
					fprintf(stderr,"Invalid argument of -H\n");
				break;
			case 'M':
				strncat(fmtstr,"%M ",FMTSTRSIZE);
				break;
			case 'S':
				strncat(fmtstr,"%S ",FMTSTRSIZE);
				break;
			case 'y':
				if(strcmp(optarg,"2") == 0)
					strncat(fmtstr,"%y ",FMTSTRSIZE);
				else if(strcmp(optarg,"4") == 0)
					strncat(fmtstr,"%Y ",FMTSTRSIZE);
				else 
					fprintf(stderr,"Invalid argument of -y\n");
				break;
			case 'm':
				strncat(fmtstr,"%m ",FMTSTRSIZE);
				break;
			case 'd':
				strncat(fmtstr,"%d ",FMTSTRSIZE);
				break;
			default:
				break;
		}
	}

	strncat(fmtstr,"\n",FMTSTRSIZE);
	strftime(timestr,TIMESTRSIZE,fmtstr,tm);  //按照fmtstr的格式把tm中的信息放到timestr
	fputs(timestr,fp);

	if(fp != NULL)
		fclose(fp);

	exit(0);
}








