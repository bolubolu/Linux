/*
fflush函数
int fflush(FILE *stream)

*缓冲区的作用：大多数情况下是好事，合并系统调用
*
*行缓冲：换行时候刷新，满了的时候刷新，强制刷新（标准输出，因为是终端设备）
*
*全缓冲：满了的时候刷新，强制刷新（默认，只要不是终端设备）
*
*无缓冲：如stderr,需要立即输出的内容
*
改缓冲模式的函数：（绝大多数情况下用不到）
*   int setvbuf(FILE *stream,char *buf,int mode,size_t size)
mode选项：_IONBF unbuffered
		  _IOLBF line buffered
		  _IOFBF fully buffered
(光标停在函数上时，shift+k可直接跳至man手册)
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Before while()"); //没有换行符时需要刷新缓冲区
	fflush(stdout);

	while(1);
	
	printf("After while()");
	fflush(NULL);

	exit(0);
}









