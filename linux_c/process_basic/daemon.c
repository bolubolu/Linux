/****守护进程实例+系统日志****
**守护进程特点：脱离终端
**/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <errno.h>

#define  FNAME "/tmp/out"

static int daemonize(void)
{
	pid_t pid;
	int fd;

	pid = fork();
	if(pid < 0)      //error
	{
	//	perror("fork()");
		return -1;
	}
	
	if(pid > 0)      //parent process正常结束
		exit(0);
	
	fd = open("/dev/null",O_RDWR);  //读写形式打开终端设备
	if(fd < 0)
	{
	//	perror("open()");
		return -1;
	}

	dup2(fd,0);   //重定向到012
	dup2(fd,1);
	dup2(fd,2);
	if(fd > 2)
		close(fd);

	setsid();

	chdir("/");   //修改当前工作目录为根目录（防止目录为空）
	//umask(0);

	return 0;
}

int main()
{
	FILE *fp;

	openlog("mydaemon",LOG_PID,LOG_DAEMON);

	if(daemonize())
	{
		syslog(LOG_ERR,"daemonize() failed!");
		exit(1);
	}
	else
	{
		syslog(LOG_INFO,"daemonize() susccessed!");
	}

	fp = fopen(FNAME, "w");
	if(fp == NULL)
	{
	//	perror("fopen()");
		syslog(LOG_ERR,"fopen():%s",strerror(errno));
		exit(1);
	}

	syslog(LOG_INFO,"%s was opened.",FNAME);
	
	for(int i = 0; ; i++)
	{
		fprintf(fp,"%d\n",i);
		fflush(fp);
		syslog(LOG_DEBUG,"%d is printed.",i);
		sleep(1);
	}

	fclose(fp);
	closelog();

	exit(0);
}










